#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小道");
        set("long",
"这里是西侧门外的小道，连接西侧门和两个练功的草坪。不时有小女\n"
"孩和小尼姑来来往往。\n"
        );

        set("exits", ([
		"northup" : __DIR__"taizi",
		"east" : __DIR__"xicemen",
		"southwest" : __DIR__"leidong",
               ]));
        set("coor/x",-80);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",40);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}