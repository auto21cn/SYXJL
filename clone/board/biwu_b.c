inherit BULLETIN_BOARD;

void create()
{
        set_name("风云榜", ({ "board" }) );
        set("location", "/u/linghu/gate");
        set("board_id", "biwu_b");
        set("long", "这是一个比武专用报名留言板。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

