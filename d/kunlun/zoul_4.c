// room: /kunlun/zoul_4.c

inherit ROOM;



void create()

{

        set("short", "走廊");

        set("long", @LONG

这是一条静悄悄的走廊, 偶尔看见弟子或家仆匆匆忙忙地走过. 东面是

家仆的卧室，西面是中厅。

LONG

        );

        set("exits", ([

                "west" : __DIR__"zhongt",

                "east" : __DIR__"jiapuwsh",

        ]));



        setup();

        replace_program(ROOM);

}



