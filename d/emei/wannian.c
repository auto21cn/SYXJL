#include <room.h>
inherit ROOM;
void create()
{
        set("short", "万年庵");
        set("long", @LONG
这里就是峨嵋山著名的万年庵。在茂密的翠竹丛中露出万年庵的一角，
确给人一种“柳暗花明又一村”的感觉。万年庵虽然不大，也很简陋，但很
整洁，是参道者静修的好地方。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"westdown" : __DIR__"qingyin",
	"east" : __DIR__"xiangfang",
]));
        set("no_clean_up", 0);
        create_door("east", "木门", "west", DOOR_CLOSED);
        set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",100);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",100);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",100);
	setup();
        replace_program(ROOM);
}
