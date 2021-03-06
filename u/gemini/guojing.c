// guojing.c 郭靖
// Write by yanzi@J.H.Y.J

#include <ansi.h>

inherit NPC;
string ask_job();
int job_over(string arg);
void create()
{
        set_name("郭靖", ({"guo jing", "guo", "jing"}));
        set("nickname", HIY"北侠"NOR);
        set("gender", "男性");
        set("age", 25);
        set("long", 
                "他就是人称北侠的郭靖，既是蒙古成吉思汗的金刀驸马，又是\n"
                "江南七怪、全真派马钰道长、「北丐」洪七公和「老顽童」周\n"
                "伯通等人的徒弟，身兼数门武功。\n"
                "他身着一件灰色长袍，体态魁梧，敦厚的面目中透出一股威严\n"
                "令人不由得产生一股钦佩之情。\n");
        set("attitude", "peaceful");
        
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);
        set("per", 22);

        set("chat_chance", 1);
        set("chat_msg", ({
                "郭靖叹了口气道：“蒙古兵久攻襄阳不下，一定会再出诡计，蓉儿又不在身边，这....\n",
                "郭靖说道：“华筝公主近来不知可好，抽空一定要回大漠去看看她。\n",
                (: random_move :),
        }));

        set("inquiry", ([
                "工作" : (: ask_job :),
                "job"  : (: ask_job :),
                "黄蓉" : "蓉儿是我的爱妻，你问她做甚？\n",
                "丐帮" : "东北西北东西北。\n",
                "拜师" : "现在蒙古人围攻襄阳，我哪有心情收徒啊！\n",
        ]));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        
        set("combat_exp", 1800000);
        set("score", 200000);
         
        set_skill("force", 250);                // 基本内功
        set_skill("huntian-qigong", 230);       // 混天气功
        set_skill("unarmed", 220);              // 基本拳脚
        set_skill("xianglong-zhang", 200);      // 降龙十八掌
        set_skill("dodge", 200);                // 基本躲闪
        set_skill("xiaoyaoyou", 180);            // 逍遥游
        set_skill("parry", 220);                // 基本招架
        
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");
        
        setup();
        
   this_player()->carry_object("/clone/misc/cloth")->wear();
}


void init()
{
        add_action("job_over","task");
}


string ask_job()
{
        object *ene;
        object me = this_player();

        if(is_fighting()) 
        {
                ene=query_enemy();
                
                if(sizeof(ene)>1) return "“请"+RANK_D->query_respect(me)+"稍等片刻，我先和这"+sizeof(ene)+"位高手切磋几下！”\n";
                if(sizeof(ene)==1) return "“请"+RANK_D->query_respect(me)+"稍等片刻，我先和"+ene[0]->name()+"切磋几下！”\n";
        }



        if(me->query_temp("mark/job_shadi")>0 ) return "“"+RANK_D->query_respect(me)+"不是已有任务了吗！”\n";

/*        if((int)me->query("shen") < 0) return "“"+RANK_D->query_respect(me)+"心术不正，我们不欢迎！”\n";
*/     
        if ((int)me->query("combat_exp")<100000) return "“"+RANK_D->query_respect(me)+"手无缚鸡之力，还是别领任务的为好！”\n";
        if (me->query("shen")>0)
        {
        switch( random(2) ) {
                case 0:
                        me->set_temp("mark/job_shadi",1);
                        me->set_temp("carry_location","northgate1");            
                return "“现在蒙古靼子侵犯中原，这位"+RANK_D->query_respect(me)+"去玄武内门帮助宋军守城吧。";

                       break;
                case 1:
                        me->set_temp("mark/job_shadi",2);
                        me->set_temp("carry_location","northgate1");            
                return "“现在蒙古靼子侵犯中原，这位"+RANK_D->query_respect(me)+"去青龙内门帮助宋军守城吧。";

                       break;
                }       
        }
        else
        {
        switch( random(2) ) {
                case 0:
                        me->set_temp("mark/job_shadi",3);
                        me->set_temp("carry_location","southgate1");
                return "“现在蒙古靼子侵犯中原，这位"+RANK_D->query_respect(me)+"去朱雀内门帮助宋军守城吧。";

                       break;
                case 1:
                        me->set_temp("mark/job_shadi",4);
                        me->set_temp("carry_location","southgate1");
                return "“现在蒙古靼子侵犯中原，这位"+RANK_D->query_respect(me)+"去白虎内门帮助宋军守城吧。";

                       break;
                }
        }
}

int job_over(string arg)
{
        int job_pot,job_exp;
        object me = this_player();

        if(!arg) return 1;

        if(arg!="over") return 1;
        if(me->query_temp("help_killed")>0)
        {
                message_vision(CYN "$N拍了拍$n的肩膀说道：“"+RANK_D->query_respect(me)+"，为国杀敌，不错不错！”\n" NOR, this_object(), me);
                job_exp=((int)me->query_temp("killed_mgb"))*30;
                  job_pot=job_exp+400+random(200);
                  job_exp=job_exp+800+random(200);
                me->add("combat_exp", job_exp);
                me->add("potential",job_pot);
                me->delete_temp("killed_mgb"); 
		me->delete_temp("help_killed");//改lks加exp 的bug (不停task over)      
                return 1;
        }
                
        if(me->query_temp("mark/job_shadi")==0)
        {
                message_vision(CYN"$N瞧了$n一眼:“没任务还什么完成不完成。”\n",this_object(),me);
                return 1;
        }
        
        if(me->query_temp("job_over")==0)
        {
                message_vision(CYN"$N瞧了$n一眼:“任务还没完成。”\n"NOR,this_object(),me);
                return 1;
        }
       if(me->query_temp("killed_mgb")<1)
       {
                  message_vision(CYN"$N瞧了$n一眼:“一个敌人都没杀掉，你还来领赏？。”\n"NOR,this_object(),me);
         me->delete_temp("job_over");
         me->delete_temp("mark/job_shadi");
                  return 1;
          }

        message_vision(CYN "$N对$n说道：“"+RANK_D->query_respect(me)+"辛苦了，去休息一下吧！”\n" NOR, this_object(), me);
        me->delete_temp("job_over");
        me->delete_temp("mark/job_shadi");
        job_exp=((int)me->query_temp("killed_mgb"))*30;
          job_pot=job_exp+800+random(200);
          job_exp=job_exp+2000+random(400);
        me->add("combat_exp", job_exp);
        me->add("potential",job_pot);
        me->delete_temp("killed_mgb");        
        return 1;

}
