// yuanchendian.c 元辰殿

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "元辰殿");
	set("long", @LONG
这里是元辰殿，正中供奉着北极大帝，他被道教尊为四御之一，协助玉
皇执掌天经地纬，日月星辰和四时气候。殿四周两侧按天干地支六十甲子供
本命神，每个人都可依据自己的生辰八字找到自己的本命神。
LONG
	);
       
	set("exits", ([
//		"northeast" : __DIR__"xilang5",
		"south" : __DIR__"xilang4",
       ]));

	set("objects", ([
"/d/quanzhen/npc/wangchuyi" : 1]));

	set("coor/x",-120);
	set("coor/y",300);
	set("coor/z",190);
	set("coor/x",-120);
	set("coor/y",300);
	set("coor/z",190);
	set("coor/x",-120);
	set("coor/y",300);
	set("coor/z",190);
	set("coor/x",-120);
	set("coor/y",300);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}



