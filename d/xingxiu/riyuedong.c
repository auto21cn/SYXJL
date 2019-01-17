// riyuedong.c 日月洞
// by QingP

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "日月洞");
        set("long", @LONG
这里是星宿派总舵所在地日月洞。洞内灯火通明，正中一把虎皮椅上端坐着
星宿派掌门人丁春秋。洞壁上装饰着虎皮、鹿头、雕羽，及一些字画(zihua)。
洞两侧竖立兵器架，上面排列的大多是各种棍棒。
LONG
        );
        set("exits", ([
             "south" : __DIR__"xxh2",
        ]));

        set("item_desc", ([
                "zihua" : "\n\n"

HIY"		※※※※※※※※※※※※※※※※※\n"NOR
HIY"		※※※※　　　　　　　　　※※※※\n"NOR
HIY"		※※※※　"HIG"古　威　德　星　"HIY"※※※※\n"NOR
HIY"		※※※※　"HIG"今　震　配　宿　"HIY"※※※※\n"NOR
HIY"		※※※※　"HIG"无　寰　天　老　"HIY"※※※※\n"NOR
HIY"		※※※※　"HIG"比　宇　地　仙　"HIY"※※※※\n"NOR
HIY"		※※※※　　　　　　　　　※※※※\n"NOR
HIY"		※※※※※※※※※※※※※※※※※\n\n"NOR

        ]) );

        set("objects", ([
                "/kungfu/class/xingxiu/ding" : 1,
                __DIR__"npc/dizi" : 2,
                 "/kungfu/class/xingxiu/tianlang" : 1,
        ]) );

        set("no_clean_up", 0);

        set("coor/x",-120);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}
