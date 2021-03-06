// azi.c 阿紫
#include <ansi.h>
// by QingP

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("阿紫", ({ "azi" }));
	set("nickname", "星宿派小师妹");
	set("long",
		"她就是丁春秋弟子阿紫。\n"
		"她全身紫衫，只十五六岁年纪，一双大眼乌溜溜地，满脸精乖之气。\n");
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 18);
	set("int", 29);
	set("con", 20);
	set("dex", 24);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 70000);
	set("score", 10000);

	set_skill("force", 35);
	set_skill("dodge", 45);
	set_skill("strike", 45);
	set_skill("poison",55);
	set_skill("throwing",45);
	set_skill("parry", 20);
	set_skill("literate", 100);
	set_skill("beiming-zhenqi", 25);
	set_skill("zhaixinggong", 40);
	set_skill("xingchen-zhang", 50);
	set_skill("huagong-dafa",70);

	map_skill("force", "beiming-zhenqi");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingchen-zhang");
	map_skill("poison", "huagong-dafa");
	map_skill("parry", "xingchen-zhang");
	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "xingchen-zhang");

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/d/xingxiu/obj/flute1");
	carry_object("/d/xingxiu/obj/xxqingxin-san");
	carry_object("/d/xingxiu/obj/key");
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();

	ob = this_player();
	if((int)ob->query("shen") > 0 && ob->query("family/master_id")=="azi")
	{
		command("chat "+ob->query("name")+"!装什么正道人士，给我滚出星宿派。\n");
		command("expell "+ ob->query("id"));
			this_player()->set("title","星宿派" + RED + "弃徒" NOR);
	}
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}

int prevent_learn(object me, string skill)
{
	object ob = this_object();

	if(skill == "huagong-dafa")
	{
		message_vision("$N瞪着双乌溜溜的大眼睛笑嘻嘻的瞧着$n，一副茫然不知所闻的样子。\n", ob, me );
		tell_object(me, "显然她似乎不知道你在说些什么。\n");
		return 1;
	}
	return 0;
}
