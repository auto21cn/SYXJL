// Room: /u/setup/shishan.c



inherit ROOM;



void create()

{

        set("short", "石山");

        set("long", @LONG

这是一座山石，山石周围到处是奇花异树，异树丛中传来阵阵的奇香，

皆由不知名之花朵传出。山脚下露出一个石洞(dong)，西面是通住火山之路

东边半里处有一小石山，北边是一片片深不见底的大丛林

LONG

        );

        set("no_clean_up", 0);

        set("exits", ([ /* sizeof() == 6 */

  "east" : __DIR__"xiaoshishan.c",

  "southeast" : __DIR__"lvyie",

  "north" : __DIR__"shulin",

  "west" : __DIR__"yashilu",

  "enter" : __DIR__"xiongdong.c",

]));

        setup();

        replace_program(ROOM);

}

