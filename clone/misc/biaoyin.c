// biaoyin.c

#include <ansi.h>
inherit ITEM;

int robberC;
int flagR;
int rob;
int robs;
int potential_lv(int exp);

void create()
{
	set_name( "镖银", ({ "biao yin", "biao","yin" }) );
	set_weight(2000+random(3000));
	set("no_put", 1);			// 这样东西不能放入容量
	set("identifier", random(10000));	// 全球镖银识别码 呵呵

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "箱");
		set("long", "一箱镖局托付给你的镖银。\n");
	}

	flagR=0;
	robberC=random(11);
	robberC=(robberC<7)?7:robberC;
	rob=0;
	robs=random(2);
	robs=(robs<1)?1:robs;
}

void init()
{
	add_action("do_give", "give");
	add_action("do_go", "go");

	if( query("target") ) {
		remove_call_out("set_target");
		call_out("set_target", 4, query("target"));
		delete("target");               // add 4 seconds' delay, can't be so fast
	}
}

void set_target(string target)
{
	set("target", target);
}

int do_go(string arg)
{
	object robber, env;
	mapping exit;

	env = environment(this_player());
	exit = env->query("exits");
	if(!env) return notify_fail("你哪里也去不了。\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) )
		return notify_fail("这个方向没有出路。\n");

	if ( objectp(robber=present("mask robber", env)) ) {
		if ( robber->is_killing(this_player()->query("id")) && living(robber) && random(10) < 7 ) {
			switch(random(2)) {
				case 0:
					message_vision(HIR"\n$n一把拦在$N面前。想走？先放下镖银！\n"NOR, this_player(), robber);
				break;
				case 1:
					message_vision(HIR"\n$n团团把$N围住，不把镖银留下，休想离开！\n"NOR, this_player(), robber);
				break;
				case 2:
					message_vision(HIR"\n$n喝道：“钱也要，命也要！你休想走人！”\n"NOR, this_player(), robber);
				break;
			}
			return 1;
		}
	}

	flagR++;

	if( flagR == robberC && environment(this_player())->query("outdoors") && rob <= robs ) {
		if(!this_player()->is_busy())
			this_player()->start_busy(1);
		remove_call_out("attract_robber");
		call_out("attract_robber", 0);
		flagR = 0;
		robberC=random(11);
		robberC=(robberC<7)?7:robberC;
		return 1;
	}
//	write(flagR+"\n");
//	write(robberC+"\n");
	return 0;
}

int do_give(string arg)
{
        int i, bonus;
        string obj, target;
        object me, ob, home;

	if(!arg || arg==" ")
		return 0;
	if( sscanf(arg,"%s to %s", obj, target)!=2 )
		if(sscanf(arg,"%s %s", target, obj) !=2 )
			return 0;

	if( !id(obj) ) return 0;

	me = this_player();

	if(!ob = present(target,environment(me)) ) {
		tell_object(me,"你想要把镖银交给谁？\n");
		return 1;
	}

	if(!ob->id(query("target")) || userp(ob)) {
		tell_object(me, "你不能把这样东西给这个人。\n");
		return 1;
        }

	if(!living(ob) ) {
		tell_object(me,ob->query("name")+"已经无法收下这样东西了。\n");
		return 1;
	}

	if( !home = find_object(ob->query("startroom")) )
		home = load_object(ob->query("startroom"));
	if(environment(ob)!=home){
		message_vision(CYN+"$N说道：我现在正忙着呢！等我回去再说吧！"+NOR, ob);
		return 1;
	}

	message_vision("$N拿出一箱镖银交给了" + ob->query("name") + "。\n", me);
	if((time()-me->query( "yunbiao/start" ))>me->query( "yunbiao/time" ) ) {
		message_vision(CYN+"$N很生气地对$n说道：这么点儿事都办不好，真没用！\n"+NOR, ob, me);
		tell_object(me, "你没有及时把镖银送到" + ob->query("name") + "的手中，你的任务失败了！\n");
/*		i = 100 + random(time()-me->query( "yunbiao/start" )-me->query( "yunbiao/time" ))/5;
		i = i/2;
		i = (i>100)?100:i;
		me->add("combat_exp", -i);
		tell_object(me, sprintf(WHT"你被扣除%s点战斗经验，\n"NOR, chinese_number(i)) );
		bonus = (int)me->query("potential");
		bonus = bonus - i/5 - 1;
		bonus = (bonus<(int)me->query("learned_points"))?(int)me->query("learned_points"):bonus;
		me->set("potential", bonus );
		tell_object(me, sprintf(WHT"%s点潜能。\n"NOR, chinese_number(i/5+1)) );*/
		me->delete("yunbiao/start");
		me->delete("yunbiao/time");
		me->set("yunbiao/halt", time());
	}
        else {
                message_vision(CYN+"$N对$n笑道：很好！这是一成的红利，你拿去吧！\n"+NOR, ob, me);
                tell_object(me, "你成功地将镖银送到了" + ob->query("name") + "的手中。\n");
                i = 100 + random(me->query( "yunbiao/time" )-time()+me->query( "yunbiao/start" ))/5;
                tell_object(me, sprintf(WHT"你获得了%s点战斗经验，\n"NOR, chinese_number(i)) );
                me->add("combat_exp", i);
                bonus = (int)me->query("potential");
                bonus = bonus - (int)me->query("learned_points");
                bonus = bonus + i/5 + 1;
                if ( bonus > potential_lv((int)me->query("combat_exp")) )
                bonus = potential_lv((int)me->query("combat_exp"));
                bonus += (int)me->query("learned_points");
                me->set("potential", bonus );
                tell_object(me, sprintf(WHT"%s点潜能。\n"NOR, chinese_number(i/5+1)) );
/*		ob=new(SILVER_OB);
                if (!ob->move(me))
			ob->move(environment(me));
		ob->add_amount(random(10)+10);*/
		me->delete("yunbiao/start");
		me->delete("yunbiao/time");
        }

        me->receive_damage("qi", 20+random(20));
        me->receive_damage("jing", 20+random(10));

        destruct(this_object());

        return 1;
}

// 设置强盗
void attract_robber()
{
	int robbers, i;
        object ob, robber, room;

        if (!userp(ob = environment(this_object())) ) return;

	robbers = random(2);
	robbers = (robbers<1)?1:robbers;
	room = environment(ob);

	if(!objectp(present("mask robber", environment(this_player())))) {
		for(i=0; i<robbers; i++) {
			robber = new("/d/npc/robber");
			robber->set("target", query("identifier"));
			robber->set("speaker", (i==0)?1:0);
			robber->move(room);
		}
		rob++;
		message_vision("一群$n从路旁冲了出来，将$N团团围住。\n", ob, robber);
	}
}

void owner_is_killed() { destruct(this_object()); }

int potential_lv(int exp)
{
        int grade;

        grade = 100 + exp / 500;;
        return grade;
}
