#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "禅房");
        set("long",
"这里是静空师太的禅房。简单而整齐的摆放着一张床和一张小桌，桌上\n"
"放着几本佛经，静空师太正端坐在床上，一边敲着木鱼一边念经。\n"
        );

        set("exits", ([
		"east" : __DIR__"xilang2",
               ])); 
        set("objects", ([
          __DIR__"npc/jingkong" : 1,
             ]));
        set("coor/x",-70);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",30);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}