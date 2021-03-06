// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
set("short", "扬州广场");
	set("long", @LONG
这里是城市的正中心，一个很宽阔的广场，铺着青石地面。一些游手好闲的人
在这里溜溜达达，经常有艺人在这里表演。正中央有一棵大榕树，盘根错节，据传
有千年的树龄，是这座城市的历史见证。树干底部有一个很大的洞(shudong)。你
可以看到北边有来自各地的行人来来往往，南面人声鼎沸，一派繁华景象，东边不
时地传来朗朗的读书声，西边则见不到几个行人，一片肃静。
LONG
	);
        set("no_sleep_room",1);
        set("outdoors", "city");

	set("item_desc", ([
		"shudong" : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n",
	]));

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
	]));

	set("objects", ([
		__DIR__"npc/liumang" : 2,
		__DIR__"npc/liumangtou" : 1,
 //  "/d/honghua/stealer" : 1,
	]));

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

/*
void do_rumor(object me)
{
	if (!me)    return;
	if (!userp(me)) return;
		CHANNEL_D->do_channel(this_player(),"rumor","天啦！"+me->name()+"在街上裸奔呀！");
}
*/
void init()
{
/*	object me;
	me=this_player();
	if (!me->query_temp("armor/cloth") && me->query("race")=="人类" ){
		if (time()-me->query_temp("rumor/nocloth")>10){
			me->set_temp("rumor/nocloth",time());
			call_out("do_rumor",random(5),me);
		}
	}
*/	
        add_action("do_enter", "enter");
//	UPDATE_D->check_user(this_player());
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="shudong" ) 
	{
		message("vision",
			me->name() + "一弯腰往洞里走了进去。\n",
			environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
                         me->name() + "从洞外走了进来。\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
