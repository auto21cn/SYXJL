#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name(MAG"风雨云"NOR, ({ "fengyuyun", "wry" }));
        set("nickname", HIG"风"HIW"雨"HIB"云"HIY"仙" NOR);
        set("long", 
                "她就是世间传闻的仙子，闻风听雨看云楼的祖师婆婆。\n");
        set("gender", "女性");
        set("age", 80);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set_skill("sword", 500);       
        set_skill("force", 500);
        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 100);
        set("combat_exp", 2000000);
        set("score", 500000); 

        create_family("闻风听雨看云楼", 1, "开山祖师");
        set("class", "sword");

        set("chat_chance_combat", 40);
        set("chat_msg", ({
             "风雨云叹了口气道：“不知道仙师小娴现在何方\n",
             "风雨云说道：“不知闻风听雨看云楼近来可好？有空要去看看才是。\n",
                (: random_move :)
 }));       
        set("inquiry", ([
                "闻风听雨看云楼" : "小女子就是此楼的开山祖师！\n",
                "拜师" : "你与我派好无渊源，何谈拜师？！\n",
        ])); 
       setup();
        carry_object("/u/wry/obj/wrysword")->wield();
        carry_object("/clone/misc/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="闻风听雨看云楼" ) 
       {        command("say 我虽成仙，可也算闻风听雨看云楼的一代掌门。");
                command("say " + RANK_D->query_respect(ob) + "若想拜我须先入我楼。"); 
                return;
        }

        command("chat*jump");
        command("chat 我又多了一个弟子耶！！！！");
        command("chat* pat " + ob->query("id"));
        
        command("recruit " + ob->query("id"));
        ob->set("title",HIW"闻风听雨看云楼"MAG"仙子"HIW"亲授弟子"NOR);

}

int accept_fight(object me, object ob)
{   ob=this_player();
   command("say " + RANK_D->query_rude(ob) + "杀心太重，恐祸不久已！\n");
   return 0;
}

void die()
{

        if( environment() ) {
        command("sigh");
        }

        destruct(this_object());
}




