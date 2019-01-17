inherit ROOM;


void create()
{
        set("short", "解脱桥");
        set("long", @LONG
解脱桥横架于瑜伽河上。上面是解脱坡，坡上有一座小寺庙，唤作“雷
音塔”，远观可见寺庙四面金檐小巧雅洁；坡侧有泉，清澈如镜，可以供游
人香客净身沐浴之用，自古就有“神仙会”的美称。经桥过瑜伽河，北面是
一道石坊，直通山上。
LONG
        );

        set("exits", ([
		"westdown" : __DIR__"fuhusi",
		"northup" : __DIR__"shifang",
               ]));

        set("coor/x",-40);
	set("coor/y",-50);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-50);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-50);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}