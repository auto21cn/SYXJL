// donglang1.c ��������
// by Xiang
// Modified by Marz 03/27/96

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
	������һ�������ϣ������м������ң��������������֡������Ǵ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"donglang2",
		"west" : __DIR__"sanqingdian",
	]));
	
	set("objects", ([
                     __DIR__"npc/xi" :1 ]));
		
	set("coor/x",-40);
	set("coor/y",90);
	set("coor/z",180);
	set("coor/x",-40);
	set("coor/y",90);
	set("coor/z",180);
	set("coor/x",-40);
	set("coor/y",90);
	set("coor/z",180);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "�䵱��") && dir == "east" &&
		objectp(present("zhang songxi", environment(me))))
	   return notify_fail("����Ϫ�ȵ����㲻���䵱���ӣ��������ڡ�\n");
		
        return ::valid_leave(me, dir);
}