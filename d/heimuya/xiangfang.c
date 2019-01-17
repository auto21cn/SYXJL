inherit ROOM;

void create()
{
        set("short", "厢房");
        set("long", @LONG
房内布置得十分舒适，分别摆放着几张大床，供日月教徒们休息之用。
LONG
        );
        set("no_fight", "1");
        set("sleep_room", "1");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"pailou",
]));

        setup();
        replace_program(ROOM);
}
