// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
	这里有四条走廊通向不同的房间。
LONG
	);

	set("exits", ([
		"east" : "/inherit/room/eproom",
		"west" : "/inherit/room/wproom",
		"south" : "/inherit/room/sproom",
		"north" : "/inherit/room/nproom",
		"down" : __DIR__"duchang",
	]));

	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

