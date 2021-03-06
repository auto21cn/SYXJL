#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("童百熊", ({ "tong baixiong", "tong",}));
        set("long", 
"一名须法俱白的老者，身材魁梧，双目炯炯
有神，他掌管着日月教风雷堂，负责着教中
所有对外的事务。\n");
        set("title",HIY"日月神教风雷堂主"NOR);        
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 1200);
        set("max_jing", 300);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 85);
        set("combat_exp", 1000000);
        set("shen", -1);


       set_skill("sword", 140); 
        set_skill("parry", 140);
        set_skill("dodge", 140);
        set_skill("unarmed", 140);
        set_skill("force",140);
        set_skill("tmzhang",140);
        set_skill("strike", 140);
        set_skill("tmjian",140);
        set_skill("literate", 70);
        set_skill("blade", 140);
        set_skill("pmshenfa",140);
         set_skill("tmdafa",140);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        create_family("日月神教",3,"弟子");
        setup();
 carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();        
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("parry") < 101) {
                command("say 习武之人，最主要练好基本功。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在基本招架上多下点功夫？");
                return;
}
         if (ob->query_dex() < 26) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;
        }
        command("say 哈哈！ 那我就收下你吧。");
        command("recruit " + ob->query("id"));
        ob->set("title","日月神教风雷堂第子");
}
     void init()
{
        object ob;

        ::init();

        ob = this_player();
           if((int)ob->query("shen") > 1000 &&ob->query("family/master_id")=="tong baixiong")
        {
                      command("chat "+ob->query("name")+"!黑木崖不要你这没用的东西。\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","日月神教" + RED + "弃徒" NOR);   
        }

}
