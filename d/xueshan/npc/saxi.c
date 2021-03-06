// 萨西活佛
// by csy

#include <ansi.h>

inherit NPC;
#include "/quest/quest.h"
void create()
{
        set_name("萨西活佛", ({ "saxi huofo", "huofo" }));
        set("long",@LONG
萨西活佛是雪山寺有道的高僧，对佛法有精深的研究。
他身穿一件黄色袈裟，头带僧帽。一副若有所思的样子。
在他这里可以领到师门的任务。
LONG
        );
        set("title", HIY "活佛" NOR);
        set("gender", "男性");
        set("nickname", HIC "寺内总管" NOR);
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2500);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 1200000);
        set("score", 100000);

        set_skill("mizong-xinfa", 120);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 100);
        set_skill("dodge", 120);
        set_skill("shenkong-xing", 100);
        set_skill("unarmed", 120);
        set_skill("yujiamu-quan", 100);
        set_skill("parry", 120);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 100);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");


        create_family("雪山寺", 3, "活佛");
        set("class", "bonze");

        setup();

        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
         add_money("gold",5);
}

