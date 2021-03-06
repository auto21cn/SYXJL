// Date: CSY 98/08/14

inherit NPC;

string ask_for_huansu();
void create()
{
        set_name("还俗僧", ({
                "huansu seng",
                "huansu",
                "seng",
        }));
        set("long",
                "他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含\n"
                "着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺，你可以向他打听还俗的事。\n"
        );

        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 30);
        set("shen_type", 1);
        set("str", 23);
        set("int", 21);
        set("con", 18);
        set("dex", 22);
        set("max_qi", 350);
        set("max_jing", 200);
        set("neili", 350);
        set("max_neili", 350);
        set("jiali", 30);
        set("combat_exp", 5000);
        set("score", 100); 

        set("inquiry", ([
        "还俗" : (: ask_for_huansu :),
        ]) );

        set_skill("force", 30);
        set_skill("hunyuan-yiqi", 30);
        set_skill("dodge", 30);
        set_skill("shaolin-shenfa", 30);
        set_skill("claw", 35);
        set_skill("longzhua-gong", 35);
        set_skill("parry", 30);
        set_skill("buddhism", 30);
        set_skill("literate", 30);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("claw", "longzhua-gong");
        map_skill("parry", "longzhua-gong");

        prepare_skill("claw", "longzhua-gong");

        create_family("少林派", 40, "弟子");

        setup();

        carry_object("/d/shaolin/obj/qing-cloth")->wear();
} 
void init()
{
        add_action("do_huansu", "huansu");
}

string ask_for_huansu()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "少林派")) 
        return ("你和少林没有渊源，贫僧不敢给你还俗。\n");
    if( (string)me->query("class")!="bonze" )
        return "阿弥陀佛！出家人不打诳语。你已经是俗家人了。\n";
    me->set_temp("pending/quit_bonze", 1);
        command ("say 阿弥陀佛！善哉！善哉！一入俗世，万劫不复。");
        command ("say 还望"+RANK_D->query_respect(me)+"三思，若已决定，便请脱袍还俗(huansu)并接受惩罚。"); 
        return "当然，如果"+RANK_D->query_respect(me)+"不愿还俗的话，就请安心在此修炼吧。\n";
}

int do_huansu()
{ 
   if(this_player()->query_temp("pending/leave_bonze")) 
     return 0;
     message_vision("$N答道：弟子愿意。\n\n", this_player());
     command("say 既是你与佛门无缘，你便下山去吧！\n");
     this_player()->set("combat_exp", this_player()->query("combat_exp")*90/100);
     this_player()->delete("class");
     this_player()->delete_skill("hunyuan-yiqi");
     this_player()->delete("family");
     this_player()->set("title", "普通百姓");
     command("say 从今以後你和少林寺再无瓜葛。");
     command("sigh");
     this_player()->delete_temp("pending/leave_bonze");
     command("say 江湖风波，善恶无形，施主好自为之。。。\n");
     this_player()->save();
     return 1;
}

