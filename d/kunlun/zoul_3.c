// room: /kunlun/zoul_3.c

inherit ROOM;



void create()

{

        set("short", "走廊");

        set("long", @LONG

这是一条静悄悄的走廊, 偶尔看见弟子或家仆匆匆忙忙地走过。西面是

厨房，东面是中厅。

LONG

        );

        set("exits", ([

                "west" : __DIR__"chufang",

                "east" : __DIR__"zhongt",

           ]));



        setup();

        replace_program(ROOM);

}



