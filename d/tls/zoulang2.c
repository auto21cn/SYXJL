// zoulang.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是一段又长又黑的走廊，向西北是藏经阁。
LONG
        );

       set("exits", ([
               "northwest" : __DIR__"zoulang3",
               "southeast" : __DIR__"zoulang1",
       ]));
       set("coor/x",-90);
	set("coor/y",-90);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-90);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-90);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-90);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}
