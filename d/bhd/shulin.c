// Room: /u/setup/shulin.c



inherit ROOM;



void create()

{

        set("short", "树林");

        set("long", @LONG

向北一直走出二十余里，就是一大片丛林了。原来此岛方圆极广，延伸

至北，不知尽头。丛林老树参天，阴森森的遮天蔽日，林内有什么古怪，却

是不得而知。遇有好事之人肯定要进入一探的。



LONG

        );

        set("exits", ([ /* sizeof() == 3 */

	"south" : __DIR__"shishan",
	"north" : __DIR__"conglin",
]));

        set("no_clean_up", 0);

        set("objects", ([

		__DIR__"npc/bianfu":2,
         ]));

        setup();

        replace_program(ROOM);

}

