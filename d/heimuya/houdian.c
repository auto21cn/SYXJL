inherit ROOM;

void create()
{
        set("short", "后殿");
        set("long", @LONG
殿中无窗，殿口点着明晃晃的蜡烛，当中摆放一张大长桌，两旁摆满了
各式椅子，一看就知道这里是教中重要人物议事谋策的地方。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"laofangrk",
  "north" : __DIR__"changlang6",
  "west" : __DIR__"changlang5",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zhou" : 1,
  __DIR__"npc/wu" : 1,
]));

        setup();
        replace_program(ROOM);
}