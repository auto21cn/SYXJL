// /clone/board/shaolin_b.c



inherit BULLETIN_BOARD;



void create()

{

        set_name("天龙寺弟子留言板", ({ "board" }) );
        set("location", "/d/tls/baodian");
        set("board_id", "tianlongsi_b");
        set("long", "这是一个供天龙寺弟子交流的留言板。\n" );
	setup();

	set("capacity", 30);

	replace_program(BULLETIN_BOARD);

}

