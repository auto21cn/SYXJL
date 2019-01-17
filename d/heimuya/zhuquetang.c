inherit ROOM;

void create()
{
        set("short", "朱雀堂");
        set("long", @LONG
堂内只点着两盏油灯，两朵火焰忽明忽暗，相距既远，火光又暗，依稀
有几个人在打座练功，但相貌如何便瞧不清楚了。
LONG
        );
        set("sleep_room", "1");
        set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"chengdedian",
		"west" : __DIR__"baihutang",
]));
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bao" : 1,
]));

        setup();
        replace_program(ROOM);
}
