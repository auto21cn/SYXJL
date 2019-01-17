
// Room: /jingzhou/xidajie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条青石铺砌的宽阔大道，道路两边长着苁蓉的大树，几乎遮住
了所有的阳光。北面是这一代有名的道观“玄帝宫”，往南面是郢都路。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"xidajie3",
                "south" : __DIR__"yingdulu",
                "west"  : __DIR__"xidajie",
                "north" : __DIR__"xuandigong",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}