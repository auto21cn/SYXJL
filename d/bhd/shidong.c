// Room: /u/setup/shidong.c



inherit ROOM;



void create()

{

        set("short", "石洞");

        set("long", @LONG

此处为一小山洞，中间透入一线天光，宛如天窗一般。这里陶碗、土灶

、石床、灶具等一应俱全。



LONG

        );

        set("exits", ([ /* sizeof() == 1 */

  "out" : __DIR__"xiaoshishan",

]));

        set("no_clean_up", 0);



       set("objects", ([

           "/d/mj/npc/shiwang": 1,
    ]));

        setup();

        replace_program(ROOM);

}

