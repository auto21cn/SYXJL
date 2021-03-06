inherit ROOM;
int do_study(string arg);

void create()
{
        set("short", "闭关室");
        set("long", @LONG
这里是任我行在地下练功的密室。密室虽小，却也五脏俱全，当时任我
行把日月大权交给东方不败后，就是在这苦练吸星大法。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "up" : __DIR__"xiaosiwu",
]));

        set("objects",([
                __DIR__"obj/book4" : 1,
        ]));

        set("item_desc", ([
                "石壁" : "这是一整块用内力雕成的石壁，上面刻了些奇怪的图形。\n",
        ]));

        setup();
}

void init()
{
        add_action("do_study", "study");
}

int do_study(string arg)
{
        object me;

        me = this_player();

        if ( !arg || ( arg != "石壁" ) )
                return notify_fail("什么？\n");

        if ( (int)me->query_skill("literate", 1) < 60)
                return notify_fail("你的后天学识太少，无法领悟图形上的高深的刀法。\n");

        
        if ( (int)me->query_skill("blade",1) < 50 )
                {
                write("你的刀法火候太浅，无法领悟图形上的高深的刀法。\n");
                return 1;
                }

        me->add("jing", (-1)*random(40));

        message_vision("$N正专心研读石桌上的古怪图形。\n", me);

        switch( random(1) )
        {
            case 0:
                if ( (int)me->query_skill("blade", 1) < 100)
                {
                        me->improve_skill("blade", me->query("int"));
                        write("你对着石壁上的图形琢磨了一回儿，似乎对刀法有点心得。\n");
                        me->set_temp("stone_learned",1);
                }
        }

        if ( !me->query_temp("stone_learned") )
        {
                                write("你对着石壁上的图形琢磨了一回儿，觉得没什么意思，可能对于你来说太浅了。\n");
        }
        return 1;
}
