// Room: /d/shaolin/nanyang.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "������");
	set("long", @LONG
������ǵ�����������Ĺʾӡ������ǲ�����Ϊ�س�Ҫ�壬
���������Ŀ����ر�࣬����Ҳ�����ȫ����¥����ջ�����꣬
�����Ӷ��ǡ������˿����٣�����������ɫ�ҴҵĽ������ˡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"hanshui2",
		"north" : __DIR__"yidao3",
		"east" : __DIR__"kedian1",
		"west" : __DIR__"jiulou1",
	]));

	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
	]));

        set("outdoors", "����");
	set("coor/x",0);
	set("coor/y",120);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}


