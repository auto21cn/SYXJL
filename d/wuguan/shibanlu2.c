// Room: /d/wuguan/shibanlu2.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG
你走在一条石板路上，北面和南面都是习武堂，不少人在这里进进出出的，
东面是武馆大厅。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "south" : __DIR__"xiwutang",
                "north" : __DIR__"xiwutang1",                
                "east" : __DIR__"wuguandating",                
                "west" : __DIR__"shibanlu3",                                
        ]));
        setup();
        replace_program(ROOM);
}
