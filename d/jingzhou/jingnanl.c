
// Room: /jingzhou/jingnanlu2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "荆南路");
        set("long", @LONG
你走在一条由青石铺砌的路面上，脚下的大青石看起来年代已经很久
远了，东边可以看到几名守城的军士，北面传来“叮叮当当”的金属碰撞
的声音。南面是一座看起来非常牢固的监狱。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"dongmen",
                "south" : __DIR__"jianyudamen",
                "west"  : __DIR__"jingnanlu",
                "north" : __DIR__"datiepu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}