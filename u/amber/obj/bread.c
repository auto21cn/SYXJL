#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
       set_name(HIC "面包" NOR, ({"bread", "jisi", "bread"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个香喷喷的鸡丝面包。\n");
          set("unit", "个");
           set("value", 0);
           set("food_remaining", 10);
         set("food_supply", 100);
        }
}
