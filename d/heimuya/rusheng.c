inherit ROOM;

void create()
{
        set("short", "入胜亭");
        set("long", @LONG
五老峰边壁上，有一座八角亭台，从此可上观奇云，下览秀石，
当真是身入胜境欲不归。好一派景色风光（fengguang）。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wulao",
]));
    set("item_desc", ([
        "fengguang" : "心旷神移之下，咦，怎么看五老峰中腰处有一点暗影。\n",
    ]));
        set("objects", ([
                __DIR__"npc/youke": 1,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
