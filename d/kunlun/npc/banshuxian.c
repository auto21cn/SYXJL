// bashuxian.c (kunlun)

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
        set_name("班淑娴", ({ "ban shuxian", "ban" }));
        set("title", "昆仑派掌门夫人");
        set("long",
                "她就是昆仑派掌门、名扬江湖的铁琴先生何太冲的夫人。\n"
                "她是一个身材高大的半老女子，头发花白，双目含威，眉心间聚有煞气。\n");
        set("gender", "女性");
        set("unique", 1);
        set("age", 44);
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 46);
        set("int", 24);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 40000);

        set_skill("literate", 100);
        set_skill("force", 120);
        set_skill("xuantian-wuji", 120);
        set_skill("dodge", 110);
        set_skill("kunlun-shenfa", 120);
        set_skill("strike", 120);
        set_skill("kunlun-zhang", 120);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("liangyi-jian", 120);
        set_skill("throwing", 120);

        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shenfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");

        prepare_skill("strike", "kunlun-zhang");

        create_family("昆仑派", 4, "掌门夫人");
        set("class", "taoist");

                set("inquiry",
                ([
                        "秘籍" : (: ask_me :),
                ]));

        set("book_count", 1);
            set("no_get",1);
        setup();
        carry_object("/d/kunlun/obj/sword")->wield();
        carry_object("/d/kunlun/obj/cloth.c")->wear();
}
void kill_ob(object me)
{
         set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 800000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.juedi" :),
                (: exert_function, "recover" :),        }));
        command("hehe" + me->query("id"));
        ::kill_ob(me);
}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="ban shuxian")
       {
         command("chat "+ob->query("name")+"! 你杀人越货胡作非为，我昆仑派岂能容你，从今以后你好自为知吧。。。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","昆仑派" + RED + "弃徒" NOR);        }
}               

void attempt_apprentice(object ob)
{
         if((int)ob->query("shen")<0){
         command("say 我昆仑乃是堂堂名门正派，"+RANK_D->query_respect(ob)+
                                "的品德实在令人怀疑。");
         command("say "+RANK_D->query_respect(ob)+
                                "还是先回去多做点善事吧。");
         return;
         }

          if(ob->query("appren_hezudao", 1) == 1) {
         command("say 前辈怎敢开这等玩笑，真是折杀做晚辈的了。");
         return;
         }

         command("say 既然"+RANK_D->query_respect(ob)+
                                "慕昆仑派之名，千里而来，我昆仑派自当广纳天下英才。");
         command("recruit " + ob->query("id"));
       ob->set("title","昆仑派白衣剑士");
       ob->set("class","sworder");       

}

string ask_me()
{
                  mapping fam;
                  object ob;

                  if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "昆仑派")
                                         return RANK_D->query_respect(this_player()) +
                                         "与本派素无来往，不知此话从何谈起？";
                  if (query("book_count") < 1)
                                         return "你来晚了，本派真经已被你师兄拿走了。";
                  add("book_count", -1);
                  ob = new("/d/kunlun/obj/kl_book1.c");
                  ob->move(this_player());
                  return "先师曾传下来这本「两仪剑谱」，你拿回去好好钻研。";
}

void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "ban shuxian" || arg == "ban")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}

int accept_fight(object ob)
{
        object me  = this_object();
                
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

        if ( me->is_fighting()) return 0;

        if ( !present(ob, environment()) ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        
        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;

        if ( !present(ob, environment()) ) return 1; 

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if( me->is_fighting() ) 
        {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 )
                {
                   
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                       if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }

        return 1;  
}


