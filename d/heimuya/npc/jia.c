#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("贾布", ({ "jia bu", "jia",}));
        set("nickname", "黄面尊者");        
        set("long", 
"他那一张瘦脸蜡也似黄，两边太阳穴
高高鼓起，便如藏了一杖核桃相似。\n");
        set("title",HIY"日月神教风雷堂香主"NOR);        
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        
        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 300);
        set("jiali", 30);
        set("combat_exp", 1000000);


        set_skill("sword", 70); 
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("unarmed",70);
        set_skill("whip", 70);
        set_skill("staff", 70);
        set_skill("blade", 70);
        set_skill("force",70);
        set_skill("literate",80);
        set_skill("tmzhang",70);
        set_skill("tmjian",70);
        set_skill("tmdao",70);        
        set_skill("rybian",70);
        set_skill("pmshenfa",70);
        set_skill("wuchang-zhang",70);
         set_skill("tmdafa",70);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        create_family("日月神教", 3, "弟子");
        setup();
 carry_object(__DIR__"obj/bi")->wield();
        carry_object(__DIR__"obj/cloth")->wear();        

}
int accept_object(object who, object ob)
{
  if (ob->query("name") == "向问天书信")
    {
      message_vision("贾布对$N说到：你既然有向左使的书信，还不快请进。\n",who);
      who->set_temp("hmy_enter",1);
      return 1;
    }
}
void attempt_apprentice(object ob)
{
        int exp;
        exp = (int)ob->query("combat_exp");
      
        if ((int)ob->query("shen") > 100) {
                command("say " + RANK_D->query_respect(ob) +
                        "我日月教乃邪魔外道，你们这些伪君子我们不耻为伍。");
                return;
        }
        command("say 哈哈！ 那我就收下你吧。");
        command("recruit " + ob->query("id"));
if( (string)ob->query("class") != "fighter")
ob->set("class", "fighter");
        if( exp <= 32000 ) {
                ob->set("title","日月神教教徒");
                return ;
        } else if ( exp <= 64000 ) {
                ob->set("title","日月神教副堂主");
                return ;
        } else if ( exp <= 128000 ) {
                ob->set("title","日月神教堂主");
                return ;
        } else if ( exp <= 256000 ) {
                ob->set("title","日月神教副坛主");
                return ;
        } else if ( exp <= 512000 ) {
                ob->set("title","日月神教坛主");
                return ;
        } else if ( exp <= 1024000 ) {
                ob->set("title","日月神教副舵主");
                return ;
        } else if ( exp <= 1536000 ) {
                ob->set("title","日月神教舵主");
                return ;
        } else if ( exp <= 2304000 ) {
                ob->set("title","日月神教护法");
                return ;
        } else if ( exp <= 3456000 ) {
                ob->set("title","日月神教大护法");
                return ;
        } else if ( exp <= 5187000 ) {
                ob->set("title","日月神教长老");
                return ;
        } else if ( exp <= 26244000 ) {
                ob->set("title","日月神教大长老");
                return ;
        } else
                ob->set("title","日月神教副教主");

//        ob->set("title","日月神教风雷堂第子");
}
     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="jia bu")
        {
                      command("chat "+ob->query("name")+"!黑木崖不要你这没用的东西。\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","日月神教" + RED + "弃徒" NOR);   
        }

}
