// sucai.c 素菜

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("素菜", ({"sucai", "cai"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘再平常不过的素菜。\n");
		set("unit", "盘");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}
