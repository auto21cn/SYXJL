// Room: /d/mingjiao/tomen1.c
// Date: XXL 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��ʯ��");
    set("long", @LONG
ʯ���������ƺ���ÿ�����Щ�����µ�ɽ�����������
���˾����Ϊһˬ��Զ����������ˮ�������н�Զ��ɽ����
�����˺��ܵ����ܣ��������ҡ߮��
LONG
    );

    set("exits", ([
        "west" : __DIR__"shanmen",
        "east" : __DIR__"tomen2",
    ]));

    set("outdoors", "mingjiao");

    set("objects",([
        "/kungfu/class/mingjiao/weiyixiao":1,
    ]));

    set("coor/x",-120);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}
