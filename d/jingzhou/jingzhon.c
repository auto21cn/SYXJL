
// Room: /jingzhou/jingzhonglu2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "荆中路");
        set("long", @LONG
你走在东大街上，踩着坚实的青石板地面，似乎可以感觉到这座城市
曾经辉煌的过去。往北是衙门，南面是屈原路，东面不时传来部队操练的
声音。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"zhangjuzhengjie",
                "south" : __DIR__"quyuanlu",
                "west"  : __DIR__"jingzhonglu",
                "north" : __DIR__"yamen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}