
// Room: /jingzhou/shilao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "石牢");
        set("long", @LONG
这是约莫两丈见方的一间大石屋，墙壁都是一块块粗糙的大石所砌，
地下也是大石块铺成，墙角落里放着一只粪桶，鼻中闻到的尽是臭气和霉
气。只见西首屋角之中，一对眼睛狠狠地瞪视着你。你身子一颤，没想到
这牢房中居然还有别人。只见石屋里还有二人，均是满脸虬髯，头发长长
的直垂至颈，衣衫破烂不堪，简直如同荒山中的野人。手上手铐，足上足
镣，甚至琵琶骨中也穿着两条铁链。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "west"  : __DIR__"jianyuguodao2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}