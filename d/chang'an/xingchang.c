// Room: /chang'an/xingchang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "刑场");
        set("long", @LONG
这里是长安城内行刑的地方，前一段时间官府下大力整治城区内的治
安，刚刚处决了一大批罪犯，刑台下面还有些暗红的血渍。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"deshanglu1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}