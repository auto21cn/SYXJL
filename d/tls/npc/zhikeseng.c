// zhikeseng.c 知客僧

inherit NPC;

void create()
{
	set_name("知客僧", ({ "zhike seng", "zhike" }));
	set("long", 
		"他是天龙寺的知客道长。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("taiji-jian", 20);
	set_skill("taoism", 20);

	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("天龙寺", 7, "弟子");

	setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
