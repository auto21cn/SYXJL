// by mayue

inherit ROOM;

void create()
{
        set("short", "风云亭");
        set("long", @LONG
这里是一个花园中的小亭子，雕梁画栋，古色古香。亭中有一老一少正在
专心致志的下棋。
LONG
        );
//     set("outdoors", "honghua");

        set("exits", ([
                "south" : __DIR__"huating1",
                "west" : __DIR__"huayuan3",
//              "north" : __DIR__"huating3",
        ]));
        set("objects", ([
//                "/d/npc/guojing": 1,
        ]));
        setup();
//      replace_program(ROOM);
}

