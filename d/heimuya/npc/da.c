#include <ansi.h>
inherit NPC;

void create()
{
        set_name("司马大", ({ "si mada", "si",}));
        set("long", 
"这大汉身材魁梧之极，巨人般的身体在走动
时，脚步声极之沉重，整个地板都为之震动。\n");
        set("title",GRN"日月神教青龙堂舵主"NOR);        
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        
        set("max_qi", 700);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 500000);



       
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
        
        map_skill("unarmed", "tmzhang");
        create_family("日月神教", 3, "弟子");

        setup();
}

