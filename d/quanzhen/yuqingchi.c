// yuqingchi.c 玉清池

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "玉清池");
	set("long", @LONG
这里是玉清池，四周群山环抱，湖面澄波如镜、碧水似蓝。湖四周
层峦叠翠、繁草密林，一派朴素娴静、清纯秀丽的风光。往上就是全真
教。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"northup" : __DIR__"shijie3",
		"eastup" : __DIR__"sheshentai",
       ]));
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",130);
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",130);
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",130);
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",130);
	setup();
	replace_program(ROOM);
}



