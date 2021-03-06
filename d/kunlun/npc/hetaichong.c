// hetaichong.c (kunlun)

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_ding();

void create()
{
        set_name("何太冲", ({ "he taichong", "he" }));
        set("title", "昆仑派掌门");
        set("nickname", HIW"铁琴先生"NOR);
        set("long",
                "他就是昆仑派掌门、名扬江湖的铁琴先生何太冲。\n"
                "虽然年纪已大，但仍然看得出他年轻时英俊潇洒。\n");
        set("gender", "男性");
        set("unique", 1);
        set("age", 40);
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1300);
        set("max_neili", 1300);
        set("jiali", 50);
        set("combat_exp", 700000);
        set("score", 40000);

        set_skill("literate", 100);
        set_skill("force", 120);
        set_skill("xuantian-wuji", 140);
        set_skill("dodge", 120);
        set_skill("kunlun-shenfa", 120);
        set_skill("strike", 140);
        set_skill("kunlun-zhang", 140);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("liangyi-jian", 130);
        set_skill("throwing", 100);

        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shenfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");

        prepare_skill("strike", "kunlun-zhang");

        create_family("昆仑派", 4, "掌门人");
        set("class", "taoist");

        set("inquiry",
                ([
                        "心法" : (: ask_me :),
                        "苏习之" : (: ask_ding :),
                ]));

        set("book_count", 1);
        set("ding_count", 5);

        setup();
        carry_object("/d/kunlun/obj/sword")->wield();
        carry_object("/d/kunlun/obj/cloth")->wear();
}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="he taichong")
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
                                "还是先回去做点善事吧。");
         return;
         }

          if(ob->query("appren_hezudao", 1) == 1) {
         command("say 前辈怎敢开这等玩笑，真是折杀做晚辈的了。");
         return;
         }

         command("say 好吧，我便收下你，只是你投入我门下之后，须得安心学艺。");
         command("recruit " + ob->query("id")); 
       ob->set("title","昆仑派蓝衣剑士");
       ob->set("class","sworder");       }


string ask_me()
{
                  mapping fam;
                  object ob;

                  if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "昆仑派")
                                         return RANK_D->query_respect(this_player()) +
                                         "与本派素无来往，不知此话从何谈起？";
                  if (query("book_count") < 1)
                                         return "你来晚了，本派心经已被你师兄拿走了。";
                  add("book_count", -1);
                  ob = new("/d/kunlun/obj/force-book.c");
                  ob->move(this_player());
                  return "我这里有本「内功心法」，是有关吐呐吸气的，你拿回去好好钻研。";
}

string ask_ding()
{
                  mapping fam;
                  object ob;

                  if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "昆仑派")
                                         return RANK_D->query_respect(this_player()) +
                                         "与本派素无来往，不知此话从何谈起？";
                  if (query("ding_count") < 1)
                                         return "丧门钉已给了我派去追杀苏习之的人，你就不用去了。";
                  add("ding_count", -1);
                  ob = new("/d/kunlun/obj/sangmending.c");
                  ob->move(this_player());
                  return "你如此自愿为师门效力，不枉我平时一番栽培，这枚丧门钉你就拿去吧。";
}

