// duanwuwei.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("段无畏", ({ "duan wuwei", "duan" }));
        set("title", "镇南王府家臣");
        set("nickname", HIC "谁也不怕" NOR );
        set("long", "他是大理国镇南王府家臣。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 920);
        set("max_jing", 700);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 2000);

        set_skill("buddhism", 80);
        set_skill("force", 80);
        set_skill("dodge", 70);
        set_skill("sword", 70);
        set_skill("duanjia-jian", 70);
        set_skill("literate", 70);
        set_skill("parry", 70);
        set_skill("cuff", 70);
        set_skill("kurong-changong", 80);
        set_skill("jinyu-quan", 70);
        set_skill("tiannan-bufa", 70);
        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("cuff", "jinyu-quan");
        map_skill("sword", "duanjia-jian");
        map_skill("parry", "duanjia-jian");
        
        create_family("镇南王府",2, "家臣");

        set("inquiry", ([
                "秘籍" : (: ask_me :),
        ]));

        set("book_count", 1);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",20 );
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("score") < 40) {
                command("say 拜师？...你......？");
                command("say 我们王爷对侍卫的要求是很严格的，怎么能收留你这种邪派人士？你还是请回吧！");
                return;
        } 
        if ((int)ob->query("shen") < 0) {
                command("say 拜师？...你......？");
                command("say 我们王爷对侍卫的要求是很严格的，怎么能收留你这种邪派人士？你还是请回吧！");
                return;
        }        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
        ob->set("title", "大理镇南王府内院侍卫");
                ob->set("class", "guard");
}

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "镇南王府")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的剑法秘籍已经给别人了。";
        add("book_count", -1);
        ob = new(__DIR__"obj/sword_book");
        ob->move(this_player());
        return "好吧，这本「剑法要诀」你拿去好好保管，可千万别弄丢了！";
}

void init()
{
        object ob;

        ::init();

         ob = this_player();
              if((int)ob->query("score")<= -80&&ob->query("family/master_id")=="duan wuwei")
        {
                      command("chat "+ob->query("name")+"!你这种败类不配留在王府，给我滚出去。\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","镇南王府" + RED + "弃徒" NOR);   
        }
}
