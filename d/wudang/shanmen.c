// shanmen.c 武当山门
// by Xiang

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "武当山门");
        set("long", @LONG
        你的面前是一座林木繁茂的高山，几座山峰在云雾中隐约可见，一条石
阶向山上延伸，走着几个进香客。石壁上写着“武当山”三个大字，原来这就是
天下闻名的武当山。
LONG
        );
        set("outdoors", "wudang");

        set("exits", ([
                "east" : __DIR__"wdroad8",
                "westup" : __DIR__"shijie11",
//                "west" : "/d/mingjiao/westroad1",
        ]));
        set("objects", ([
                __DIR__"npc/guest" : 1,
               __DIR__"npc/zhike" : 1]));
        set("coor/x",-40);
        set("coor/y",-90);
        set("coor/z",0);
        set("coor/x",-40);
        set("coor/y",-90);
        set("coor/z",0);
        set("coor/x",-40);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
//      replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if (me->query_temp("shou") && (dir == "east" || dir == "westup") &&
                objectp(present("zhike daozhang", environment(me))))
        {
        message_vision(CYN"$N突然想离开山门。\n"NOR,me);
        message_vision(CYN"知客道长不高兴的对$N说道：“守门时不要乱跑。如果你不想守门的话就放弃吧。”\n"NOR,me);
        return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

