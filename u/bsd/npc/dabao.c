// weixiao bao.c 韦小宝

#include <ansi.h>

inherit NPC;
void greeting(object ob);
void do_init();
void do_init1();
int ask_me();

void create()
{
        set("title",HIR"无所不知 无所不晓"NOR);
        set_name("韦小宝", ({"wei xiaobao","wei","bao","xiaobao"}));
        set("gender", "男性");
        set("age", 19);
        set("long", 
                "他就是康熙皇帝身旁的大红人--韦小宝,天地会\n"
                "青木堂香主。这人挺讲义气，可就是爱耍心眼.\n"
                "福大命大，一共娶了七个老婆。\n"
                "江湖上人称小色狼。\n");
        set("attitude", "peaceful");
        
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);

        set("chat_chance",9);
         set("es_msg", ({
                RED"韦小宝喃喃道：辣块妈妈，老子泡妞好好的，非有人说鹿鼎记没我就不是鹿鼎记，妞也泡不成了\n"NOR,
  HIG"韦小宝懒懒的笑着说：嘿嘿，不会玩MUD?看看主页http://202.102.230.25。\n"NOR,
                HIC"韦小宝道：经验小于50000?嘻嘻，去钓鱼呀，就在河边。\n"NOR,
                (: call_out("do_init1", 1) :),

        }));

        set("inquiry", ([
               "双儿" : HIM"我最喜欢的丫头，可温柔拉 \n"NOR,
               "阿珂" : WHT"我几个老婆里最漂亮的一个，我可追了她很长时间哦。\n"NOR,
               "帮助" : BLU"我可以告诉你几个门派的方向。请问：慕容，日月，杀手，浣花，万梅,昆仑。\n"NOR,
               "慕容" : HIB"姑苏慕容呀，在泰山以东，太湖那里坐船去。\n"NOR,
               "日月" : HIY"日月神教？好象是在泉州那边。\n"NOR,
               "杀手" : YEL"杀手楼!，杀手楼!，呵呵，去南门附近找找？\n"NOR,
               "浣花" : MAG"这个，嘿嘿！我记不清楚了，就记得是在日月后面的谷中。\n"NOR,
               "万梅" : GRN"西门吹雪的万梅山庄，我知道，就是从京城的西门一直朝西走。\n"NOR,
               "昆仑" : CYN"你还是去天山脚下看看去吧。\n"NOR,
               "鹿鼎记" : HIR"连鹿鼎记都不知道，还混个什么咯！\n"NOR,
               "韦春芳" :WHT"我老娘，问她赶嘛，是不是...嘿嘿..\n"NOR,       
                "礼品"  : HIR"你说元旦的礼品吗？礼品还正在筹备中，到99年1月1日零时，\n我就会发给你们的。不要着急嘛。\n"NOR, 
				"liwu" : (: ask_me :),
                "礼物" : (: ask_me :),
        ]));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 500);
        set("max_jing", 500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        
        set("combat_exp", 800000);
        set("score", 200000);

        set_skill("dodge", 100);                // 基本躲闪
        set_skill("shenxing-baibian", 100);
        set_skill("parry", 120);                // 基本招架
        
        map_skill("dodge", "shenxing-baibian");

       
        setup();
		
        
      carry_object("/d/city/obj/cloth")->wear();
}


void greeting(object ob)
{

        int combatexp = (int) (ob->query("combat_exp"));
        if( !ob || environment(ob) != environment() ) return;
        if(combatexp<1000)
        {
//         say(HIW"韦小宝懒懒的说道：新来的吧要帮助吗？\n"NOR);

        command("bow "+ob->query("id"));
        command("say 你不妨四处看看"HIY"look"NOR CYN",地上有什么东西你都可以捡起来"HIY"get"NOR CYN"收着。你
            可以先查查"HIY"i or inventory"NOR CYN"，看你现在身上有些什么。你要不时地
            查查"HIY"hp"NOR CYN"你的身体状态，要是饿了或渴了就去找些吃的喝的吧。至于
            各种指令的具体用法可以参看 "HIY"help commands"NOR CYN"。"NOR);

        return;
        }
        else if((combatexp<10000)&&(combatexp>1000))
        {   say(HIY"韦小宝笑嘻嘻的说：这位"+RANK_D->query_respect(ob)+
               ",玩MUD已经入门了，要是还有问题看主页去吧。\n"NOR);
        return;
        }
        else if((combatexp<100000)&&(combatexp>10000))
        {   say(HIR"韦小宝拱手道：这位"+RANK_D->query_respect(ob)+
               ",要勤练武功哦，好在江湖上有立足之地。\n"NOR);
        return;
        }
        else if((combatexp<500000)&&(combatexp>100000))
        {   say(HIM"韦小宝道：哇！这位"+RANK_D->query_respect(ob)+
               "可是我们鹿鼎记的主力军哦。\n"NOR);
        return;
        }
        else
        {   say(HIW"韦小宝狂跳起来，快看，这位"+RANK_D->query_respect(ob)+
               "是我们鹿鼎记的超级高手。\n"NOR);
        return;
        }
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
int ask_me()
{
  object ob=this_player();
  if( ob->query("shizhe") )
    {command("smile "+ob->query("id"));
     command("say 这位"+RANK_D->query_respect(ob)+"已经拿过我给你的礼物哦！");
     return 1;
    }
    ob->add("combat_exp",20000);
ob->add("potential",10000);
  ob->set("shizhe",1);

  command("addoil "+ob->query("id"));
  command("ldj "+ob->name(1)+"得到了我给帮助，开始行走江湖！");
command("es "+ob->name(1)+"得到了我给帮助，开始行走"+HIY+"鹿鼎记随缘站"HIR"(202.102.230.25 5555)"+NOR+"");
  return 1;
}
