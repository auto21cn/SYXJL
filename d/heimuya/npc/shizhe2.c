#include <ansi.h>
inherit NPC;

void create()
{
        set_name("护法使者", ({ "shi zhe", "zhe",}));
        set("long", 
"此人头上罩着黑色头罩，根本看不见
相貌，是由教主请手调教出来的高手
，负责着教坛的守卫。\n");
        set("title",HIW"日月神教护法"NOR);        
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 1000);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 100000);

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

        set("chat_chance", 1);
        set("chat_msg", ({
                 "护法使者高声说道：“教主令旨英明，算无遗策。”\n",
                "护法使者说道：“教主千秋万载，一统江湖。”\n",
        }));

}
