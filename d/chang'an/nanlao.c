// Room: /chang'an/nanlao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "男监");
        set("long", @LONG
里面的人很多，因此显得拥挤不堪，又没有人打扫，骚臭的味道甚至
盖过了霉味，别人的脚丫子抵着你的鼻子睡觉你也难得挪个窝，现在你开
始后悔不去做一个守法的良民了吧，还不叫你的亲戚朋友往知府那里送点
银子好出去！
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"jianyuguodao",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}