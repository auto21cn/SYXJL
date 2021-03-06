// mishi.c

// by QingP



#include <room.h>



inherit ROOM;



void close_gate();

int do_unlock(string arg);



void create()

{

	set("short", "密室");

	set("long", @LONG

这个密室是丁春秋练功的地方，四周摆满了各种毒器、丹药。

密室的中间摆放着一尊木鼎。

LONG

	);



	set("objects", ([

		__DIR__"obj/xiaoyaosan" : 1,

		__DIR__"obj/shihunxing" : 2,

		__DIR__"obj/lianxindan" : 2,

		__DIR__"obj/wangding" : 1,

	]));

	setup();

}



void init()

{

	add_action("do_unlock", "unlock");

	add_action("do_unlock", "open");

}



void close_gate()

{

    object room;



    if(!( room = find_object(__DIR__"cave1")) )

        room = load_object(__DIR__"cave1");

    if(objectp(room))

    {

        delete("exits/south");

        message("vision","只听乒地一声，暗门自动关上了。\n",this_object());

        message("vision","你脑海中闪过一个念头：坏了！出不去了！\n" ,this_object());

        room->delete("exits/north");

        message("vision","只听乒地一声，暗门自动关了起来。\n", room);

        message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n" ,room );

     }

}





int do_unlock(string arg)

{

	object room;

	if (query("exits/south"))

		return notify_fail("暗门已经是打开的。\n");

	if (!arg || (arg != "bi"))

		return notify_fail("你要打开什么？\n");

	message_vision(	"$N从里面打开了暗门。\n", this_player());

	set("exits/south", __DIR__"cave1");

	if(!( room = find_object(__DIR__"cave1")) )

	room = load_object(__DIR__"cave1");

	if(objectp(room))

	{

        	set("exits/south", __DIR__"cave1");

        	message_vision("$N轻轻地推门，只听吱地一声，门开了。\n",this_player());

        	room->set("exits/north", __FILE__);

        	message("vision","只听吱地一声，暗门从外面打开了。\n", room);

		remove_call_out("close_gate");

		call_out("close_gate", 10);

	}

return 1;

}