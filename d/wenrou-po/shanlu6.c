// shanlu6  ..angle
inherit ROOM;

void create()
{
        set("short", "山顶");
        set("long", @LONG
这是山顶的一片空地，方圆十几丈，山风缓缓的吹过，你不由的从泛
起几丝凉意，抬头向上望去，一座古色古香的寺庙就矗立在前方，一条笔
直的石阶向上延伸着……
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
  "northup" : __DIR__"shanlu7", 
  "westdown" : __DIR__"shanlu5",]));
        set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",60);
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",60);
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",60);
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",60);
	setup();
}


