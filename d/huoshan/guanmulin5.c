
// Room: /huoshan/guanmulin5.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "灌木林");
        set("long", @LONG
这里仿佛到了热带雨林般，在一些大树中间长满了灌木丛，中
间有一条羊肠小道，一不小心就有些荆棘挂破了你的衣服，端的是
难走得紧。

LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "east"  : __DIR__"shamo1",
                "south" : __DIR__"",
                "west"  : __DIR__"shamo1",
                "north" : __DIR__"shamo1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}