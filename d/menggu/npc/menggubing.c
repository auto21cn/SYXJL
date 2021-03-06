inherit NPC;

void create()
{
        set_name("蒙古兵", ({ "menggu bing", "bing" }));
        set("age", 22);
        set("gender", "男性");
        set("long", "蒙古兵个个都从小受到训练，打仗冲锋不比中原的差。\n");
        set("attitude", "peaceful");
        set("vendetta_mark", "authority");
        set("pursuer", 1);

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 10000);
        set("shen_type", 1);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("blade", 50);
        set_skill("force", 50);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        setup();
this_object()->carry_object("/d/menggu/obj/madao")->wield();
}

int accept_fight(object me)
{
        command("say 放马过来吧，我们蒙古的勇士是天下最好的。\n");
        me->apply_condition("killer", 500);
        kill_ob(me);
        return 1;
}

int check_jindao (object who)
{
  object me = this_object();
  object jindao;

  jindao = present("jin dao",who);

  if (! jindao)
    return 1;

    message_vision("$N对$n吼道：敢冒充我们蒙古国的金刀驸马！看刀！！！\n",me,who);
  command("kill "+who->query("id"));
  me->set_temp("no_return",1);
  return 1;
}
