#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long",@long
��С����������̤����С���İ��ߣ�ֻ������ȫ�ǻ������硣�����ţ�
ʮ��ѧʿ��ʮ��̫�������ɹ������糾��������������Ĳ軨���������
��Χ�����Ѿ����ݻ����У��������ϸ�ı���򣬺����ܹ��߳�ȥ��
long);
         set("outdoors","mr");
/*       set("objects",([
             __DIR__"npc/youcao" : 1,
]));
*/       set("exits",([
             "south" : __DIR__"hc",
             "east" : __DIR__"hc1",
             "west" : __DIR__"hc2",
]));
         set("coor/x",70);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}