#include <ansi.h>
inherit NPC;

void create()
{
        set_name("老头子", ({ "lao touzi", "zi",}));
        set("nickname", "黄河老祖");        
        set("long", 
"此人身材极之肥胖，远看有如一大肉球
般，可身法却极之轻灵，动作如闪电般
迅速。\n");
        set("title",GRN"日月神教青龙堂坛主"NOR);        
        set("gender", "男性");
        set("age", 50);
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
        set("combat_exp", 400000);
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
create_family("日月神教",3,"弟子");
        setup();
 carry_object(__DIR__"obj/bi")->wield();
        carry_object(__DIR__"obj/cloth")->wear();        

}
