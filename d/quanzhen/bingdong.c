// bingdong.c 冰洞 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "冰洞");
	set("long", @LONG
这里就是冰洞。洞内都是坚硬的冰块。虽是盛夏，如果走进冰洞，
亦可见坚冰，寒气逼人,随时有被冻僵的可能。如非武功高强之人，根
本无法在洞中久留。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"south" : __DIR__"fengdong",
			]));
	setup();
	replace_program(ROOM);
}


