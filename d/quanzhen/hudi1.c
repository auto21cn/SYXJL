// hudi1.c 湖底

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "湖底");
	set("long", @LONG
 这里是小湖水下 ，四周十分的昏暗，依希有几道天光从头顶的潭水中投射
下来，此时也不那么瑰丽了，昏沉沉的犹如天边的晚霞。脚下漆黑一片也不知有
些什么。四周的水流也没有那么平静了，似乎在向一个方向流动着。你不由心中
一动：不会有暗流吧！！
LONG
	);
        
	set("exits", ([
		"down" : __DIR__"hudi2",
        ]));
	setup();
	replace_program(ROOM);
}



