// waishi.c ���� 

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ĵ�������������ŷ�����ʮ���Ʋ����ţ�������һ��
��ľ��̳����̳�Ϸŵ�ǽ�Ϲ���һ����ʿ�񡣶����߸�����һ��
������ۼ�Ĵ�ƿ���ϲ�̴����֦���������ƣ��뵷ҷ�������
һƬ���֮���������������ƽ̶����½���˵���ĵط���
LONG
        );
        

        set("exits", ([
                "west" : __DIR__"zhongtang",
                "north" : __DIR__"neiyuan",
        ]));

        set("objects", ([
                __DIR__"npc/mayu" : 1, 
   ]));

 
        set("coor/x",-100);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",270);
	set("coor/z",190);
	setup();
        replace_program(ROOM);
}
