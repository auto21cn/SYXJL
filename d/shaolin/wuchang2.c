// Room: /d/shaolin/wuchang2.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м�
�����Ų��ٲݰС�ʮ����ɮ��������ϰ���ա�������һ����ɮ����
LONG
	);

	set("exits", ([
		"south" : __DIR__"zoulang3",
		"west" : __DIR__"wuchang",
		"east" : __DIR__"luohan5",
		"north" : __DIR__"zoulang7",
	]));

	set("objects",([
                __DIR__"npc/mu-ren2" : 2 ]));

	set("outdoors", "shaolin");
	set("coor/x",10);
	set("coor/y",310);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}


