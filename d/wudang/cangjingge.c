// cangjingge.c �ؾ���
// by Xiang
// 05/30/96 Marz

inherit ROOM;

string* books = ({
	"laozi1",
	"daodejing-i",
	"laozi2",
	"daodejing-i",
	"laozi8",
	"daodejing-i",
	"laozi13",
	"laozi1",
	"laozi16",
	"daodejing-i",
	"laozi18"
});

void create()
{
	set("short", "�ؾ���");
	set("long", @LONG
	�����ǲؾ��󣬿�ǽ��һ����ܣ������˵��̵ĵ伮��������һ������
�εĴ����ӣ�����Ҳ�������顣һ����ͯ���������鼮��
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"xilang",
	]));

	set("objects", ([
		CLASS_D("wudang") + "/daotong" : 1,
		__DIR__"obj/"+books[random(sizeof(books))] : 1,
		__DIR__"obj/"+books[random(sizeof(books))] : 1
	]));

	set("coor/x",-60);
	set("coor/y",100);
	set("coor/z",190);
	set("coor/x",-60);
	set("coor/y",100);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}