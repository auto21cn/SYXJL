//Room /d/honghua/shanxia.c
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","峡谷");
	set("long",@LONG
这里是一道峡谷，两旁石壁峨然笔立，有如用刀削成，抬头望天
，只觉天色又蓝又亮，宛如潜在海底仰望一般。峡内岩石全系深黑，
乌光发亮。道路弯来弯去，异常曲折。
LONG
	);
	
	set("outdoor", "honghua");	

	set("exits", ([
		"south" : __DIR__"caoyuan",
		"north" : __DIR__"xinxin-xia",
	]));

	set("coor/x",-130);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",70);
	set("coor/z",0);
	setup();
}
