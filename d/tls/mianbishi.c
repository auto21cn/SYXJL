inherit ROOM;

void create()
{
	set("short", "面避室");
	set("long", @LONG
这里是天龙寺僧人思过的面壁室，除了地上有几个蒲团外，只剩下光秃秃的墙壁了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"sanwugong",
	]));
        set("no_fight", 1);
	set("no_steal",1);

	set("coor/x",-60);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-100);
	set("coor/z",30);
	setup();
}

void init()
{
	object me = this_player();

	if ((int)me->query_temp("bamboo/count") == 14 
	&&  (int)me->query_skill("dodge", 1) >= 30 
	&&  (int)me->query_skill("dodge", 1) <= 100 
	&&  present("bamboo", me) )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("dodge", me->query("int"));
	}

        add_action("do_mianbi","面壁");	
        add_action("do_mianbi","mianbi");	
}

int do_mianbi()
{
	object me = this_player();

	message_vision("$N面对着面壁室後半边的石壁跌坐静思，良久，似有所悟。\n", me);
	
	me->set_busy(10);
	me->set("shen",0);

	return 1;
}
