// famu.c 伐木
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("伐木道长", ({ "famu daozhang", "famu" }));
        set("long", 
                "他是武当山的伐木道长, 专为庙中提供木材。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);

        set("combat_exp", 5000);
        set("score", 1000);

        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("blade", 60);
        set_skill("taiji-dao", 60);
        set_skill("taiji-quan", 60);
        set_skill("tiyunzong", 60);
        set_skill("taiji-shengong", 60);
        set_skill("taoism", 60);
        set_skill("literate", 60);

        map_skill("blade", "taiji-dao");

        create_family("武当派", 4, "弟子");

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();
}


void attempt_apprentice(object ob)
{


        if ( this_player()->query("class")=="bonze")
        {
                command("say 我派不收佛门弟子，" + RANK_D->query_respect(ob) + "请现还俗了在来。");
                return;
        }
        if ( this_player()->query("gender")=="无性")
        {
                 command("say 我派不收太监，" + RANK_D->query_respect(ob) + "请回吧。");
                return;
        }

        if ((string)ob->query("class") != "taoist")
        {
                command("say 我派只收道士，"+ RANK_D->query_respect(ob) + "是否愿意入我三清。");
                command("say 如果你决定了。请告诉我(decide)。");
                ob->set_temp("prepare/taoist", 1);
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，贫道就收下你了。");
        command("recruit " + ob->query("id"));
         command("chat " + ob->query("name") + "决定加入我武当派。");
               command("chat* hehe");
        this_player()->set("class", "taoist");
        if (this_player()->query("age")<20)
        {
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title","武当派道童");
        else
                this_player()->set("title","武当派小道姑");
        }
        else {
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title","武当派道士");
        else
                this_player()->set("title","武当派道姑");
        }
}

void init()
{

        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<0&&ob->query("family/master_id")=="famu daozhang")
        {
                  command("chat "+ob->query("name")+"!你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
                  command("expell "+ ob->query("id"));
                  this_player()->set("title","武当派" + RED + "弃徒" NOR);   
        }
}               


int do_decide()
{

        object ob=this_player();
        if( !this_player()->query_temp("prepare/taoist") )
                return 0;
        
        this_player()->delete_temp("prepare/taoist");

        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return 0;
        }
   
        this_player()->set("class", "taoist");
        command("say 好吧，贫道就收下你了。");
        command("say 如今你已经是三清弟子，以后做事可要好好做人，否则我派无法留你。");
        command("recruit " + ob->query("id"));
        if (this_player()->query("age")<20)
        {
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title","武当派道童");
        else
                this_player()->set("title","武当派小道姑");
        }
        else {
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title","武当派道士");
        else
                this_player()->set("title","武当派道姑");
        }
        return 1;
}


