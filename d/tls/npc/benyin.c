#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();
void create()
{
        set_name("本因", ({ "ben yin","yin"}) );
        set("long",
                "他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
                "太阳穴高高鼓起，似乎身怀绝世武功。\n"
            );
        set("gender", "男性" );
        set("title", "天龙寺主持");
        set("class", "bonze");
        set("age", 65);
        set("shen_type", 1);
        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("qi", 4500);
        set("max_qi", 4500);
        set("jing", 2500);
        set("max_jing", 2500);
        set("neili",8000);
        set("max_neili", 8000);
        set("jiali", 170);
        set("combat_exp", 1700000);
        set("score", 1000000);

        set_skill("force", 200);
        set_skill("kurong-changong", 200);
        set_skill("dodge", 180);
        set_skill("tiannan-bufa", 180);
        set_skill("parry", 180);
        set_skill("finger", 180);
        set_skill("sword", 180);
        set_skill("yiyang-zhi", 180);
        set_skill("duanjia-jian", 180);
        set_skill("buddhism", 250);
        set_skill("literate", 150);
        set_skill("sword", 180);
        set_skill("duanjia-jian", 180);
         
        map_skill("sword", "duanjia-jian");
        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("parry", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger","yiyang-zhi");   
        create_family("天龙寺", 6, "掌门");
        set("inquiry" ,([
        "段家剑法" : "“段家剑法是一灯祖师为了弥补我寺弟子武功在兵器上的不足而特别创造的。”\n", 
        "南帝" : "“南帝就是本寺开山主师，当年和王重阳和切搓武功后就创立了本寺。”\n",  
        "六脉神剑谱" : "“施主不会是打什么主意吧？”\n",
        "六脉神剑" :  "“此乃本寺绝顶武学,施主也有意于此?”\n",
        ]));
        set("chat_chance_combat", 60); 
        set("chat_msg_combat", ({
                  (: perform_action, "sword.tun" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "finger.yizhi" :),
                (: exert_function, "recover" :),
              })   );
        setup();
        carry_object(__DIR__"obj/sengxie")->wear();
        carry_object(__DIR__"obj/sengrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("score") < 0 && ob->query("family/master_id")=="ben yin")
        {
                command("chat "+ob->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","天龙寺" + RED + "弃徒" NOR);
        }
}

void attempt_apprentice(object ob)
{
        string name,new_name; 
             if ((int)ob->query_skill("kurong-changong", 1) < 180) {
                command("say 我天龙寺着重内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在枯荣禅功上多下点功夫？");
                return ;
        }
        if ((string)ob->query("class") != "bonze") {
                command("say 老衲不收俗家弟子，施主请回吧。");
                
                return ;
        }
        if ((int)ob->query("shen") <70000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }
        if ((int)ob->query("score") <400) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }
        if ((int)ob->query_skill("buddhism", 1) < 200) {
                command("say 悟禅之人，德义为先，我天龙寺乃佛门嫡传，你先学好佛家的经书吧。");
                command("say 在禅宗心法方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }

        command("say 好啦,起来...你今后可得多多用功");
        command("party 老僧又收一徒弟,大家以后好好切磋。");
        command("recruit " + ob->query("id"));
        name = ob->query("name");     
        new_name = "归" + name[2..3];
        ob->set("name", new_name);
        ob->set("family/generation", 7);
        command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为天龙寺归字辈弟子 !");
                return ;
}
