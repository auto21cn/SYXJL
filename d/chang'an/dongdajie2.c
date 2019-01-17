
// Room: /chang'an/dongdajie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "东大街");
        set("long", @LONG
这儿是很大的十字街口，北边是东内大街，南面是一条街道，听说巡
捕房和监狱就在那里面，东面直通向长安城的青龙门，向西可到达中央广
场。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"dongdajie1",
                "south" : __DIR__"shangdelu3",
                "west"  : __DIR__"dongdajie3",
                "north" : __DIR__"shangdelu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}