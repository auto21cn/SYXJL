// Room: xxiangfang.c

inherit ROOM;

void create()
{
        set("short", "西厢房");
        set("long", @LONG
你置身所在似是一间大户人家小姐的闺房。靠窗边的是一张梳妆台，台
上红烛高烧，照耀得房中花团锦簇，富丽堂皇。另一边是张牙床，床上罗帐
低垂，床前还放着一对女子的粉红绣鞋，显是有人刚睡在床上。这闺房只有
一道进门，窗户禁闭。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"houyuan",
]));
        set("sleep_room", "1");
        set("no_clean_up", 0);

        set("coor/x",-150);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",130);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

