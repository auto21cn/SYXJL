
// Room: /chang'an/luotuohang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "骆驼行");
        set("long", @LONG
由于长安是丝绸之路的起点，往来的商人驮运货物全要靠这些骆驼了，
谁敢说不依赖这种动物能穿越大沙漠的话，那人一定是个疯子。这里的生
意做得很活，你想去波斯的话，这里的老板会介绍合适的商队把你捎过去。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"beidajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}