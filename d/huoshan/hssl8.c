
// Room: /huoshan/hssl.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "海市蜃楼");
        set("long", @LONG
你所见到的绿洲突然就眼睁睁地凭空消逝了，原来你所见到的
只是传说中的海市蜃楼，这时火辣辣的太阳更加强烈地烘烤着你的
身体，你觉得自己已经快坚持不住了，慌不择路，只希望快点离开
这个鬼地方。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "east"  : __DIR__"shamo1",
                "south" : __DIR__"shamo1",
                "west"  : __DIR__"shamo1",
                "north" : __DIR__"luzhou1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}