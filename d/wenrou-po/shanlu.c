// shanlu  ..angle
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条窄窄的山路蜿蜒而上，路旁尽是又矮又密的灌木丛，一些碎石铺成
的小路却是格外的搁脚。东面是扬州采石场。
LONG
        );
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        set("exits", ([
          "east" : __DIR__"shichang1",
      "west" : "/d/wudang/wdroad1", 
]));
        set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}


