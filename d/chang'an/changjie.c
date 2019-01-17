
// Room: /chang'an/changjie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "长街");
        set("long", @LONG
真是一条长街，老远才望得到头，两边都是高高的院墙。脚下踩的是
碎石铺成的路面。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"gulou",
                "west"  : __DIR__"jiekou4",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}