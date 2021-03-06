// wangding.c 神木王鼎

#include <ansi.h>

inherit ITEM;

int do_put(string);
int do_suck(string);
//int come_duchong(object, object);
int ok_suck(object, object);

void create()
{
	set_name(YEL"神木王鼎"NOR, ({"shenmu wangding", "wangding", "ding"}));
        set("long","这是一尊六寸来高大小的木鼎，深黄颜色，雕琢甚是精细，木质坚润\n"
	"似玉，木理之中隐隐约约的泛出红丝。\n");
       	set("unit", "尊");
	set("weight", 130);
        set("no_drop", "这样东西不能离开你。\n");

}

void init()
{
        add_action("do_put","put");
        add_action("do_suck", "suck");
}

int do_put(string arg)
{
        object ob, env, me = this_player();
        string what, where;

        if( !arg || sscanf(arg, "%s in %s", what, where) != 2 )
                return notify_fail("你要将什么东西放进哪里？\n");

        if( !(where == "shenmu wangding" || where == "wangding" || where == "ding") )
                return 0;

        if( what == "all" ) {
                write("还是一样一样来吧。\n");
                return 1;
        }

        if( !objectp(ob = present(what, me)) )
                return notify_fail("你身上没有这样东西。\n");

        if( ob->query("id") != "xiang" )
                return notify_fail("神木王鼎只能用来插香抓毒虫。\n");

        if( ob->query("name") != "点燃的香" )
                return notify_fail("你还是先把香点燃吧。\n");

        message_vision("$N将一支点燃的香插进神木王鼎中。\n", me);
        destruct(ob);

        env = environment(this_object());

        if( (int)env->query("duchong") > 0 ) {
		remove_call_out("come_duchong");
//		call_out("come_duchong", 10 + random(20), env, this_object());
        }

        return 1;
}

int do_suck(string arg)
{
        object me = this_player();

        int lvl, lvl2;

        if( !arg || ( arg != "blood" ) )
                return 0;

        if( query("amount") < 1 )
                return notify_fail("你要吸什么？\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("这种地方不能练功。\n");

        if( me->is_fighting() )
                return notify_fail("战斗中不能练功。\n");

        if( me->query_skill_mapped("poison") != "xingxiu-dugong" )
                return notify_fail("你不运星宿毒功吸收毒质，怎么练功？！\n");

        if( me->query_skill_mapped("force") != "beiming-zhenqi" )
                return notify_fail("你不运北冥真气抵御毒素，当心反被毒死！\n");

        if( me->query("qi") < 70 || me->query("jing") < 70 )
                return notify_fail("你身体状况不佳，先歇息一会儿吧。\n");

        if( me->query("neili") < 50 )
                return notify_fail("你内力不够。\n");

        add("amount", -1);
        me->receive_damage("qi", 20 + random(20));
        me->receive_damage("jing", 20 + random(20));
        me->add("neili", -10 - random(10));

        message_vision("$N伸掌将血液接住，盘膝运功，将血液都吸入掌内。\n", me);

   // need bingcan after 150 level
        if( lvl < 150 )
                me->improve_skill("huagong-dafa", 5 + random(me->query("con")));

        me->improve_skill("chousui-zhang", 1 + random(me->query("int")));

  // i set the punishment in /adm/daemons/natured.c 
  // give punishment if query("apply/xx_du") < 2 * (lvl - 60)
        
        if( me->query("apply/xx_du") < me->query("con") * lvl )
                me->add("apply/xx_du", 5 + random(10));

        return 1;
}
/*
int come_duchong(object env, object ob)
{
        object obj;
  
        if( environment(ob) != env )
                return 1;

        if( env->query("duchong") < 1 )
                return 1;

        switch( random(3) ) {
        case 0:
                obj = new("/d/xingxiu/npc/scorpion");
                break;
        case 1:
                obj = new("/d/xingxiu/npc/wugong");
                break;
        case 2:
                obj = new("/d/xingxiu/npc/spider");
                break;
        }

        message_vision(HIR"忽听得地上嗦嗦声响，却是一只$N爬了过来。那$N闻到鼎中散出的香气，径身游向木鼎，从鼎下的孔中钻进去，便不再出来。\n"NOR, ob, env);
        env->add("duchong", -1);
        obj->move(ob);
        call_out("ok_suck", 5 + random(10), ob, obj);

        if( (int)env->query("duchong") < 1 )
                call_out("refresh_duchong_room", 60 + random(60), env);

        return 1;
}

*/
void refresh_duchong_room(object env)
{
        env->set("duchong", env->query("max_duchong"));
}

int ok_suck(object ob, object obj)
{
        message_vision("过了一会儿，" + ob->query("name") + "里的" + obj->query("name") + "化成了一滩脓血。\n", ob);
        set("long", "一只雕琢而成的暗黄色小木鼎, 木理之间隐隐泛出红丝。鼎侧有五个铜钱大的圆孔，，只见里面有一滩血，一滴滴从孔中滴下来。\n");
        set("amount", 100 + random(100));
        destruct(ob);

        return 1;
}