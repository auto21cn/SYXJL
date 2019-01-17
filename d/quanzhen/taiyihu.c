// taiyihu.c 太乙湖

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "太乙湖");
	set("long", @LONG
这里就是太乙湖。太乙湖为山间湖泊，传为唐天宝年间地震造成，四周
高峰环列，池面碧波荡漾，山光水影，风景十分优美。如泛舟湖上，可
穿行于峰颠之间，尽情地享受着大自然的情趣，其乐无穷。往西是风洞，
往北是翠华庙。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"southdown" : __DIR__"shijie2",
		"west" : __DIR__"fengdong",
             "north": __DIR__"cuihuamiao" 
	]));
	setup();
	replace_program(ROOM);
}

