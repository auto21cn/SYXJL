//Room: /u/lzd/dali/zhulin2.c
//Date: June. 29 1998 by Java
 
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short","竹林深处");
        set("long",
"这儿是竹林的深处，只见前方不远处有一个男子正跪\n"
"在什么面前呆呆的说着什么，你好奇的走近一看，原来是\n"
"座"HIR "墓碑" NOR "(mubei)。\n");
        set("objects", ([
           __DIR__"npc/xiaofeng": 1,
        ]));
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */
            "north"      : __DIR__"hexi",
        ]));
        
        set("item_desc", ([
        "mubei" : "\n\n" 
HIW"             ※※※※※※※\n"NOR
HIW"             ※※※※※※※\n"NOR 
HIW"             ※※  "HIR"爱  "HIW"※※\n"NOR
HIW"             ※※  "HIR"妻  "HIW"※※\n"NOR
HIW"             ※※  "HIR"阿  "HIW"※※\n"NOR
HIW"             ※※  "HIR"朱  "HIW"※※\n"NOR
HIW"             ※※  "HIR"之| "HIW"※※\n"NOR
HIW"             ※※  "HIR"墓萧"HIW"※※\n"NOR
HIW"             ※※    "HIR"峰"HIW"※※\n"NOR
HIW"             ※※※※※※※\n"NOR
HIW"             ※※※※※※※\n"NOR
                 
                 ]) );

                 set("no_clean_up", 0);
                 set("coor/x",-10);
	set("coor/y",-220);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-220);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-220);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-220);
	set("coor/z",10);
	setup();
}
