// Room: chanfang.c

inherit ROOM;

void create()
{
        set("short", "产房");
        set("long", @LONG
这是一间专门为孕妇准备的产房。
LONG
        );
        set("no_fight",1);
        set("no_sleep_room",1);
        set("no_steal",1);
        set("no_beg",1);
        set("no_study",1);
        set("no_yun",1);

        set("exits", ([
                "down" : "/d/city/yaopu",
        ]));

        setup();
        replace_program(ROOM);
}

