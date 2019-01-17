
// Room: /huoshan/guanmulin6.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "灌木林");
        set("long", @LONG
转了半天，面前却出现了一面山壁，看来这里就是这条路的尽
头了，坚实的山壁挡住了路的去向。靠着山角的一片地方有一大片
灌木(guanmu)长得格外茂盛，仿佛是人为地堆在那里一般。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "south" : __DIR__"guanmulin5",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}