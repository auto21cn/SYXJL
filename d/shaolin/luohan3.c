// Room: /d/shaolin/luohan3.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�޺�������");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬��
�ڿյ����ر��������������İڷ��ż��������ҷ��ڵĻƲ�
���ţ���λ�뷢���׵���ɮ�������������Ŀ�붨�������Ǳ���
ʮ���޺��������еĵط������پ����书�����ڴ������
LONG
	);

	set("exits", ([
		"south" : __DIR__"luohan2",
		"north" : __DIR__"luohan4",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/cheng-ming" : 1,
	]));
	set("coor/x",20);
	set("coor/y",290);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}


