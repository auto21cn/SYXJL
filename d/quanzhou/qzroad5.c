// Room: /d/quanzhou/qzroad5.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
�����ڶ��ϵ�һɽ������ɽ�ϡ�����Ӷ��洵�������ż��ֺ��⡣
�ϱ߾��������ĺ���Ȫ���ˡ�
LONG
	);

	set("exits", ([
                "north" : __DIR__"qzroad4",
                "south" : __DIR__"beimen",
	]));

        set("objects", ([
		"/d/wudang/npc/yetu" : 2 ]));

	set("outdoors", "quanzhou");
	set("coor/x",70);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
