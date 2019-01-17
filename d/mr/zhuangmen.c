#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short","庄门");
        set("long",
"你转过一丛茂密的花丛, 猛然间, 只见一座红檐绿瓦, 小巧玲珑的庄院矗\n"
"利在灿澜的花丛中。庄门大匾上赫然写着「"HIY"曼陀罗山庄"NOR"」五个金光闪闪的大字。\n"
);
       set("outdoors","mr");
       set("exits",([
           "west" : __DIR__"hc",
	"east" : __DIR__"qianyuan",
	"south" : __DIR__"xiaojing1-0",
           "north" : __DIR__"hc1",
]));
        set("coor/x",80);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}
