// Room: /d/gaibang/dlandao4.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
        set("short", "暗道");
        set("long", @LONG
这是丐帮极其秘密的地下通道，乃用丐帮几辈人之心血掘成。
你隐隐看见不远处有一点光亮，好象是一个出口，并且远处隐隐
约约传来一些市井的声音...� 
LONG
        );

        set("exits", ([
                        "southdown" : __DIR__"dlandao3",
                        "out" : "/d/dali/dahejieeast",
        ]));

        setup();
        replace_program(ROOM);
}
