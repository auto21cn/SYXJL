inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("宋老板", ({ "song lao ban", "laoban", "song" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "宋老板热心的接待每一位来光顾的客人，总是笑容可拘\n");
        set("combat_exp", 100);
        set("per", 18);
        set("attitude", "friendly");
        set("rank_info/respect", "老板");

        set("vendor_goods", ({
                "/d/city/obj/camera",
                "/d/city/obj/maomao",
        }) );
        setup();
       carry_object("/d/city/obj/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "宋老板笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，买个玩具吧，送个亲朋好友保证拿的出手。\n");
                        break;
                case 1:
                        say( "宋老板拿起一件玩具，说道：这位" + RANK_D->query_respect(ob)
                                + "，您看看，保证质量，童叟无欺。\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 1000) 
        {
                tell_object(who, "宋老板高兴地说道：多谢，有好的玩具一定给您老留一件，不过千万别让我的上司风雨云知道我在受贿。\n");

                return 1;
        }

        return 0;
}


