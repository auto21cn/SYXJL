#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short","С��");
set ("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�ǰ�����С���ˣ�һλ��������Ůվ����ǰ���㱻������ò��
����������������������������������ϻ�����������ò����Ů��
long);
         set("outdoors","mr");
       set("objects",([
             __DIR__"npc/abi" : 1,
]));
       set("exits",([
             "east" : __DIR__"xiaoting",
             "southwest" : __DIR__"xiaojing3",
]));
         set("coor/x",160);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
         replace_program(ROOM);
}