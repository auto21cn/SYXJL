#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������飬�����ǻ��ʷ��������ǳ��ȵ���
�졣
long);
         set("exits", ([
             "east" : __DIR__"hffang",
             "north" : __DIR__"c13-2",
]));
         set("coor/x",100);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}
