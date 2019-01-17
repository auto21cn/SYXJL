inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("村长", ({ "cun zhang", "zhang" }));
	set("long", "鹿鼎记玩家村村长，你可以找他买房子！\n");
	set("gender", "男性");
	set("age", 50);

	set_skill("literate", 100);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
//	set("shen_type", 1);
	setup();

	set("chat_chance", 5);
	set("chat_msg", ({
		"村长笑眯眯地说：您是来买房的吧？我们这里的服务包您满意。\n"
			}) );
}

void init()
{

}

int accept_object(object who, object ob)
{
    if (this_player()->query("age")<18) 
        {      write("你太小，过些日子再来买房吧！\n");
               return 0;
        } 
        if (!undefinedp(this_player()->query("myroom")))
        {     write("村长不解的说，您已经买过房了呀！\n");
              return 0;
        }
	if (ob->query("money_id") && ob->value() >= 10000000) {
		message_vision("村长高兴的对$N说：好吧，请到玩家村看看您的新房吧。\n", this_player());
	        this_player()->set("myroom/time",time());
		return 1;
	}

}
