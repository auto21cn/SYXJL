inherit NPC;

void init();

int do_ling(string);

void create()
{
        set_name("静和师太", ({
                "jinghe shitai",
                "jinghe",
                "shitai",
        }));

        set("long",
                "她是一位中年师太。\n"
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
        set_skill("fuliu-jian", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("sword", "fuliu-jian");
        map_skill("parry", "fuliu-jian");
        prepare_skill("sword", "fuliu-jian");

        create_family("峨嵋派", 4, "弟子");

        setup();

        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
   add_action("do_ling","ling");
}                               

int do_ling(string arg)
{
 object ob = this_object();
 object me = this_player();
 object obj;
 if(!arg || (arg != "zhujian" && arg != "mudao"))
    return notify_fail("你要领什么？\n"); 

 if (arg == "zhujian" || arg == "mudao")
    {
	if (objectp(present(arg,this_player())) )
	    return notify_fail("你已经有了武器，还领什么？\n");
        obj=new(__DIR__"obj/"+arg);
	command("say 好吧，就给你一把"+obj->query("name")+"吧，好好练习我峨嵋的武技！");
        message_vision("$N交给$n一把"+obj->query("name")+"。\n", ob, me);
    }
	obj->move(me);
	return 1;
}