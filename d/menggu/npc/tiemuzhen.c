inherit NPC;
void create()
{
        set_name("铁木真", ({"teimuzhen", "tie" }));
        set("title", "成吉思汗" );
                    set("gender", "男性");
                   set("age", 48 );
                   set("str", 25 );
                   set("int", 16 );
                   set("long",                   
"这人身材高大，头戴铁盔，下颏生了一丛褐色的胡子，双
 目一转，精光四射。他就是蒙古部落的首领铁木真。\n" );
                    set("combat_exp", 130000 );
                    set("attitude", "heroism" );
                    set("force", 1000 );
                    set("max_force", 1000 );
                    set("force_factor", 0 );
                    set_skill("parry", 80 );
                    set_skill("dodge", 70 );
                    set_skill("force", 70 );
                    set_skill("sword", 80 );                           
                    set_skill("unarmed", 80 );
                    set("inquiry", ( [
                           "name": "我就是铁木真。\n"                                                                                                                                                                                                              
        ]));
           setup();
}
