// 修改by think

inherit ROOM;

void create ()
{
	set ("short", "右看台");
	set ("long", @LONG
这是「随缘洗剑录」比武场的左看台，看台上有一排排的木制条
凳。你坐在这里一丈高的比武台上一切比武过招你都能看得非常
清楚。这里还提供免费的饮食。
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"up"   : __DIR__"biwutai",
		"northwest"   : __DIR__"houtai",
		"southwest"   : __DIR__"kantai2",
		"south"   : __DIR__"zoulang",
	]));
	setup();
}

void init()
{
	add_action ("do_work","ansuan");
}

int do_work()
{
	write("在这里你还敢暗算别人？\n");
	return 1;
}

int valid_leave(object me, string dir)
{
        object tai=load_object(__DIR__"biwutai");
        object *inv=all_inventory(tai);
	object ob, where;
        int i=sizeof(inv);

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="up" ) {
		if( ob->query("start/start") && !me->query("biwu_fighter") )
			return notify_fail("比武已经开始了，你不是选手不能上台。\n");
		if(i>=2)
			return notify_fail("比武台上已经有两名选手，你现在不能上台。\n");
	}
        return ::valid_leave(me, dir);
}
