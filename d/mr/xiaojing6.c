#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ������������������濴ȥ��һ
Ƭ�����֣�����Ͷ�����С�������졣
long);
set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaojing7",
             "north" : __DIR__"liulin1",
             "west" : __DIR__"xiaojing5",
             "south" : __DIR__"xiaojing8",
]));
	set("objects",([
		__DIR__"npc/yahuan" : 2,
]));
        set("coor/x",120);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}