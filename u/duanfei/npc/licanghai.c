// licanghai.c 李沧海
// shilling 97.2

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("李沧海", ({ "li canghai", "canghai","li" }));
       set("title", "逍遥仙子");
       set("long", 
               "他就是逍遥派逍遥仙子、但是因为逍遥派属于一个在江湖中\n"
               "的秘密教派，所以他在江湖中不是很多人知道，但其实他的\n"
               "功夫却是。。。。他长的像林青霞。\n");
       set("gender", "女性");
       set("age", 35);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("str", 40);
       set("int", 40);
       set("con", 40);
       set("dex", 40);
       set("per", 40);
       
       set("max_qi", 5500);
       set("max_jing", 3000);
       set("neili", 3000);
       set("max_neili", 3000);
       set("jingli", 2000);
       set("max_jingli", 2000);
       set("jiali", 100);
       set("combat_exp", 10000000);
       set("score", 200000);

       set_skill("force", 200);
         set_skill("sword", 200);
         set_skill("strike", 200);
       set_skill("beiming-shengong", 200);
       set_skill("dodge", 200);
       set_skill("lingboweibu", 200);
       set_skill("unarmed", 200);
       set_skill("liuyang-zhang", 180);
       set_skill("parry", 200);
       set_skill("blade", 200);
       set_skill("ruyi-dao", 180);
       set_skill("zhemei-shou", 200);
         set_skill("chixin-qingchang-jian", 200);
     set_skill("hand", 200);
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

       create_family("逍遥派", 1, "逍遥仙子");
       set("class", "taoist");

       setup();
}


          

