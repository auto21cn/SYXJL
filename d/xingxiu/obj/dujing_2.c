// dujing_2.c 『星宿毒经〖下册〗』

inherit ITEM;

void create()
{
	set_name("『星宿毒经〖下册〗』", ({ "du jing", "jing" }) );
	set_weight(100);
	set("unit", "册");
        set("long",
"\n                 『星宿毒经〖下册〗』\n\n"
"　　毒经为星宿宝典，凡以此经及经内所载武功泄漏与他人，即视为欺师灭祖、\n"
"背叛师门。对叛师之徒，虽上天入地，吾弟子必予诛之。外人持有本经者，吾\n"
"弟子见一个杀一个，见十个杀十个，断不容私阅本门宝典者苟存于世。\n\n"
"　　　　　　　　　　　　　　　　　　　　　　　　　　星宿老仙　丁春秋\n"
"\n"	);
	set("value", 700);
	set("material", "paper");
	set("skill", ([
		"name": "poison",  //name of the skill
		"exp_required": 0 , //minimum combat experience required
		"jing_cost": 10+random(1),// jing cost every time study this
		"difficulty":	20,	// the base int to learn this skill
		"max_skill":	31	// the maximum level you can learn
	]));
}
