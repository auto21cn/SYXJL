
// Room: /jingzhou/xuandigong.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "玄帝宫");
        set("long", @LONG
玄帝宫始建于唐代，规模宏大，由于现在本朝的皇帝信奉道教，所以这
里的道士显得更加傲慢，根本无视于你的存在，忙碌着自己的事情，你只好
大发一篇感叹后无奈地离开。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"xidajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}