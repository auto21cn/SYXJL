
// Room: /chang'an/mahang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "马行");
        set("long", @LONG
这里是长安城内唯一一家车马行。你可花一点钱租辆马车到各个城市
去，能节约不少体力。这里圈养着不少的好马
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"nandajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}