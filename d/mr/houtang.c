#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","后堂");
         set("long", @long
这里摆着一张小床，床头是一张女人用的梳妆台，上面放着许多胭脂粉
盒。靠窗是一张长长的红木书桌，只要抬眼望去，太湖的万顷碧波，尽
收眼底。
long);
         set("exits",([
             "north" : __DIR__"xiaoting",
]));
        set("coor/x",170);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
