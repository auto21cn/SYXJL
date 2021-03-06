#include <ansi.h>
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("归宝", ({"gui bao",   "bao",}));
        set("long",
                "他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
                "太阳穴高高鼓起，似乎身怀绝世武功。\n"
        );

//      set("nickname", "");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 50);
        set("shen_type", 1);
        set("str", 26);
        set("int", 26);
        set("con", 26);
        set("dex", 28);
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("combat_exp", 1300000);
        set("score", 10000);

        set_skill("force", 180);
        set_skill("kurong-changong", 180);
        set_skill("dodge", 150);
        set_skill("tiannan-bufa", 150);
        set_skill("finger", 150);
        set_skill("sword", 150);
        set_skill("unarmed", 150);
        set_skill("jinyu-quan", 150);
        set_skill("yiyang-zhi", 150);
        set_skill("parry", 150);
        set_skill("buddhism", 200);
        set_skill("literate", 120);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("finger", "yiyang-zhi");
        map_skill("parry", "yiyang-zhi");
        map_skill("unarmed", "jinyu-quan");

        prepare_skill("finger", "yiyang-zhi");

        create_family("天龙寺", 7, "弟子");

        setup();


}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("score") < 0 && ob->query("family/master_id")=="gui bao")
        {
                command("chat "+ob->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","天龙寺" + RED + "弃徒" NOR);
        }
}

void attempt_apprentice(object ob)
{
        string name,new_name;  
        if((string)this_player()->query("family/master_id")!="xing lei" )
        {       
                command("say 以你现在的修为还无法继承我的衣钵。\n");
                command("say 你还是先找行雷师侄学习吧。\n");       
                return ;
        }
        if ((int)ob->query_skill("kurong-changong", 1) < 150) {
                command("say 我天龙寺着重内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在枯荣禅功上多下点功夫？");
                return ;
        }
        if( (string)ob->query("class")!="bonze" )
        {
                command("say 阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请先行受戒。\n");
                return ;
        }
        if ((int)ob->query("shen") <50000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }
        if ((int)ob->query("score") <350) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }
        
        command("chat 好啦,起来...你今后可得多多用功");
        command("partytell 老僧又收一徒弟,大家以后好好切磋。");
        command("recruit " + ob->query("id"));
        name = ob->query("name");
        new_name = "行" + name[2..3];
        ob->set("name", new_name);
        ob->set("family/generation", 8);
        command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为天龙寺行字辈弟子 !");
        return ;

}
