inherit ROOM;

void create()
{
	set("short", "药王洞");
	set("long", @LONG
这里就是峨嵋著名的九老洞了，一个很空旷的大洞内，摆满了各种丹
药和炉鼎，一个中年尼姑在指挥着众人干活。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shandao4",
]));
	set("objects",([
       __DIR__"npc/jingci" : 1,
     ]));

	set("coor/x",0);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",0);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",0);
	set("coor/y",110);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
