inherit ROOM;

void create()
{
        set("short", "索道");
        set("long", @LONG
来到这条索道，两边是深不见底的崖谷，岩壁两侧设有铁索以作扶拦。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"baichi",
]));
        set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/rygirl" : 1,
]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
