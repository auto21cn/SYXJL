// Room: /u/setup/bingshan2.c



inherit ROOM;



void create()

{

        set("short", "冰山");

        set("long", @LONG

这是一块很大浮动冰山，是由万年玄冰组成。由于前面的冰山受到火山

之热，不断的熔化，而产生吸力，把许多浮冰不断的吸进，所以冰山是不断

的靠近火山。



LONG

        );

        set("exits", ([ /* sizeof() == 1 */

  "out" : __DIR__"bingshan1",

]));

        set("no_clean_up", 0);

         set("objects", ([ /* sizeof() == 1 */

		__DIR__"npc/bingxiong":1,
]));

        setup();

}







void init()

{

        

        add_action("do_jump", "jump");

        add_action("do_jump", "yue");

}



int do_jump(string arg)

{

        object me = this_player();



        if ( arg == "fubing") {

                if (me->query_skill("dodge", 1) >= 60) {

                        message("vision", me->name() + "吸了口气，纵身向对面跃去。\n",

                                environment(me), ({me}) );

                        write("你吸了口气，纵身向对面跃去。\n");

                        me->move(__DIR__"xiaobing");

                        message("vision", "只见人影一闪，" + me->name() +  "纵身跃了过来。\n",

                                environment(me), ({me}) );

                        

                        return 1;

                }

                else {

                        message("vision", me->name() + "纵身向对面跃去，只听“扑通”一声，" + me->name() + "摔入冰中，狼狈的爬了回来。\n",

                                environment(me), ({me}) );

                        write("你纵身向对面跃去，只听“扑通”一声，你摔入冰中，狼狈的爬了回来。\n");

                        me->receive_damage("qi",30);

                        return 1;

                }

        }

        return 0;



}

