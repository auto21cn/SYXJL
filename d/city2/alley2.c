inherit ROOM;

void create()
{
	set("short", "杨柳胡同");
	set("long", @LONG
街道上一个人也看不到。你突然有点害怕起来。东南边有一家棺材店。
西南边是一条黑漆漆的小巷，你不知道要不要继续向里走。“还是往北回
去吧，免得。。。。。。”，心底里一个声音不住地对你说。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
                "southeast" : __DIR__"guancaidian",
		"north" : __DIR__"alley1",
		"southwest" : __DIR__"alley3",
	]));

	set("coor/x",-70);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

