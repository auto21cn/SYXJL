inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "玄武外门");
        set("long", 
"这里是长安城的北城门，只见城门上方是三个大字。"HIB"

                   玄    武    门
\n"NOR
"    长安是西北经济中心，丝绸之路的起点，由于朝廷禁止偷运走私蚕籽
之类的物品出关，所以在这里已经开始盘查得十分严格了。两边是很大的
草地。\n"
 );
        set("outdoors", "chang'an");

        set("exits", ([
                "south"  : __DIR__"northgate1",
                "north"  : __DIR__"caodi3",
                "east"   : __DIR__"caodi1",
                "west"   : __DIR__"caodi2",
        ]));
/*
        set("objects", ([
                __DIR__"npc/pi"   : 1,
                __DIR__"npc/bing" : 2,
        ]));
*/
        setup();
        replace_program(ROOM);
}

