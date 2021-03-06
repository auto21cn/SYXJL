// 修改 by think

#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "比武大擂台");
	set ("long", @LONG
这里就是比武场的大比武台，一丈来高的比武台上铺着猩红色的地毯
比武台两边的兵器架上摆放着两排十八班兵器作为装饰。比武台后面
是一个贵宾席，只有巫师可以坐在哪里。
LONG);
	set("info_sends",1);
	set("biwutai",1);
	set("exits", ([
		"north"   : __DIR__"caipan",
		"down"   : __DIR__"kantai2",
	]));
	setup();
}

void init()
{
	add_action ("do_fight","fight");
	add_action ("do_fight","kill");
	add_action ("do_fight","hit");
	add_action ("do_work","quit");
	add_action ("do_work","halt");
}

int do_fight(string arg)
{
	object me=this_player();
	object *inv=all_inventory(environment(me));
	object ob;
	object who;
	int i;

	if(!arg) { 
		write("你要同谁比武？\n");
		return 1;
	}
	ob=present(arg, environment(me));
	if(!ob) {
		write("这里没有这个人！\n");
		return 1;
	}
	if(ob==me) {
		write("你要同自己比武？？？\n");
		return 1;
	}
	if(!interactive(ob)) {
		write("他现在无法同你比武！\n");
		return 1;
	}
	if(!userp(me) || !userp(ob)) {
		write("他现在无法同你比武！\n");
		return 1;
	}

	for(i=0; i<sizeof(inv); i++) {
		who=inv[i];
		if(who->is_fighting()) {
			write("台上"+who->query("name")+"等正在比武，请稍侯！\n");
			return 1;
		}
	}

	message("channel:chat",HIW"【比武大擂台】"+
		me->query("family/family_name")+"的"+me->query("name")+"与"+
		ob->query("family/family_name")+"的"+ob->query("name")+
		"在比武台上较量高低！\n\n"NOR,users());

	me->set("biwu_fighter",1);
	ob->set("biwu_fighter",1);

	me->kill_ob(ob);
	ob->kill_ob(me);
	return 1;
}

void info_sends(string str)
{
	tell_room(__DIR__"kantai1", str);
	tell_room(__DIR__"kantai2", str);
	tell_room(__DIR__"kantai3", str);
}

int no_die(object me)
{
	object ob = me->query_temp("last_opponent");
	object obj, where;
	string id=ob->query("id");
	string id1=me->query("id");

	me->delete_temp("last_opponent");
	ob->delete_temp("last_opponent");
	me->delete_temp("last_damage_from");
	ob->delete_temp("last_damage_from");
	me->remove_all_killer();
	ob->remove_all_killer();

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", me->query("max_qi"));
	me->set("eff_jingli", me->query("max_jingli"));
	me->set("jingli", me->query("max_jingli"));
	me->set("eff_douzhi", me->query("max_douzhi"));
	me->set("douzhi", me->query("max_douzhi"));
	me->set("shenzhi", me->query("max_shenzhi"));
	me->set("neili", me->query("max_neili"));

	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("eff_jingli", ob->query("max_jingli"));
	ob->set("jingli", ob->query("max_jingli"));
	ob->set("eff_douzhi", ob->query("max_douzhi"));
	ob->set("douzhi", ob->query("max_douzhi"));
	ob->set("shenzhi", ob->query("max_shenzhi"));
	ob->set("neili", ob->query("max_neili"));

	message("channel:chat",HIW"【比武大擂台】"+
		ob->query("family/family_name")+"的"+ob->query("name")+"在比武台击败"+
		me->query("family/family_name")+"的"+me->query("name")+"！\n\n"NOR,users());

	message_vision (CYN"$N重重地摔在地上！\n"NOR,me);
	message_vision (CYN"\n$N慢慢从地上爬将起来，被壮汉扶着走下比武台。\n"NOR,me);
	me->move(__DIR__"kantai1");
	message_vision (CYN"$N被壮汉扶着慢慢走了过来。\n"NOR,me);
	message_vision (CYN"几名壮汉欢呼着簇拥着$N走下比武台。\n"NOR,ob);
	ob->move(__DIR__"kantai3");
	message_vision (CYN"$N被几名壮汉簇拥着走了过来。\n"NOR,ob);

	me->delete("biwu_fighter");
	ob->delete("biwu_fighter");

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	obj=present("gongping zi", where);
	if(obj->query("fangshi")!="个人赛") {
		if(obj->query("start/juesai"))
			obj->jieshu_biwu(id, id1);
			obj->keep_biwu(id);
	}
	return 1;
}

int do_work()
{
	write("这里不能使用这个指令！\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( !wizardp(me) && dir=="north" ) {
		return notify_fail("你不是巫师，不能到贵宾席。\n");
	}

	if ( !wizardp(me) && dir=="down" ) {
		if( me->query("biwu_fighter") )
			return notify_fail("你马上要比武了，不要到处乱跑。\n");
	}

	me->delete_temp("last_opponent");
	me->delete_temp("last_damage_from");
	me->remove_all_killer();

	return ::valid_leave(me, dir);
}

