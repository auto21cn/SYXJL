// fojing11.c



inherit ITEM;





void create()

{

          set_name("九阳真经", ({ "jiuyang zhenjing", "zhenjing" }));

	set_weight(200);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("unit", "本");

                  set("long", "这是一册记载玄门正宗内功的心法。\n");

		set("shaolin", 1);

		set("material", "paper");

		set("skill", ([

                          "name": "jiuyang-shengong",     // name of the skill

                          "exp_required": 200000,      // minimum combat experience required

                          "jing_cost":    30,     // jing cost every time study this

                          "difficulty":   40,     // the base int to learn this skill

                          "max_skill":    200      // the maximum level you can learn

		]) );

	}

}

