// sheep.c 山羊
// by QingP

inherit NPC;

void create()
{
	set_name("山羊", ({ "shan yang", "yang", "sheep" }) );
	set("race", "野兽");
	set("age", 5);
	switch( random(3) )
	{
		case 0:	
			set_name("山羊", ({ "shan yang", "yang", "sheep" }) );
			set("long", "一只白色的小山羊。\n");
		break;
		case 1:
			set("long", "一只黑色的小山羊。\n");
		break;
		case 2:
			set("long", "一只白色的小绵羊。\n");
		break;
		case 3:
			set("long", "一只黑色的小绵羊。\n");
		break;
	}
        set("long", "一只白色的小山羊。\n");
        set("attitude", "peaceful");
        
        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 500);
//      set("shen_type", 0);

//      set("chat_chance", 6);
//      set("chat_msg", ({
//              (: this_object(), "random_move" :),
//      }) );
        
== 未完继续 57% == (ENTER 继续下一页，q 离开，b 前一页)
        set_temp("apply/attack", 2);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 2);
        set_temp("apply/armor", 1);

        setup();
}

void die()
{
        object ob;
        message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
        ob = new(__DIR__"turou");
        ob->move(environment(this_object()));
        destruct(this_object());
}
