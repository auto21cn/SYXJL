
// Room: /jingzhou/nvrenjiepu3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "女人街店铺");
        set("long", @LONG
这是一家专门卖针线荷包的小店，店里做着个满脸和蔼之气的老婆婆，
正做在那里一心一意地将线往针里穿，膝盖上放着一个没有做完的绣花荷包。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"nvrenjie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}