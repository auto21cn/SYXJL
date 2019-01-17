// by mayue


inherit ROOM;

void create()
{
        set("short", "正气堂");
	set("long", @LONG
这里是红花会的正气堂，是红花会商议要事的地方，屋子两旁整齐的摆放着
两排红木大椅。有一个少年正在收拾着一些东西，听见脚步声不觉瞟了你一眼
神色有些慌张。
LONG
	);
//      set("outdoors", "honghua");

	set("exits", ([
		"south" : __DIR__"huating2",
		"west" : __DIR__"huayuan1",
		"north" : __DIR__"huating3",
	]));
        set("objects", ([
                "/d/city/npc/main":1,
                "/u/ybl/honghua/npc/xinyan":1,
	]));
    

	setup();
	replace_program(ROOM);
}

