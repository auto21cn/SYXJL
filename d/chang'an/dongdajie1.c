
// Room: /chang'an/dongdajie1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "东大街");
        set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。东面是朝阳内门，远远
地可以看见守城的军士偶尔开着小差。北面是一家很大的酒楼，不时飘来
一阵阵酒肉的香味，南面是一座戏院。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"eastgate1",
                "south" : __DIR__"xiyuandamen",
                "west"  : __DIR__"dongdajie2",
                "north" : __DIR__"diyilou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}