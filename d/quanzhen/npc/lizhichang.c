//李志常 

#include <ansi.h> 
inherit NPC;
#include "/quest/quest.h"
void consider();

void create()
{
        set_name("李志常", ({"master li","li zhichang", "li", "zhichang"}));
        set("master", "王处一");
        set("gender", "男性");
        set("age", 30);
        set("long",
             "他容貌不算俊，但却十分英挺，高高的个子，体格很健壮。\n"
             "在他这里你可以领到师门的任务。\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 21);
        set("int", 19);
        set("con", 21);
        set("dex", 19); 
        set("per", 20);
        set("chat_chance", 1);
        set("chat_msg", ({
            "李志常说道：“杨过这小王八蛋差点害死我师兄，活死人墓的玉蜂真厉害。”\n",
     "李志常喃喃道：“只要找到茯苓和龟甲就可以到掌药道长那里去配药了。”\n",
     "李志长神秘兮兮的对你说：“龟茯膏可是我全真教的至宝呀！”\n",
//        (: random_move :),
        }));

        set("qi", 850);
        set("max_qi", 850);
        set("jing", 850);
        set("max_jing",850);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        
        set("combat_exp", 800000);
        set("score", 80000);
 
        set_skill("force", 120);             // 基本内功
        set_skill("tiangang-zhengqi", 120);    //天罡正气
        set_skill("unarmed", 120);           // 基本拳脚
        set_skill("kongming-quan", 120);     //空明拳 
        set_skill("dodge",130);              // 基本躲闪
        set_skill("qixing-huanwei", 130);        //七星换位
        set_skill("parry", 120);             // 基本招架
        set_skill("sword", 120);             // 基本剑法
        set_skill("quanzhen-jianfa", 120);        //天罡剑法 
        set_skill("taoism",120);           //道学心法  
        set_skill("literate",120);           //读书写字
        set_skill("qixing-array",120);  

  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "tiangang-beidou");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("全真教", 3, "第子"); 
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );
        setup();
        
        carry_object("/d/quanzhen/npc/obj/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();

}   

