inherit ROOM;

void create()
{
    set("short", "五老峰");
    set("long", @LONG
此处有五坐石峰紧紧相靠，石峰自上而下有数百年的草藤随风飘洒，
就象年逾古稀的五位老朋友在叙旧一般。这里远离人烟，动物渐多，眼
前就有一对猴群（houqun）跳上跳下。
LONG
    );
        set("exits",([
            "west" : __DIR__"lianhua",
            "east" : __DIR__"ziyun",
            "north" : __DIR__"yiping",
            "south" : __DIR__"rusheng",
            "down" : __DIR__"wulaoqiao",
        ]));
        set("objects", ([
                __DIR__"npc/houzi": 2,
                __DIR__"npc/xiaohou": 2,
                __DIR__"npc/wolf": 2,

]) );
	set("item_desc", ([
		"houqun" : "这群猴子自跳自闹，一会跳下峰壁，一会又窜上峰顶。\n",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "down" && this_player()->query("age")>12)
                return notify_fail("下边杂草丛生，根本看不到路，小心一失足成千古恨。\n");
        return ::valid_leave(me, dir);
}
