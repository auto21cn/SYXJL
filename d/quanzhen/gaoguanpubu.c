// gaoguanpubu.c 高冠瀑布 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "高冠瀑布");
	set("long", @LONG
迎面一瀑布落差超过二十米，急流飞溅，直下深潭，响声如雷。唐岑参
有诗云：“岸口悬飞瀑，半空白皑皑。喷壁四时雨，傍村终日雷。”这是对
眼前高冠瀑布真实而形象的写照。往上是车厢潭。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"northup" : __DIR__"chexiangtan",
		"westdown" : __DIR__"guanyintai",
        ]));
	set("coor/x",-70);
	set("coor/y",160);
	set("coor/z",120);
	set("coor/x",-70);
	set("coor/y",160);
	set("coor/z",120);
	set("coor/x",-70);
	set("coor/y",160);
	set("coor/z",120);
	set("coor/x",-70);
	set("coor/y",160);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}



