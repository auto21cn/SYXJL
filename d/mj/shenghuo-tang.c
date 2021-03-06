// Room: shenghuo-tang.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"圣火堂"NOR);
        set("long", 
"这里就是明教圣火堂所在。正上方有一幅横匾上书「"RED"圣火堂"NOR"」三
个血红大字。正面墙上的石壁中刻着一团巨大的火红烈焰，升腾向上，
呼之欲出。两边各竖挂一条字幅：\n"
HIY @LONEA
“焚我残躯，熊熊圣火，生亦何欢，死亦何苦？为善除恶，惟光明故，”
“喜乐悲愁，皆归尘土。怜我世人，忧患实多！怜我世人，忧患实多。”
LONEA
NOR @LONEB
由于近年来明教威名大盛，前来朝拜的江湖中人络绎不绝，四周墙上挂
满了访客留下的称颂之词。正中设有教主的宝座，左右两排分列护法教
众。西面通往教主休息的后院。南面是聚义厅。
LONEB
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"juyiting",
  "west" : __DIR__"xiaoting",
  "east" : __DIR__"jyentrance",
]));
        set("objects", ([
  __DIR__"npc/mingjiaodizi" : 4,
__DIR__"npc/zhangwuji" : 1,
]));
        set("no_clean_up", 0);

        set("coor/x",-130);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",120);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


