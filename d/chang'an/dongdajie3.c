
// Room: /chang'an/dongdajie3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "东大街");
        set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。东边是一个大十字街
口。西面是长安的中央广场，北面是八字大开的衙门大门，门口站着几名
吊儿郎当的衙役，操着水火棍一副无所事事的样子。南面不时有快马进进
出出，原来是此处的驿站。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"dongdajie2",
                "south" : __DIR__"yizhan",
                "west"  : __DIR__"zhonglou",
                "north" : __DIR__"yamendamen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}