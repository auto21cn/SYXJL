// Room: /d/wuguan/wuguandayuan.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "武馆大院");
        set("long", @LONG
这是个大院子，东西两边都是练武场，不少人在这里习武强身，这里
很吵，乱烘烘的，你看见不时有扛着东西的，挑着水的匆匆而过，北面上
了台阶就是武馆大厅。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"wuguangate",
                "north" : __DIR__"wuguandayuan1",   
                "east"  : __DIR__"changlang1",                             
                "west"  : __DIR__"changlang5",                                             
                 "southwest"  : __DIR__"liaotian",             
        ]));
        set("objects", ([
                __DIR__"npc/brave" : 1,
        ]));        
        setup();
        replace_program(ROOM);
}
