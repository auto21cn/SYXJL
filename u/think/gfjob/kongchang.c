inherit ROOM;

void create()
{
        set("short", "广场");
        set("long", @LONG
这是知府旁边的一片小空场，在东边的墙上贴了几张官府悬赏捉拿朝廷
要犯的告示，下面围观了许多看热闹的人，当中不乏一些武林高手，但
是要捉拿的要犯都很扎手，很少有人随便揭榜（jie wenshu）,但也有不
少武林后起之秀在一旁跃跃欲试。
LONG
        );

        set("exits", ([
                 "southwest" : "/d/city/yamen",
                 
        ]));
        set("objects", ([
                "/quest/gfjob/npc/yayi" : 1,
        ]));
         
        setup();
}
#include "/quest/gfjob/job2.h"


