// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "һ����");
	set("long", @LONG
����ڷ���ɽ��Լ�����������һ���š�������һ����׷�����
�˴˷�������˵�̩ɽ���̵���������һ������ͤ��ʿ����Ǽ���
��ӣ����������ﻻ�����ķ�װ���ż�����ɽ����һ��������
������������ʮ���������������������֣���̩ɽ���˵�������
��ֹ֮̾��������һ�Ʒ�����д�����ӵ��ٴ������ഫΪ�����ӹ�
̩ɽ�ࡹ�Ĺ��·����ĵط���
LONG
	);

	set("exits", ([
		"northup" : __DIR__"doumo",
		"southdown" : __DIR__"baihe",
	]));

	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));

        set("outdoors", "̩ɽ");
	set("coor/x",60);
	set("coor/y",50);
	set("coor/z",20);
	set("coor/x",60);
	set("coor/y",50);
	set("coor/z",20);
	set("coor/x",60);
	set("coor/y",50);
	set("coor/z",20);
	set("coor/x",60);
	set("coor/y",50);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
