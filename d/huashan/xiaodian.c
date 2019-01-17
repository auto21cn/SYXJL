// Room: /huashan/jiulou1.c

inherit ROOM;

void create()
{
	set("short", "山顶小店");
	set("long", @LONG
这里是华山山顶的一间小店，卖些简单的饮食，专门赚那些游客的钱。
LONG
	);

	set("exits", ([
		"east" : __DIR__"square",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}

