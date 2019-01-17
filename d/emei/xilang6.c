inherit ROOM;

void create()
{
	set("short", "西廊");
	set("long", @LONG
这里是通往师太们的禅房的过道，东边就是千佛庵的大殿。这里很是安
静，没有了嘈杂的人声，两边是一排排的花草。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xilang",
  "east" : __DIR__"dadian",
]));
	set("no_clean_up", 0);

	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
