// force_book.c 内功心法

inherit ITEM;

void create()
{
        set_name("红花心法", ({ "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long", "这是一本线装书，记载着红花会的内功心法。\n");
                set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name":	"force",	// name of the skill
         "exp_required": 15000,      // minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
                        "max_skill":    150      // the maximum level you can learn
		]) );
	}
}
