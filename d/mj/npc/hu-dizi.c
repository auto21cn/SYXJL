// 药师

#include <ansi.h>
inherit NPC;
string ask_liao();
string ask_me();

void create()
{
	set_name("药师", ({ "yao shi", "yao" }));
	set("long",
		"他就是明教的见死不救医仙胡青牛的弟子。\n"
		"全身仙气笼绕，颇有些乃师风范。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("no_get", 1);

	set("max_qi", 250);
	set("max_jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);
	set("combat_exp", 10000);
	set("shen",500);
	set("score", 10);

	set_skill("force", 30);
	set_skill("shenghuo-shengong", 30);
	set_skill("dodge", 30);
	set_skill("qingyunwu", 30);
	set_skill("shenghuo-quan", 30);
	set_skill("parry", 30);
	set_skill("literate", 40);

	map_skill("force", "shenghuo-shengong");
	map_skill("unarmed", "shenghuo-quan");
	map_skill("parry", "shenghuo-quan");
	create_family("明教", 35, "弟子");
	set("inquiry", ([
	      "疗伤" : (: ask_liao :),
	]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_liao()
{
	mapping fam;
	int i, j;

	object ob;
	ob=this_player();
	write( "药师正盯著你看，不知道打些什么主意。\n");
	if ( ob->is_busy() )
		return "你正忙着呢。\n";
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
		return RANK_D->query_respect(this_player()) +
		"与本派素无来往，不知此话从何谈起？";
	if ((int)this_player()->query("eff_qi") >= (int)this_player()->query("max_qi"))
		return RANK_D->query_respect(this_player()) + "气血充足，不用医治啊。";
	i = ob->query("max_jing") - ob->query("eff_jing");
	j = ob->query("max_qi") - ob->query("eff_qi");
	ob->add("eff_jing", i/2);
	ob->add("jing", i/2);
	ob->add("eff_qi", j/2);
	ob->add("qi", j/2);
	write( HIW "药师在你身上动了几下，你觉得浑身好过了些，好象失去的一些气血回到了身上 \n"NOR);
	ob->start_busy(3);

	return "我本事不够，只能这样了！";
}
