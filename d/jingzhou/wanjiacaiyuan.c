
// Room: /jingzhou/wanjiacaiyuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "万家菜园");
        set("long", @LONG
这里是万家大院的一片开阔地，平日里来的人少，戚芳闲时无事，也
就在里面种了些农作物，现在的菜园里种满了油菜、萝卜、茄子、丝瓜之
类。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south"  : __DIR__"wanjiahouyuan",
        ]));
        set("objects", ([
                __DIR__"npc/kongxincai" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}