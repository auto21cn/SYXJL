inherit ROOM;

void create()
{
        set("short", "晃天门");
        set("long",@LONG
这是出入天龙寺的必经之路。往西望去，可见寺中亭台楼阁规模宏
大，构筑精丽，宅地连云，其气势之盛更胜于五台，普陀等诸处佛门胜地
的名山大寺。
LONG
        );
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"jietan",    			
	        "west" : __DIR__"wulege",
		"east" : __DIR__"wuchangge",
	]));
	set("objects",([
	         __DIR__"npc/saodiseng" : 1,
	]));

        set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
