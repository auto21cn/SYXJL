inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("玉笛谁家听落梅", ({"food"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘天下无双味美无比的名菜。\n");
                set("unit", "盘");
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}
