// fu-xiaoyuan ����СԺ
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "����СԺ");
        set("long", @LONG
���ǽ��ź��һ��СԺ�䡣������һ�����ţ�������һ����
���ź���ͨ�������������Ǵ��ţ�������Ǵ����ˡ��������
��ͷɥ����վ��СԺ�У���������Ϊ�ɲ����ⱻץ���ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"fu-damen",
                "south" : __DIR__"fu-datang",
                "west" : __DIR__"fu-cemen",
                "east" : __DIR__"fu-huating",
        ]));
        set("objects", ([
                __DIR__"npc/poorman" : 2,
        ]));

        set("coor/x",-100);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",110);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
