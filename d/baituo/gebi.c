//gebi

inherit ROOM;

void create()
{
	set("short", "戈壁");
	set("long",
	     "这里是临近沙漠的戈壁滩，荒无人烟。东边是一望无际的大沙漠，\n"
	 "西北方可以看见一座小镇。\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"east" : "/d/xingxiu/shamo4",
		"northwest" : __DIR__"dongjie",
	]));
	set("coor/x",-90);
	set("coor/y",-80);
	set("coor/z",-30);
	set("coor/x",-90);
	set("coor/y",-80);
	set("coor/z",-30);
	set("coor/x",-90);
	set("coor/y",-80);
	set("coor/z",-30);
	set("coor/x",-90);
	set("coor/y",-80);
	set("coor/z",-30);
	setup();
	replace_program(ROOM);
}
