// shangou.c 山沟

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "山沟");
	set("long", @LONG
你的眼前是一条又长又深的山沟，
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"" : __DIR__"",
		"" : __DIR__"",
             "": __DIR__"" 
	]));
	setup();
	replace_program(ROOM);
}



