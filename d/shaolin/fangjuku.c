// Room: /d/shaolin/fangjuku.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "���߿�");
	set("long", @LONG
����һ��ܴ�ķ��䣬��ǽ����ط���һ��������ӣ�����
�����ų����ţ�¶������ĸ��ַ��ߣ�Ʒ��֮�࣬������ƽ������
һλ����ɮ������ͷ����һ������Ļ��ߡ��������Ҳû��ע�⡣
LONG
	);

	set("exits", ([
		"north" : __DIR__"yaopinku",
		"south" : __DIR__"wuqiku",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang" : 1,
	]));
	set("coor/x",30);
	set("coor/y",350);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}


