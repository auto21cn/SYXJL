// Room: /d/quanzhou/jiaxing.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "���˳�");
	set("long", @LONG
�����ǽ������Ǽ��ˡ��Ƕ��Ƿ羰�续���Ϻ����Ǳ�������������¥��
����ȫ������֮һ���𴦻��ͽ����߹־���������ԼѰ������֮�󡣲�֪
��ʲôԭ���������Ǩ�������ˡ�
LONG
	);

	set("exits", ([
                "west" : __DIR__"qzroad2",
                "east" : __DIR__"nanhu",
		"south" : __DIR__"jxnanmen",
	]));

	set("outdoors", "quanzhou");
	set("coor/x",70);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
