
inherit ROOM;

void create()
{
	set("short", "海港");
	set("long", @LONG
这是一望无际的大海，海中心隐隐约约能看见有一艘船。
在西南面隐约听见“哗，哗，哗．．．”的潮水声。这里是
到冰火岛的唯一的路了。
LONG
	);

	set("exits", ([
                "west" : "/d/city2/road3",
	]));

	set("objects", ([
		__DIR__"npc/chuanfu" :1,
	]));

	set("outdoors", "city2");
	set("coor/x",20);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
