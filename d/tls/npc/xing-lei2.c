#include <ansi.h>
inherit NPC;
inherit F_MASTER;
//string ask_for_join();

void create()
{
        set_name("行雷", ({"xing lei","lei",}));
        set("long",
                "他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
                "刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
        );


        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 40);
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 700);
        set("max_jing", 400);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("score", 2000);

        set_skill("force", 130);
        set_skill("kurong-changong", 150);
        set_skill("dodge",130);
        set_skill("tiannan-bufa", 130);
        set_skill("jinyu-quan", 130);
        set_skill("unarmed", 130);
        set_skill("parry", 130);
        set_skill("buddhism", 170);
        set_skill("literate", 100);
        set_skill("finger", 130); 
        set_skill("sword", 140);
        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("unarmed", "jinyu-quan");
        map_skill("parry", "jinyu-quan");

        prepare_skill("unarmed", "jinyu-quan");

        create_family("天龙寺", 8, "弟子");

        setup();
}

void init()
{
        object me;

        ::init();
        
        me = this_player();

        if((int)me->query("score") < 0 && me->query("family/master_id")=="xing lei")
        {
                command("chat "+me->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                command("expell "+ me->query("id"));
                this_player()->set("title","天龙寺" + RED + "弃徒" NOR);
        }
}

void attempt_apprentice(object ob)
{        
        string name,new_name;
        if((!ob->query("family") || ob->query("family")["family_name"]!="镇南王府"))
        {
                command("say 本寺是大理皇家寺院，收徒是很严格的。");
                command("say 你和本寺毫无关系，此话从和说起？");
                
                return ;
        } 
        if((int)ob->query("shen") <30000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面,你是否还做得不够？");
                return ;
        }
        if((int)ob->query("score") <250) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面,你是否还做得不够？");
                return;
        }
         if((string)this_player()->query("family/master_id")!="duan zhengchun" )
        {
                command("say 没有镇南王的同意贫僧怎敢留你？\n");
                command("say 你先回去得到王爷的同意再来吧。\n");        
                return ;
        }
                command("chat 好啦,起来...你今后可得多多用功");
                command("party 老僧又收一徒弟,大家以后好好切磋。");
                command("recruit " + ob->query("id"));
                ob->set("score", (int)ob->query("score")+300);
                name = ob->query("name");     
                new_name = "无" + name[2..3];
                ob->set("class", "bonze");
                ob->set("name", new_name);
                ob->set("family/generation", 9);
                command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为天龙寺无字辈弟子 !");
                return; 
        if((!ob->query("family") || ob->query("family")["family_name"]!="天龙寺"))
        {                        ob->add("betrayer", -1);
                return ;
        } 
}
