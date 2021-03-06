#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIB"狼王"NOR, ({ "wolf king","king"}) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只身体硕大，两眼发着绿光的狼。\n");
        set("attitude", "peaceful");
        
        set("str", 100);
        set("cor", 100);
        set("dex", 100);
        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 1000000);
        set("shen_type", -1);

        set("chat_chance", 6);
        set("chat_msg", ({
          (: this_object(), "random_move" :),
        }) );
        
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "野狼大声：喔！喔！喔！喔！喔！喔！\n",
                "野狼突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
        }) );
                
        set_temp("apply/attack", 150);
        set_temp("apply/damage", 300);
        set_temp("apply/armor",  200);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );

        setup();
}


void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }       
}
void die()
{
        object ob;
        message_vision("$N惨嚎一声，死了！\n", this_object());
        ob = new(__DIR__"obj/goupi");
        ob->move(environment(this_object()));
        destruct(this_object());
}

