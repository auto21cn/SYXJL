inherit ROOM;

void create()
{
        set("short", "卧云崖");
        set("long", @LONG
这是黑木崖的最西端卧云崖，山崖正巧高于云层一截，真有人在云
上走，云自脚下飘的雅致。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"guanpu",
]));
        set("objects", ([
                __DIR__"npc/tufei1" : 1,
                __DIR__"npc/tufei2" : 1,
        ]));

        setup();
}
