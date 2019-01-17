// sgroad2.c 山冈小路

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条上冈的小路上，二边都是茂密的树林，冈顶的庙宇依稀可见。
LONG
	);
	set("outdoors", "quanzhen");

	set("exits", ([
		"southdown" : __DIR__"sgroad1",
		"northup" : __DIR__"gangding",
	]));

  
	setup();
}

