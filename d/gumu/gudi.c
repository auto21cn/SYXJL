// gudi.c



#include <ansi.h>

#include <room.h>



inherit ROOM;



void init()

{

        add_action("do_pa", "pa");

        add_action("do_tiao", "tiao");

        

}



void create()

{

    set("short", HIG"谷底"NOR);

    set("long", @long

你来到谷底，却发现这里原来是一处碧水清潭(tan）。周围岸边有几棵大

树。树上排列着数十个蜂巢(fengchao)。而在巢畔飞来飞去的都是一些体形硕

大，颜色灰白的异种玉蜂。

long);

    set("item_desc", ([

        "fengchao": HIY"你走近巢边观察，只见蜂巢之旁糊有泥土，实是人工所为。\n"NOR,

        "tan": HIC"你举目向潭中望去，但见水潭里面蓝森森，青郁郁，寒气逼人，似乎结满玄冰，

一眼望不到底。\n"NOR,

    ]));



    set("objects", ([

                __DIR__"npc/bee" : 1,

        ]));



    set("outdoors", "古墓");



    setup();

}



int do_pa(string arg)

{

        object me;



        me=this_player();

        if (me->is_busy() || me->is_fighting())

                return notify_fail("你正忙着哪！\n");

        if ( !arg || arg != "yabi")

                return notify_fail("你要往哪爬？\n");

        message_vision(YEL"$N颤颤噤噤地爬了上去。\n"NOR, me);

        me->move(__DIR__"yabi7");

        me->add_temp("tengacc",1);

        me->start_busy(1);

        tell_room(environment(me), me->name() + "从上面爬了下来。\n", ({ me }));

        return 1;

}



int do_tiao(string arg)

{

        object me;



        me=this_player();

        if (me->is_busy() || me->is_fighting())

                return notify_fail("你正忙着哪！\n");

        if ( !arg || arg != "tan")

                return notify_fail("你要往哪跳？\n");

        message_vision(HIY"$N扑通一声，涌身跳入了水潭。\n"NOR, me);

        me->move(__DIR__"guditan1");

        tell_room(environment(me), me->name() + "从岸边跳了下来。\n", ({ me }));

        message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);

        return 1;

}



