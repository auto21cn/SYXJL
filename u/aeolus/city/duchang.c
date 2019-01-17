// Room: /city/duchang.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "扬州赌场");
	set("long", @LONG
	这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。
北边和南边是赌「骰子」的房间，西边是赌「牌九」的房间。楼上是
打拱猪的地方。墙上有匾(bian)一块。
LONG
	);

	set("item_desc", ([
		"bian" : HIG"愿赌服输\n"NOR,
	]));
	set("exits", ([
// "north" : __DIR__"dice1",
//                    "enter" : __DIR__"dice2",
                  "up" : __DIR__"duchang2",
		  "east" : __DIR__"nandajie1",
	]));
	set("objects", ([
                "/quest/quest/wuqing": 1,
	]));

	set("no_fight",1);
        set("no_sleep_room", 1);
        set("no_steal", 1);
        set("no_beg", 1);
	set("no_yun",1);
	
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        if ((dir == "north" || dir == "south") && this_player()->query("age")<18)
                return notify_fail("小毛孩子往这儿瞎凑合什么?!\n");
        return ::valid_leave(me, dir);
}

