// wudunlu.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("武敦儒", ({"wu dunru", "wu", "dunru"}));
	set("title", HIY"郭靖大弟子"NOR);
	set("gender", "男性");
	set("age", 23);
	set("long", "他是郭靖大弟子，相貌和蔼，一天到晚笑呵呵的。\n");
 	set("attitude", "peaceful");
	
	set("per", 24);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("inquiry", ([
		"黄蓉" : "那是我师母。\n",
		"郭靖" : "那是我师父。\n",
	]));

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	
	set("combat_exp", 80000);
	set("score", 20000);
	 
	set_skill("force", 50);
	set_skill("tiangang-zhengqi", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	
	map_skill("force", "tiangang-zhengqi");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}

