// Room: /u/setup/xiaoshishan.c



inherit ROOM;



void create()

{

        set("short", "小石山");

        set("long", @LONG

这是一座小山石，比之东面的石山为小山石周围到处是奇花异树，异

树丛中传来阵阵的奇香，皆由不知名之花朵传出。山脚下露出一个小石洞

(dong)，东边有一石山

LONG

        );

        set("exits", ([ /* sizeof() == 3 */

  "west" : __DIR__"shishan",

  "enter" : __DIR__"shidong",

]));

        set("no_clean_up", 0);

    set("objects", ([

		__DIR__"npc/longwang": 1,


]));

        setup();

        replace_program(ROOM);

}

