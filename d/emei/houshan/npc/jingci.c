//静慈师太 
//create bye cuer
//last modified by Lgok 2000.12.16

inherit NPC;

int peiyao();
int liandan();

void create()
{
        set_name("静慈师太", ({
                "jingci shitai",
                "jingci",
                "shitai",
        }));

        set("long",
                "她是一位和蔼的中年师太。\n是负责管理药王洞的人。\n据说对配药和炼制霹雳弹颇有造诣。\n"
        );

        set("gender", "女性");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 70);
        set("combat_exp", 400000);
        set("score", 100);

        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("yanxing-dao", 100);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "yanxing-dao");
        prepare_skill("blade", "yanxing-dao");

        create_family("峨嵋派", 4, "弟子");

        set("inquiry",([
            "配药" : ( : peiyao :),
            "霹雳弹" : ( : liandan : ),
             ]));

        setup();
        carry_object(__DIR__"obj/gangdao")->wield();
        carry_object(__DIR__"obj/cloth")->wear(); 
}

int peiyao()
{
	object me = this_player();
	object obj;
	int i;     
	if(!objectp(present("caoyao 3",me)))	{
		command("say 你的身上没有那么多草药。");
		return 1;
	}

	 for(i=0;i<3;i++) {
	   obj=present("caoyao",me);
	   destruct(obj);
	  }

	 command("smile");
	 command("say 好吧，我就给你配一包药吧，拿好了。");
	 obj=new(__DIR__"obj/zhongyao");
	 obj->move(me); 
	 message_vision("静慈师太给$N一包中药。\n",me); 
	 return 1;
}

int liandan()
{
	object me = this_player();
	object obj;

	if(!objectp(present("liuhuang",me)))	{
		command("say 你的身上没有炼制霹雳弹用的硫磺。");
		return 1;
	}

	obj=present("liuhuang",me);
	destruct(obj);
	command("smile");
	command("say 好吧，我就给你炼制一粒霹雳弹。");
	obj=new(__DIR__"obj/pilidan");
	obj->move(me);    
	message_vision("静慈师太给$N一粒霹雳弹。\n",me); 

	return 1;

}
