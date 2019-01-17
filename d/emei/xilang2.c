#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西廊");
        set("long",
"这里是千佛庵西边的过道，过道上很安静。不时能听到从走廊两边传\n"
"来的木鱼声和颂经声。东边是静真师太的禅房，西边是静空师太的禅房。\n"
        );

        set("exits", ([
		"north" : __DIR__"xilang",
                "south" : __DIR__"xilang1",
		"east" : __DIR__"chfang4",
		"west" : __DIR__"chfang3",
               ]));
        set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}