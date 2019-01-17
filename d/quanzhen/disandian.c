// Room: disandian.c 第三殿

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "第三殿");
        set("long", @LONG
这里是全真教的第三殿，是全真七子集议之所。大殿中按北斗七星的方
位摆放着七张椅子。东西是走廊，往南是后殿，往北是后院。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"houyuan",
            "south" : __DIR__"houdian",
           ]));
         set("objects",([
"/d/quanzhen/npc/haodatong" : 1]));
               
        set("coor/x",-90);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",270);
	set("coor/z",190);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "全真教") &&!wizardp(me) 
	&& dir == "north" &&
		objectp(present("hao datong", environment(me))))
	   return notify_fail("郝大通喝道：“后院重地，你不是全真教弟子，不得入内。”\n");
		
        return ::valid_leave(me, dir);
}

