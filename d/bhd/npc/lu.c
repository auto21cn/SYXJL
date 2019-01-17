// Johnny 8/98

inherit NPC;

void create()
{       set_name("梅花鹿", ({"meihua lu", "meihua", "lu"}));
        set("race", "野兽");
        set("age", 10);
        set("long", "一匹良种的梅花鹿，身上的斑纹十分好看。\n");
        set("attitude", "peaceful");
set("limbs", ({ "角", "身体", "前蹄", "后蹄" }) );
        set("verbs", ({ "hoof", "knock" }) );
        set("max_qi",1000);
set("combat_exp", 5000);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 10);

        set("chat_chance", 10);
        set("chat_msg", ({
                "梅花鹿见有人来，害羞地跑开了。\n",
                (: random_move :)
        }) );
        setup();
}
