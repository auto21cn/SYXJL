inherit NPC;
void create()
{ 
       set_name("博尔术", ({"boershu", "shu" }));
        set("title", "大漠四杰-赤狼" );
                    set("gender", "男性");
                   set("age", 38 );
                   set("str", 27 );
                   set("int", 19 );
                   set("long",                   

"只见眼前这人身材魁梧，目光如鹰，一脸阳刚之气，
 他就是大漠四杰之一的博尔赤。他在战场上是位屡立
 战功的将领，同时也与铁木真有着手足深情，铁木真
 称之为鹰爪，就是说他就如猛鹰的爪一般重要。\n");
                    set("combat_exp", 200000 );
                    set("attitude", "heroism" );
                    set("force", 1600 );
                    set("max_force", 1600 );
                    set("force_factor", 10 );
                    set_skill("parry", 130 );
                    set_skill("dodge", 130 );
                    set_skill("force", 120 );
                    set_skill("sword", 120 );                           
                    set_skill("unarmed", 130 );
                    set("inquiry", ( [
                           "铁木真": "我们永远跟随大汉！草原上的成吉思汗！成吉思汗！成吉思汗！\n"
                    ] ) );
            setup();
}
