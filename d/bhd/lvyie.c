// Room: /u/setup/lvyie.c



inherit ROOM;



void create()

{

        set("short", "绿野");

        set("long", @LONG

这里是岛屿的东部。极目的是一片看不到尽头的大绿野，是活火山经几

千万年的火山灰堆积而成，沿途所见，除低丘高树之外，尽是青草奇花。草

丛之中，偶尔惊起一些叫不出名目的大鸟小兽，看来也皆无害于人，你走到

此处，疑为仙山。转过一片大树林，西北角上是一座石山。

LONG

        );

        set("exits", ([ /* sizeof() == 2 */

  "south" : __DIR__"lvyie1",

  "northwest" : __DIR__"shishan",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

