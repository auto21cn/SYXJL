#include <ansi.h>



inherit ROOM;



void create()

{

    set("short", "ׯ������");

    set("long", @LONG

����һ�����á����Ϲ����߰˸���λ.����һ�������Ϲ���

��һ������.һ�����紵��,����ͻȻ����.

LONG

    );



    set("exits", ([

		"west" : "/d/city2/zhuang5",

    ]));

    set("objects", ([

		"/d/city2/npc/dizi": 1,

    ]));

    set("outdoors", "city2");

    setup();

   replace_program(ROOM); 

}




