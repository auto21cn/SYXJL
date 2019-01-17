inherit ROOM;
create()
{
	set("short", "斋厅");
	set("long", @LONG
这里便是天龙寺寺僧用斋的地方。斋厅极大，足可容纳上
千人同时进餐。从东到西一排排摆满了长长的餐桌和长凳，几位
小和尚正来回忙碌着布置素斋。桌上摆了几盘素菜。
LONG
	);

	set("exits", ([
		"west" : __DIR__"chufang",
		"east" : __DIR__"fanting1",
	]));

	set("objects",([
		__DIR__"npc/shaofan-seng" : 1,
		__DIR__"obj/qingshui-hulu" : 1,
		__DIR__"obj/sucai":3,		
	]));
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (( present("qingshui-hulu", me)||present("sucai", me))
	&&objectp(present("shaofan-seng", environment(me))) )
	{
		if ((dir == "east") || (dir == "west"))
		{
			return notify_fail("阿弥陀佛,你把食物那走让其他僧人吃什么 !\n");
		}
	}
	return ::valid_leave(me, dir);
}


