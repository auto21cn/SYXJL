#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石坊");
        set("long",
"这座石坊据传是上古留传下来的，石坊上横书"GRN"“震旦第一”"NOR"四个字，\n"
"字虽不大，却很有气势，使人不由为之一凛，此处山势虽陡，却使人意兴\n"
"盎然，再往上走就是玉女池了。\n"
        );

        set("exits", ([
		"northup" : __DIR__"yunvchi",
		"southdown" : __DIR__"jietuo",
               ]));

        set("coor/x",-40);
	set("coor/y",-40);
	set("coor/z",40);
	set("coor/x",-40);
	set("coor/y",-40);
	set("coor/z",40);
	set("coor/x",-40);
	set("coor/y",-40);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}