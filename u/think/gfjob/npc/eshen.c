//  南海鳄神-by duanfei

#include <ansi.h> 
inherit NPC;
 
void create()
{
        set_name("南海鳄神", ({ "nanhai eshen", "eshen" }));
        set("nickname",HIY "凶神恶煞"NOR);
        set("long", 
        "他一个脑袋大得异乎寻常，一张阔嘴中露出白森森的利齿，一对眼睛却是又圆又小，便如两
颗豆子，然而小眼中光芒四射，向你脸上骨碌碌的一转，你不由得打了一个寒噤。但见他中
等身材，上身粗壮，下肢瘦削，颏下一丛钢刷般的胡子，根根似戟，却瞧不出他年纪多大。
身上一件黄袍子，长仅及膝，袍子子是上等锦缎，甚是华贵，下身却穿着条粗布裤子，污秽
褴褛，颜色难辨。十根手指又尖又长，宛如鸡爪。你初见时只觉此人相貌丑陋，但越看越觉
他五官形相、身材四肢，甚而衣着打扮，尽皆不妥当到了极处。\n");
        set("gender", "男性");
        set("age", 36);
        set("attitude", "peaceful");
        set("str", 35);
        set("int", 20);
      set("con", 35);
        set("dex", 27);
        
        set("max_qi", 2500);
        set("max_jing", 2500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 120);
        set("combat_exp", 1500000); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.fumo" :),
         })); 
         set_skill("force", 180);
         set_skill("yijin-jing", 180);
         set_skill("dodge", 180);
  

        set_skill("shaolin-shenfa", 180);
        set_skill("cuff", 180);
         set_skill("jingang-quan", 210);
        set_skill("parry", 170);
      
        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "jingang-quan");
        prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);
}
#include "/quest/gfjob/npc/npc.h"

