//wangchuyi.c  王处一
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("王处一", ({"master wang","wang chuyi", "wang", "chuyi"}));
        set("nickname",HIC"玉阳子"NOR);
        set("gender", "男性");
        set("age", 48);
        set("long",
             "他长眉秀目，颏下疏疏的三丛黑须，似是一个十分着重修饰的羽士。\n"
                "他就是独足站立凭临万丈深谷，使一招“风摆荷叶”，威镇天下的铁脚仙玉阳子。\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 32);
        set("int", 29);
        set("con", 32);
        set("dex", 29);

        set("chat_chance", 1);
        set("chat_msg", ({
                "王处一说道：“全真教威震天下，盛名长久不衰。”\n",
                "王处一叹了口气道：“我门下第子没一个是可造之才，这可如何是好。\n",
             "王处一喃喃道：“天罡北斗阵是全真教中最上乘的玄功，威不可当。”\n",
//              (: random_move :),
        }));
        set("inquiry", ([
                "天罡北斗阵":"“此阵需集七人之力，和而为一，可天下无敌。”\n",
        ]));

        set("qi", 1600);
        set("max_qi", 1600);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 120);
        
        set("combat_exp", 2000000);
        set("score", 200000);
         
        set_skill("force", 190);             // 基本内功
        set_skill("tiangang-zhengqi", 190);    //天罡正气
        set_skill("unarmed", 200);           // 基本拳脚
        set_skill("kongming-quan", 180);    //空明拳 
        set_skill("dodge", 200);             // 基本躲闪
        set_skill("qixing-huanwei", 200);       //七星换位
        set_skill("parry", 180);             // 基本招架
        set_skill("sword", 190);             // 基本剑法
        set_skill("quanzhen-jianfa",190);        //天罡剑法 
        set_skill("taoism", 190);            //道学心法  
        set_skill("literate",190);           //读书写字
        set_skill("qixing-array",210);

        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongmingquan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("全真教", 2, "长老");
        

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );


        setup();
        
        carry_object("/d/quanzhen/obj/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();
}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="master wang")
       {
         command("chat "+ob->query("name")+"! 你杀人越货胡作非为，我教岂能容你，从今以后你好自为知吧。。。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","全真教" + RED + "弃徒" NOR);        }
}               

void attempt_apprentice(object ob)
{

        object me  = this_object();
        mapping ob_fam  = ob->query("family");
        mapping my_fam  = me->query("family");

        
        if ( ob_fam["generation"] <= my_fam["generation"] )
        {
                command("say " + RANK_D->query_respect(ob) + "，贫道哪里敢当 !");
                return;
        }


        if ((int)ob->query_str() < 28 || (int)ob->query_con() < 28) {
                command("say 当道士需要能吃苦耐劳，六根清静依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当道士？");
                return;
        }
        if ((string)ob->query("family/family_name") != "" &&
            (string)ob->query("family/family_name") != "全真教") {
                command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜本真人呢？");
                return;
        }
       if ((int)ob->query_skill("tiangang-zhengqi", 1) <80) {
                command("say 我全真教乃内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在天罡正气上多下点功夫？");
                return;
       }
       if ((int)ob->query_skill("qixing-huanwei", 1) < 100) {
                command("say 我本身以轻功见长，最看中轻功。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在七星换位上多下点功夫？");
                return;
       }
       command("smile");  
       command("say 好吧，看来你还是可造之才，贫道就收下你了。");
       command("recruit " + ob->query("id")); 
       ob->set("title","全真教玉阳真人爱徒");
       ob->set("class","sworder");               
}


