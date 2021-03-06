// Room: /city/wudao4.c
// Date: Feb.28 1998 by Java
#include <ansi.h>;
inherit ROOM;
string look_gaoshi();
void create()
{
        set("short", HIR"武道场"NOR);
        set("long", @LONG
这里是三面环山，只有北面有条出口的一坪山间平地。山坡山阵阵松涛哗
哗作响，山脚下的平地绿草如茵，中间已经架起了个擂台，四周一溜过去搭着
凉棚，棚中桌椅杯盆俱全，看来比武大会快开始了。
    场中立有一面告示牌(gaoshi)。
LONG );
        set("outdoors", "city");
        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));
        set("exits", ([
                "leitai"      : __DIR__"leitai",
                "west"       : "/d/village/hsroad2",
                "southeast"   : __DIR__"wudao1",
                "southwest"   : __DIR__"wudao2",
        ]));
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        set("coor/x",10);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",0);
	setup(); 
        "/u/lzd/biwu_b"->foo();}

void init()
{
        this_player()->set_temp("view_leitai", 1);

        add_action("do_quit","quit");
        add_action("do_quit","exit");

        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
        add_action("do_quit","exert");
        add_action("do_quit","yun");
        add_action("do_quit","learn");
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna");
        add_action("do_quit","perform");
        add_action("do_quit","persuade");
        add_action("do_quit","quanjia");
        add_action("do_quit","practice");
        add_action("do_quit","lian");
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"，折腾个啥劲儿呀，专心看比武吧！\n");
        return 1;
}
int valid_leave(object me, string dir)
{
        if ((dir == "leitai") && (!me->query_temp("leitai_allow")) && !wizardp(me))
                return notify_fail("还没到你比武呢，别猴急上去。\n");
        if ((dir == "leitai") && (me->query_temp("leitai_allow")))
        {
                me->delete_temp("leitai_allow");
        }
        me->delete_temp("view_leitai");
        return ::valid_leave(me, dir);
}
string look_gaoshi()
{
        return 
HIR"\n\n                           
                   鹿鼎记  之  比武大会
\n"HIY"
第一、每月的十五日晚上十九时三十分举行比武大会。地点在扬州北门
      外武道场。
第二、比赛按年龄分组，每组设天下第一，第二称号。分组如下：
      幼年组 十五到十七岁 少年组 十八到二十岁 青年组 廿一到三十
      岁 壮年组 卅一到四十岁 盛年组 四十以上
      如果在一组内只有两人，他就直接获得该组第一、二名。
第三、比武实行淘汰制。预先分组淘汰。每轮实行三局两胜制，分别比
      赛第一兵器，拳脚和第二兵器，先胜两局者进入下一轮。幼儿组
      和少年组除了决赛外每轮只赛一场。
第四、为使天下第一名实相符，允许使用现行所有武功，允许perform，
      powerup，enforce，poison等。但roar由于严重影响比武秩序，
      因此谢绝使用。违者停赛。
第五、比赛时所用兵器和防具请在擂台上的兵器架上自行拿取，经研究，
      禁止使用自造兵器。禁止使用金刚罩、软猥甲、真丝宝甲外，禁
      止使用伤害力超过50的兵器如敖拜匕首，长歌剑，伏魔刀等。
第六、比赛时请注意言行，犯众怒者、违反现场巫师安排者，取消一年
      比赛资格。

  "HIG"                                      鹿鼎记  敬启
\n"NOR;
}

