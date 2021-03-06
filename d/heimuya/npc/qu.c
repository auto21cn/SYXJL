#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        set_name("曲洋", ({ "qu yang", "qu",}));
        set("long", 
"此人乃日月神教十大长老之一，武功深不可测。
而他更痴迷于琴曲之道，琴艺可以称得上是当世第一人.\n
");
        set("title",HIM"日月神教长老"NOR);         
       set("gender", "无性");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
       
        set("max_qi", 700);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("shen", -1000);


       
        set_skill("tmzhang",100);
        set_skill("tmjian",100);
        set_skill("tmdao",100);        
        set_skill("pmshenfa",100);
         set_skill("tmdafa",100);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        create_family("日月神教",3,"长老");

        set("inquiry", ([
                "笑傲江湖曲" : (: ask_me :),
        ]));
set("book_count", 1);
        setup();
 carry_object(__DIR__"obj/bi")->wield();
        carry_object(__DIR__"obj/cloth")->wear();        

}

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
                return RANK_D->query_respect(this_player()) + 
                "与本教素无往来，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "笑傲江湖曲已赠知音人，你来晚一步了。";
        add("book_count", -1);
        ob = new(__DIR__"obj/xo");
        ob->move(this_player());
        return "宝剑赠侠客，红粉配佳人，这本笑傲江湖曲就送给你吧，
       只盼你是个真正的知音人。";
}
