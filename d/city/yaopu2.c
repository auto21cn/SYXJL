// Room: /d/city/yaopu.c
// YBL 2000/07/27
inherit ROOM;

void create()
{
        set("short", "药铺");
        set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小
抽屉里散发出来的。神医平一指坐在茶几旁，独自喝着茶，看也不看你一眼。
一名小伙计站在柜台后招呼着顾客。柜台上贴着一张发黄的广告(guanggao)
和一张新贴的牌子(paizi)。里面是扬州城的治疗室。
LONG);

        set("no_fight", 1);
        set("no_study", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);
       set("no_dexmove",1);
        set("no_yun",1);
        set("no_shot","敢在公众场合放暗器？不想混了？");

        set("item_desc", ([
                "paizi" : "疗伤五两黄金。\n",
        ]));

        set("objects", ([
                  __DIR__"npc/huoji" : 1,
        ]));

        set("exits", ([
                "south"  : __DIR__"dongdajie2",
                "north" : __DIR__"yaopu1",
        ]));

}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
   notify_fail("伙计挡在你的面前，笑者说：请您老先付症金！\n");

        if ( me->query_temp("rent_paid") && dir == "west" )
  notify_fail("伙计一把拦住你说：您老还没看病，怎麽就走了？\n");

        return ::valid_leave(me, dir);
}


