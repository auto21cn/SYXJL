// Room: /d/kunlun/qianting.c 

#include <ansi.h> 
inherit ROOM; 
 
void create() 
{ 
        set("short", "前厅");
        set("long", @LONG
走进大门, 这里是三圣堂前厅。厅中简单地放着几张桌椅, 一般来客均在 
此稍事休息, 等待家仆或弟子向里面通报。左右不时传来呼喝之声, 都是练武 
场。昆仑派故意将练武场设在前厅之侧, 一来在这里练武的弟子所学的均是入 
门功夫，不怕观看，二来可以显得弟子众多, 以壮昆仑声势。 
LONG
        );
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/kl-dizi3.c" : 2,
  __DIR__"npc/banshuxian.c" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lianwu2",
  "west" : __DIR__"lianwu1",
  "north" : __DIR__"zhongt",
  "out" : __DIR__"damen",
]));

        setup();
//       replace_program(ROOM);
        "/clone/board/kunlun_b"->foo();
} 

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "昆仑派") && dir == "north" &&
                objectp(present("ban shuxian", environment(me))))
    return notify_fail(HIW"\n班淑娴喝道：你不是昆仑弟子，要想入内需过我这关! \n"NOR);
                
        return ::valid_leave(me, dir);
}

