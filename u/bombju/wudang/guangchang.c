// guangchang.c 广场
// by Xiang

inherit ROOM;

void create()
{
        set("short", "武当广场");
        set("long", @LONG
        这是一个由大石板铺成的广场，是武当弟子学习武功和互相切磋的地点。
周围种满了梧桐树，一到秋天就是满地的落叶。一个年纪轻轻的道童正在打扫。
北边是灵霄宫三清殿。
LONG
        );
        set("outdoors", "wudang");

        set("exits", ([
                "southdown" : __DIR__"shijie62",
                "north" : __DIR__"sanqingdian",
                "west"  :__DIR__"shijie7",
                "east"  :__DIR__"xiaolu",
        ]));
        set("objects", ([
            __DIR__"npc/qingshu" : 1 ,
                CLASS_D("wudang") + "/daotong" : 2]));

        set("coor/x",-50);
        set("coor/y",80);
        set("coor/z",180);
        set("coor/x",-50);
        set("coor/y",80);
        set("coor/z",180);
        set("coor/x",-50);
	set("coor/y",80);
	set("coor/z",180);
	setup();
        replace_program(ROOM);
}
