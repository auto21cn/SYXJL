// cave1.c

// by QingP



inherit ROOM;



void close_gate();

int do_open(string arg);

int do_close(string arg);





void create()

{

	set("short", "山洞");

	set("long", @LONG

这个山洞里点着几支昏暗的蜡烛，阴森森的让人感到浑身上下都不舒服。

右边的墙壁(bi)看上去似乎有点不大对劲。

LONG

	);



	set("item_desc", ([

	"bi":"你仔细看了看墙壁，发现它竟然是一扇隐蔽的石门，可不知怎么打开。\n",

	]));

	set("exits", ([

		"out" : __DIR__"cave",

	]));



	set("objects", ([

		"/kungfu/class/xingxiu/tianlang" : 1,

	]));



	setup();

}



void init()

{

	add_action("do_open", "open");

	add_action("do_open", "unlock");

}



void close_gate()

{

	object room;



	if(!( room = find_object(__DIR__"mishi")) )

		room = load_object(__DIR__"mishi");

	if(objectp(room))

	{

		delete("exits/north");

		message("vision","只听乒地一声，暗门自动关了起来。\n",this_object());

                message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n" ,this_object());

		room->delete("exits/south");

		message("vision","只听乒地一声，暗门自动关了起来。\n",room);

	        message("vision","你脑海中闪过一个念头：坏了！出不去了！\n" ,room );

	}

}



int do_open(string arg)

{

	object room;

        object ob;



	if (query("exits/north"))

		return notify_fail("暗门已经是开着了。\n");



	if (!arg || (arg != "bi" && arg != "north"))

		return notify_fail("你要开什么？\n");

	if (!(ob = present("mishikey", this_player())))

		return notify_fail("你会撬锁？！\n");

	message_vision("$N用钥匙打开了暗门，可一不小心钥匙卡在里面断了.\n", this_player());

	

	destruct(ob);



	if(!( room = find_object(__DIR__"mishi")) )

		room = load_object(__DIR__"mishi");

	if(objectp(room))

	{

		set("exits/north", __DIR__"mishi");

		message_vision("$N使劲把暗门打了开来。\n",this_player());

		room->set("exits/south", __FILE__);

		message("vision","里面有人把暗门打开了。\n",room);

		remove_call_out("close_gate");

		call_out("close_gate", 10);

	}



	return 1;

}



int valid_leave(object me, string dir)

{

	if (objectp(present("tianlang zi", environment(me)))

	&& (dir == "north"||dir == "south")

	&& living(present("tianlang zi", environment(me))))

		return notify_fail("天狼子挡住了你：此乃本门禁地，赶紧快快离去，被师傅发现你就大事不妙了！\n");

	return ::valid_leave(me, dir);

}