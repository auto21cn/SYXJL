
inherit BULLETIN_BOARD;

void create()
{
	set_name("��ػ�������԰�", ({ "board" }) );
	set("location", "/d/city2/dating");
	set("board_id", "tiandi_b");
	set("long", "����һ������ػ���ӽ��������԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}