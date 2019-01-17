// Room: /city/yaopu1.c
// YBL 2000/07/27 

inherit ROOM;

void create()
{
    set("short", "治疗室");
	set("long", @LONG
这是扬州城药铺的治疗室，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小
抽屉里散发出来的。神医平一指坐在茶几旁，独自喝着茶，看也不看你一眼。
一名小伙计站在柜台后招呼着顾客。
LONG
	);


	set("objects", ([
                __DIR__"npc/ping2" : 1,
	]));

	set("exits", ([
        "south" : __DIR__"yaopu",
	]));

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

