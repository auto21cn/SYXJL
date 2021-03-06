// yang.c 杨老板 
inherit F_VENDOR_SALE;
//inherit NPC;
//inherit F_VENDOR;

void create()
{
        reload("yang");
        set_name("杨永福", ({ "Yang yongfu", "yang" }));
        set("shop_id",({"boss"}));
        set("shop_title","杂货铺老板");
        set("shen_type", 1);

        set("gender", "男性");
        set("age", 45);
        set("long",
                "杨老板是土生土长的扬州人，做了几十年的小买卖。\n");
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
       carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}


