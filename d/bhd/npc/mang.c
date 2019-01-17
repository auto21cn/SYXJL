// animal: snake.c

// Johnny 98.8



inherit NPC;



void create()

{

        set_name("蟒蛇", ({ "mang she", "mang" }));

        set("race", "野兽");

        set("age", 200);

        set("long", "一条庞大无比, 色彩斑斓的巨蟒。 浑身发出阵阵强烈的腥臭味。\n");

        set("attitude", "aggressive");

        set("str", 70);

        set("con", 50);

        set("max_qi", 800);

        set("limbs", ({ "头部", "身体", "尾巴" }) );

        set("verbs", ({ "bite" }) );

        set("combat_exp", 200000);

        set_temp("apply/attack", 50);

        set_temp("apply/armor", 50);

        setup();

}



void die()

{

        object ob,ob1,ob2;

        message_vision("$N抽搐了几下，身体缩在一起，死了。\n", this_object());

        ob = new(__DIR__"shebian");

        ob1 = new(__DIR__"shepi");

        ob2 = new(__DIR__"sherou");

        ob->move(environment(this_object()));

        ob1->move(environment(this_object()));

        ob2->move(environment(this_object()));

        destruct(this_object());

}

