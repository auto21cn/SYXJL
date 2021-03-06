// guxu.c 谷虚
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("谷虚道长", ({ "guxu daozhang", "guxu" }));
        set("long", 
                "他就是俞莲舟的弟子谷虚道长。\n"
                "他今年四十岁，主管武当派的俗事。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 30);

        set("combat_exp", 70000);
        set("score", 8500);

        set_skill("force", 60);
        set_skill("taiji-shengong", 40);
        set_skill("dodge", 70);
        set_skill("tiyunzong", 50);
        set_skill("unarmed", 60);
        set_skill("taiji-quan", 40);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("taiji-jian", 40);
        set_skill("taoism", 60);
        set_skill("literate", 80);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        create_family("武当派", 3, "弟子");
        set("class", "taoist");

        set("inquiry", 
                ([
                        "道德经" : (: ask_me :),
                ]));
                                
        set("book_count", 1);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
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
 

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "武当派")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的道德真经不在此处。";
        add("book_count", -1);
        ob = new("/d/wudang/obj/daodejing-ii");
        ob->move(this_player());
        return "好吧，这本「道德经」你拿回去好好钻研。";
}



void init()
{

        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="guxu daozhang")
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

