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
        set("chat_msg_combat", ({
                "狼王大声：喔！喔！喔！喔！喔！喔！\n",
                "狼王突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
        }) );
                
        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);
        set("chat_chance", 20);

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
        message_vision(HIW "$N仰天长啸,远处峭壁上传来隐隐狼嗥！\n" NOR,this_object());
        message_vision("$N惨嚎一声，死了！\n", this_object());
        message_vision(HIR "突然从暗处冲出一群野狼！\n" NOR);
        ob = new(__DIR__"obj/goupi");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolfking");
        ob->move(environment(this_object()));
 
        destruct(this_object());
}

