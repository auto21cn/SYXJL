//zhulin.c
inherit ROOM;
void create()
{
  set("short","竹林");
  set("long",
  "这里是青竹林，常有蛇出没。南边是蒿草丛。北边有一个大岩洞。\n"
      );
  set("exits",([
      "northup" : __DIR__"cave",
      "south" : __DIR__"cao2",
     ]));
 set("objects",([
		"/clone/beast/jinshe" : random(3),
		"/clone/beast/dushe"  : 1 + random(3),
		"/clone/beast/fushe"  : random(2),
		"/clone/beast/qingshe": random(2),
		"/clone/beast/wubushe": random(3),
      ]));
 set("coor/x",-160);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-160);
	set("coor/y",10);
	set("coor/z",0);
	setup();
 replace_program(ROOM);
}




