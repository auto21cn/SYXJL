
// Room: /huoshan/guanmulin2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��ľ��");
        set("long", @LONG
����·����ȴ����ְ㣬��һЩ�����м䳤���˹�ľ�ԣ���
����һ����С����һ��С�ľ���Щ��������������·����˵���
���ߵý���

LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "east"  : __DIR__"guanmulin1",
                "south" : __DIR__"guanmulin3",
                "west"  : __DIR__"guanmulin2",
                "north" : __DIR__"guanmulin2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}