
// Room: /chang'an/xiyuandamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "戏院大门");
        set("long", @LONG
这里就是长安城内的戏院了，人们娱乐消闲的时候都喜欢跑到这里来
听听具有浓郁的陕北风味的秦腔。听说这里原来最有名气的花旦小凤仙跟
人私奔了。为此现在戏院一直也没有开张，戏院老板现在急得要命，正在
四处张罗新角。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"dongdajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}