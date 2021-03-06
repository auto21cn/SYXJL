// Room: /d/emei/dadian.c

inherit ROOM;

void create()
{
	set("short", "千佛庵大殿");
	set("long", @LONG
大殿内法相庄严，地下放着数个蒲团，几个尼姑在一旁吟佛颂礼，神台前站
着一位眉目秀丽，表情严肃的女尼，这就是峨眉派的掌门大师姐，近来掌门人灭
绝师太身体不适，派中一应大小事务都交给了大师姐办理。
LONG
	);
         set("valid_startroom",1);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xilang6",
  "south" : __DIR__"dian2",
  "north" : __DIR__"dian3",
  "east" : __DIR__"dxiang",
]));

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
