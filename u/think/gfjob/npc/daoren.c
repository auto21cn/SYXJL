//  dadao ��ƽ����-by duanfei
 
inherit NPC;
 
void create()
{
    set_name("��ƽ����", ({ "buping daoren", "daoren" }));
        set("long", 
        "һ���޶����Ľ��������Ĵ���ҽ��ᣬ�����ˡ�\n");
        set("gender", "����");
        set("age", random(20) + 25);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 27);
        
        set("max_qi", 1200);
        set("max_jing", 1200);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 100);
        set("combat_exp", 380000 + random(300000)); 
         
         set_skill("force", 150);
         set_skill("yijin-jing", 150);
         set_skill("dodge", 120 + random(30));
  

        set_skill("shaolin-shenfa", 120 + random(30));
        set_skill("strike", 120 + random(30));
        set_skill("sword", 120 + random(30));
        set_skill("parry", 120 + random(30));
        set_skill("chousui-zhang", 120 + random(30));
        set_skill("murong-jianfa", 120 + random(30));
        set_skill("literate", 20);
        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "murong-jianfa");
        map_skill("sword", "murong-jianfa");
        
        prepare_skill("strike", "chousui-zhang");
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("silver", 50);
}
#include "/quest/gfjob/npc/npc.h"
