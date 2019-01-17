#include <ansi.h>

inherit NPC;

void create()
{
        set_name("王城", ({ "wang cheng", "wang",}));
        set("long", 
"此人身材矮胖，满脸堆笑，其实为人十分狠毒。\n");
        set("title",HIY"日月神教风雷堂旗主"NOR);        
        set("gender", "男性");
        set("age", 50);
        set("attitude", "heroism");
        set("vendetta_mark", "authority");        
        set("pursuer", 1);
        set("shen_type", -1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        
        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 50000);
        set("score", 50);


        set_skill("sword", 60); 
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        set_skill("force",60);
        set_skill("tmzhang",60);
        
        map_skill("unarmed", "tmzhang");
create_family("日月神教",3,"弟子");
        setup();
}
