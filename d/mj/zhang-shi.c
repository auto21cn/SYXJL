// Room: zhang-shi.c

inherit ROOM;

void create()
{
        set("short", "小房间");
        set("long", @LONG
一个不能算大，也不能算小的房间，可怜巴巴的座落在这儿，
一个瘦小枯干的老头怒气冲冲的站在那里，吹胡子，瞪眼睛，嘴
巴一张一合，唾沫满天飞！也不知他为何生气！
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"niushi",
  "east" : __DIR__"luzhou",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhywai" : 1,
]));
        set("no_clean_up", 0);

        set("coor/x",-90);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

