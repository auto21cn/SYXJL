// Room: /city/zuixianlou2.c
// YZC 1995/12/04 

inherit ROOM;
inherit F_DEALER;

void create()
{
	set("name", "����¥");
	set("short", "����¥��¥");
	set("long", @LONG
	����������������ѧʿ������������ʫ��������������Ҳ������߳Ժȱ�
�����ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������ֻ�����Ŀ�������
������һ�غ�ˮ���̲������������ǳ�ɽ���룬��������Կ�������ȫ���İ�¹��
Ժ�ĺ�ͥ��ǽ�Ϲ��ż۸�����(paizi)��
LONG
	);

	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));

	set("objects", ([
		__DIR__"npc/xian" : 1,
		__DIR__"npc/guidao" : 1,
                /*CLASS_D("gaibang") + "/kongkong" : 1,*/
	]));

	set("exits", ([
		"down" : __DIR__"zuixianlou",
	]));

	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}