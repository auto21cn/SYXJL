// Room: /d/chang'an/westgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "玉祥内门");
	set("long", 
"这里是长安城的西城门的内城门，只见城门上方是三个大字。"HIW"

                      玉    祥    门
\n"NOR
"    长安是西北经济中心，丝绸之路的起点，由于朝廷禁止偷运走私蚕籽
之类的物品出关，所以在这里已经盘查得十分严格了。两边是上城头的石
阶，向东进入城区。\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
		"southup" : __DIR__"wallw2",
		"northup" : __DIR__"wallw1",
		"east"    : __DIR__"xidajie1",
		"west"    : __DIR__"westgate2",
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

