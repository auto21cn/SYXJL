// jinliange.c 金莲阁 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "金莲阁");
	set("long", @LONG
这里是金莲阁，
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"eastdown" : __DIR__"laoyuyan",
		"northup" : __DIR__"baoquan",
        ]));
	setup();
	replace_program(ROOM);
}



