// Room: /d/wuguan/shibanlu3.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
������һ��ʯ��·�ϣ������ȥ���Ǻ�Ժ�ˣ�����������������
���洫�����󷹲˵���������������ݵķ����������ȥ����ݴ�����
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "south" : __DIR__"changlang6",
                "north" : __DIR__"shibanlu4",
                "west" : __DIR__"fanting",                               
                "east" : __DIR__"shibanlu2",                
        ]));
        setup();
        replace_program(ROOM);
}