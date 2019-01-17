
// Room: /chang'an/yihongge.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "怡红阁");
        set("long", @LONG
你一走进来，一名妖冶的女人马上围了过来在你身边磨蹭。厅内到处
张灯结彩，香气扑鼻。几名打扮得妖里妖气的女人分站两旁对你发出媚笑。
一名鸩母正上上下下、前前后后招呼着客人。从楼上传来了一阵阵打情骂
俏的声音。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"yanhuaxiang",
                "up"    : __DIR__"yihonggeerlou"
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}