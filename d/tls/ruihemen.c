inherit ROOM;

void create()
{
        set("short", "瑞鹤门");
        set("long",@LONG
这是通往天龙寺后寺的门户。你低头看看地上，只见铜门槛早已被踩
踏得锃亮，足见此寺香火之盛了。抬头向南可以望见点苍山耸立云天。
LONG
        );
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"wuchangge",
		"north": __DIR__"wuwoge",
	]));
        set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
