// Room: /u/setup/huoshan.c



inherit ROOM;



void create()

{

        set("short", "火山");

        set("long", @LONG

到这里来后你什么都看不见了，，，，，只是有被火烧身的感觉。！！！！

LONG

        );

        set("exits", ([ /* sizeof() == 1 */

  "east" : __DIR__"huoshanjiaoxia",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

