inherit ITEM;

void create()
{
	set_name( "金玉拳解上卷", ({ "shoufa tu", "tu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "幅");
		set("long", "这是天龙寺的前辈所写的练功心解，上面画着一些纷繁复杂的招式。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"jinyu-quan",	
			"exp_required":	0,	
			"jing_cost": 20, 	
			"difficulty":	20,	
			"max_skill":	30,	
		]) );
	}
}
