// Room: /u/setup/yashilu.c



inherit ROOM;



void create()

{

        set("short", "岩石路");

        set("long", @LONG

这是一岩石路，由此去火山尚须四十多里路。但在此已可以看到四面山

上一缕黑烟冲天而起。岩石路皆由火山灰堆成，厉时久，地面十分坚硬。

LONG

        );

        set("exits", ([ /* sizeof() == 2 */

  "east" : __DIR__"shishan",

  "west" : __DIR__"haoshanyanshilu",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

