#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long",@long
���Ų�����, ֻ�������г�ɽ�軨����ޱ�������, �������ǣţ��,
���º�, Ǿޱ֮��Ҳ��һ�䶼�ޡ��߳���ʮ�ɺ�, ֻ��ɽ��Ʒ�ֽ���, ż
��Ҳ��һ�������㲻��, ȴҲ���ֲ����䷨���������ǰԺ��
long);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"qianyuan",
             "west" : __DIR__"hc1",
]));
         set("coor/x",90);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}