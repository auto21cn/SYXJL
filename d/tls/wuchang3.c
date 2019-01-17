inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是天龙寺的练武场。由无数块巨大的花岗岩石板铺就。
上千年的踩踏已使得这些石板如同镜子般平整光滑。练武场中间
竖立着不少草靶。十来个僧人正在练习武艺。东面是武场中心。
LONG
	);

	set("exits", ([
		"west" : __DIR__"wuchang",
	]));

	set("objects",([
                __DIR__"npc/mu-ren" : 2 ]));

	set("outdoors", "tianlongsi");

	set("coor/x",-70);
	set("coor/y",-130);
	set("coor/z",20);
	set("coor/x",-70);
	set("coor/y",-130);
	set("coor/z",20);
	set("coor/x",-70);
	set("coor/y",-130);
	set("coor/z",20);
	set("coor/x",-70);
	set("coor/y",-130);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}



