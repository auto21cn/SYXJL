// lingguandian.c ��ٵ�

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
������ȫ��̵���ٵ�߽���ӭ���һ�񽫣�������Ŀ����
�׳ֱޣ��������ݣ����������պ������ĵ��̻���������١�ת����
�񱳺󣬲����Թ�����ŭĿԲ�������������¡�����λԪ˧�������ԡ�
LONG
	);
        
	set("exits", ([
		"northeast" : __DIR__"donglang2",
		"south" : __DIR__"donglang1",
       ]));

	set("objects", ([
"/d/quanzhen/npc/sunbuer" : 1]));

	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}


