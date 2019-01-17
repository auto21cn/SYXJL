// Room: /d/chang'an/jiangjunfu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "将军府");
	set("long", 
"一座气派非凡的大院跃入你的视线，只见红墙碧瓦，门楼高挑。左右
各自放着一只汉白玉雕的大狮子，大门的匾额上书三个大字:"HIY"
                        将 军 府
"NOR"
    一名偏将和几名军士，正威风八面地站在大门口，根本不屑于向你望上一
眼。\n"
 );
        set("outdoors", "chang'an");
	set("exits", ([
		"south" : __DIR__"xidajie3",
	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/junshi" : 2,
	]));
	setup();
	replace_program(ROOM);
}

