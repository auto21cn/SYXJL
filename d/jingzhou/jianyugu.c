
// Room: /jingzhou/jianyuguodao2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "监狱过道");
        set("long", @LONG
左边是一间封闭的牢房，只有门的下面有一道仅可递饭的小洞，里面了
无声息，又边是女囚室。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"shilao",
                "west"  : __DIR__"silao",
                "north" : __DIR__"jianyuguodao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}