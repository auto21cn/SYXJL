// shengdian.c

inherit ROOM;

void create()
{
        set("short", "圣殿");
        set("long", @LONG
这里是天龙寺最神圣的地方，整个大殿摆满了黄金做成的法器，中
间供奉着一座五米高的大如来佛象，光照上去，金光灿灿，所有的一切
无不体现出天龙寺在大理国至高无上的地位。佛像前一个老和尚正盘膝
而坐，完全不受这满屋金光的影响。
LONG
        );

       set("exits", ([
               "north" : __DIR__"zoulang1",
               "south" : __DIR__"doushuai",
               "east" : __DIR__"jialan",
               "west" : __DIR__"fzlou",
       ]));
        set("objects", ([
                __DIR__"npc/benxiang": 1,

]));
        set("no_clean_up", 0);
        set("coor/x",-80);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
        set("valid_startroom", 1);

}

