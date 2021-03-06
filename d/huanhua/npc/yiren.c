#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("任易", ({ "ren yi", "ren" }) );
	set("title","书生");
	set("gender", "男性" );
	set("shen_type", 1);
	set("age", 35);
	set("str", 25);
	set("cor", 25);
	set("int", 25);
	set("long",
		"这是个手里拿着一卷经书的书生嘴里还正唠叨个不挺。\n");
	set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4400);
        set("max_neili", 4400);
        set("jiali", 100);
        set("combat_exp", 3000000);
	set("attitude", "heroism");
	set("chat_chance_combat", 30);

	set("inquiry", ([
		"萧易人"   : (: ask_me :),
		"黑白剑"   : (: ask_me :),
	]) );

	
        set_skill("cuff", 185);
        set_skill("strike",185);
        set_skill("force", 190);
        set_skill("dodge", 190);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("literate",180);
	set_skill("unarmed",180);
        set_skill("huanhua-jian",200);
	 set_skill("tiexian-quan",180);
	 set_skill("guiyuan-dafa",180);
         set_skill("feihua-wuping",180);

	 map_skill("force","guiyuan-dafa");
	 map_skill("unarmed","tiexian-quan");
	 map_skill("sword","huanhua-jian");
	 map_skill("dodge","feihua-wuping");
     
        set("sword_count", 1);
        set("chat_chance", 50);
        set("chat_msg", ({
                "任易说道: 你知道浣花溪吗 ! \n",
                "任易情不自禁地说：浣花溪可是个美丽的地方。\n",
                (: random_move :)
        }) );

	setup();
	
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
      
}

string ask_me(object who)
{
	object ob,me = this_player();
        if (query("sword_count") < 1){
        me->unconcious();
       return "你敢用BUG!!\n";}
	if (random(10) < 5) 
		return "我…不大清楚。\n";
        message("vision", "任易突然一震，看来...爹还是知道我在哪儿了。\n" NOR,
		environment(), this_object() );
        say("很长时间没回浣花了，真想回去看看。\n");
                     
          ob = new ("/d/huanhua/obj/bsword");
	ob->move(this_player());
        add("sword_count", -1);
        me->start_busy(5);
	message_vision("萧易人给$N一把黑剑。惚的人就不见了\n",this_player());
        remove_call_out("destrory");
        call_out("destrory",1,this_object());
	return ("麻烦你把这把剑带回浣花吧。");
	
}
void destrory(object ob)
{
        destruct(ob);
}
