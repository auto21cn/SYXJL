// /clone/board/honghua_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("红花会弟子留言板",({"board"}));
	set("location","/d/honghua/zongduo");
	set("board_id", "hongh_b");
	set("long", "这是供红花会弟子留言的板子.\n");
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

