#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","厢房");
         set ("long",@long
这是一间厢房, 里面摆设简单, 只有一张床, 一张书桌和一把椅子。
long);
         set("no_fight", 1);
         set("sleep_room", 1);
         set("exits",([
             "west" :__DIR__"c13-2",
             "east" : __DIR__"yunjinlou",
             "north" : __DIR__"c13",
]));
         set("coor/x",110);
	set("coor/y",-40);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}

