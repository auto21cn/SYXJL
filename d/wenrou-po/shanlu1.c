// shanlu1  ..angle
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条窄窄的山路蜿蜒而上，路旁尽是又矮又密的灌木丛，一些碎石铺成
的小路却是格外的搁脚！
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
  "eastup" : __DIR__"shanlu2", 
  "southdown" : __DIR__"shichang", 
  "westdown" : __DIR__"shichang1", 
]));
        set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",10);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",10);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",10);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
}


