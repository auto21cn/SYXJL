inherit ROOM;

void create()
{
	set("short", "�ذ��Ŷ����");
	set("long", @LONG
����һ����������Ĵ��������ͨ���ذ��š�����ͨ����������
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"di_an1",
		"west" : __DIR__"di_anmen",
	]));
	set("objects", ([
		"/d/city2/npc/flowerg" :  2,
	]));

	set("coor/x",-80);
	set("coor/y",180);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

