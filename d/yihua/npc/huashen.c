
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
	set_name("花之神", ({ "hua shen", "hua", "shen"}));
	set("long",
	    "这是个容貌动人的女子, 是她自称花之神,\n"+
	    "其实原是移花宫门人，后无故失踪，她竟然\n在这里，眼如点漆, 清秀绝俗.\n"+
	    "真是绝代佳人.\n");
	set("gender", "女性");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);

	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 170);
	set_skill("dodge", 180);
	set_skill("parry", 170);
	set_skill("sword",100);

	set_skill("yihua-force",180);
	set_skill("yihua-jiemu",180);
	set_skill("yifeng-jian",180);

	map_skill("force", "yihua-force");
	map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "yihua-jiemu");
	map_skill("sword", "yifeng-jian");

	prepare_skill("sword","yifeng-jian");
	create_family("移花宫",2,"传人");
	setup();
	carry_object("/u/skinys/yihua/obj/jinlvyi")->wear();
        carry_object("/clone/weapon/changjian")->wield();
	add_money("gold",15);
}
