// 修改 by think

inherit ROOM;

void create ()
{
	set ("short", "后台");
	set ("long", @LONG
这是比武场的后台，上面是贵宾席用来主持比武的地方，只有巫师或
者贵宾才能上去。
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"up"   : __DIR__"caipan",
		"southeast"   : __DIR__"kantai3",
		"southwest"   : __DIR__"kantai1",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob, where;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="up" )
	return notify_fail("只有巫师才能从这里进入贵宾席。\n");
	return ::valid_leave(me, dir);
}
