//zhebie.c
inherit NPC;
void create ()
 {            
                set_name("哲别", ({"zhebie", "zhe"}) );
              set("title", "神箭手");
              set("gender", "男性");
              set("age", 27);
              set("str", 28);
              set("int", 15);
              set("long",

"这人中等身材，宽大的脸上显出英武之气，手持一柄金弓，
他就是铁木真的地一神箭手哲别，哲别本是蒙语神箭手之意
因为他箭法如神，族人都叫他哲别，反而忘了他的真名。\n");
              set("combat_exp", 150000);
              set("attitude", "heroism");
              set("force", 1500);
              set("max_force",1500);
              set("force_factor", 10);
              set_skill("sword", 90);
              set_skill("unarmed", 90);
              set_skill("dodge", 90);
              set_skill("force", 90);

          set("inquiry", ([
               "华筝":"她是我妹妹，已经被铁木真赐婚给了郭靖，她现在正在伤心呢。\n"
              ]));
           setup();
}
