// Room: /city2/qianzhuang.c

inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ
�����е���Ʊ�����ǳ��ã�ͨ��ȫ�����������ߵ�������κ�һ����
ׯ�ֵ궼���������ȡ��ǽ�Ϲ���һ������(paizi)��
LONG
	);

	set("item_desc", ([
		"paizi" : "\n��ׯ����Ϣ�����ٰٷ�֮һ��\n",
	]));
	set("exits", ([
		"west" : __DIR__"wangfu1",
	]));

	set("objects", ([
                __DIR__"npc/qianlaob" : 1
	]));

	set("coor/x",-30);
	set("coor/y",160);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
