#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ������������������濴ȥ��һ
Ƭ�����֣������Ǻ�Ժ��������һ��С����
long);
         set("outdoors","mr");
         set("exits",([
             "north" : __DIR__"xiaojing6",
             "south" : __DIR__"houyuan",
]));
        set("coor/x",120);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}