#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long",@long
����һ��С����, ��Ȼ����, ���ǹ���ư��, ���ν���, ������ȫ����̨
�϶��������ʹϹ��߲�, �����Ϻ, �������಻��, ��ʮ�ָɾ����롣
long);
         set("objects", ([
             __DIR__"npc/obj/lingbai-xiaren" : 1,
             __DIR__"npc/obj/dongsun-tang" : 1,
]));
         set("valid_startroom", 1);
         set("exits",([
             "south" : __DIR__"xiaoting",
]));
         set("coor/x",170);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
         
}