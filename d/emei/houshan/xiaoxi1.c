inherit ROOM;
void create()
{
	set("short", "小溪");
	set("long", @LONG
这是一条不起眼的山间小溪，夹在两座高山之间，小溪上冒着热气，
看来还是一个温泉，两边的植物也由于它的原因而分外茂盛，空气中还夹
杂着颇为刺鼻的硫磺的味道，向着小溪的上游去，硫磺的味道越来越浓。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xiaoxi2",
  "northwest" : __DIR__"shandao1",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",100);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
