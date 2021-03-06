// gaoli.c

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("高丽商", ({ "gaoli shang", "shang" }));
	set("title", "新罗坊老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long",
		"这是个高丽商人，长得和中国人没啥区别。连卖的东西也差不多。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
                   "/d/city/obj/mabudai",
                   "/d/city/obj/beixin",
                   "/d/city/obj/toukui",
                   "/d/city/obj/cycle",
                   "/d/city/obj/surcoat",
                   "/d/city/obj/shield",
                   "/d/city/obj/huwan",
                   "/d/city/obj/zhitao",
                   "/d/city/obj/huyao",
                   "/d/city/obj/caoxie",
                   "/d/city/obj/pixue",
                   "/d/city/obj/shoutao",
                   "/d/city/obj/tieshou",



	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
