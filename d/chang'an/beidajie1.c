// Room: /chang'an/beidajie1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "北大街");
        set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北面是玄武内门，南边
显得很繁忙。东边是一茶馆，一面上书“茶”的招幡在风中轻轻地摇曳着，
一股股茶香扑面而来。西面是一家骆驼行。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"chaguan",
                "south" : __DIR__"beidajie2",
                "west"  : __DIR__"luotuohang",
                "north" : __DIR__"northgate1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}