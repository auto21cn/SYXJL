// Room: /d/shaolin/luohan9.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�޺��þŲ�");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬��
�ڿյ����ر��������������İڷ��ż��������ҷ��ڵĻƲ�
���ţ���λ�뷢���׵���ɮ�������������Ŀ�붨�������Ǳ���
ʮ���޺��������еĵط������پ����书�����ڴ������
LONG
	);

	set("exits", ([
		"south" : __DIR__"luohan8",
		"northup" : __DIR__"zoulang8",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/cheng-he" : 1,
	]));
	set("coor/x",20);
	set("coor/y",310);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}


