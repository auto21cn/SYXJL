//bridge.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long",
             "����һ��С���ţ�������ɽ���ϵı�ѩ�ڻ��γ�һ���峺��СϪ\n"
         "�������»�����������ʱ����Ƥ��С��Ծ��ˮ�棬�������»���һ��\n"
         "����ɫ�Ļ��ߡ�\n"
        );
        set("outdoors", "baituo");
        set("exits", ([
                "northwest" : __DIR__"guangchang",
                "east" : __DIR__"xijie",
        ]));
        set("objects",([
                __DIR__"npc/cungu" : 1,
        ]));
        set("coor/x",-120);
	set("coor/y",-70);
	set("coor/z",-30);
	set("coor/x",-120);
	set("coor/y",-70);
	set("coor/z",-30);
	set("coor/x",-120);
	set("coor/y",-70);
	set("coor/z",-30);
	set("coor/x",-120);
	set("coor/y",-70);
	set("coor/z",-30);
	setup();
        replace_program(ROOM);
}