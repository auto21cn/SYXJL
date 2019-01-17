// Room: /city/dongmen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
	���Ƕ����ţ��������Ϸ����š����š�����������֣���ǽ�����ż���
�ٸ���ʾ(gaoshi)���ٱ��Ǿ����ע���Ź������ˣ������С��Ϊ�һ����ֱ
����ʯ���������������졣�����ǽ��⣬��Լ�ɼ�һƬһ���޼ʵ����֣���
��Ī�⡣�����ǳ��������һƬïʢ�������֡����������ݵĹ���ӹ�����
LONG
	);
        set("outdoors", "city");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : "/d/taishan/yidao",
		"north" : __DIR__"ml1",
		"west" : __DIR__"dongdajie2",
                   "south" : "/d/city/jiagong",
	]));

	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));

	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}
