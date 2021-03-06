// liqiushui.c 李秋水
// shilling 97.2

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("李秋水", ({ "li qiushui", "qiushui","li" }));
       set("title", "逍遥圣女");
       set("long", 
               "他就是逍遥派逍遥圣女、但是因为逍遥派属于一个在江湖中\n"
               "的秘密教派，所以他在江湖中不是很多人知道，但其实他的\n"
               "功夫却是。。。。他长的像张敏。\n");
       set("gender", "女性");
       set("age", 35);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("str", 40);
       set("int", 40);
       set("con", 40);
       set("dex", 40);
       set("per", 29);
       
       set("max_qi", 5500);
       set("max_jing", 3000);
       set("neili", 3000);
       set("max_neili", 3000);
       set("jingli", 2000);
       set("max_jingli", 2000);
       set("jiali", 100);
       set("combat_exp", 8000000);
       set("score", 200000);

       set_skill("force", 180);
         set_skill("sword", 180);
         set_skill("strike", 180);
       set_skill("beiming-shengong", 180);
       set_skill("dodge", 180);
       set_skill("lingboweibu", 180);
       set_skill("unarmed", 180);
       set_skill("liuyang-zhang", 180);
       set_skill("parry", 180);
       set_skill("blade", 180);
       set_skill("ruyi-dao", 180);
       set_skill("zhemei-shou", 180);
         set_skill("chixin-qingchang-jian", 180);
     set_skill("hand", 180);
       set_skill("literate", 120);

       map_skill("force", "beiming-shengong");
       map_skill("dodge", "lingboweibu");
       map_skill("unarmed", "zhemei-shou");
         map_skill("sword", "chixin-qingchang-jian");
     map_skill("strike", "liuyang-zhang");
       map_skill("parry", "ruyi-dao");
       map_skill("blade", "ruyi-dao");

//     prepare_skill("hand","zhemei-shou");
//     prepare_skill("strike","liuyang-zhang");

       create_family("逍遥派", 1, "逍遥圣女");
       set("class", "taoist");

       setup();
}


          

