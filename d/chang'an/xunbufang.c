// Room: /chang'an/xunbufang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "巡捕房");
        set("long", @LONG
这里就是巡捕房了，由考场新考取的考生基本上每个人都要先到这里
来锻炼上一段时间，主要做做城内巡逻，抓抓罪犯小偷什么的事情。北面
是休息室，南面是一间很小的临时牢房。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"xiuxishi",
                "west"  : __DIR__"shangdelu1",
                "north" : __DIR__"laofang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}