// sanmending.c 丧门钉
// csy 12/12/98

#include <weapon.h>
inherit THROWING;
// inherit COMBINED_ITEM;

void create()
{
        set_name("丧门钉", ({ "sangmen ding", "ding" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一玫丧门钉，似乎喂的是“青陀罗花”的毒汁。\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N抓出一把丧门钉扣在手心。\n");
                set("unwield_msg", "$N将手中的丧门钉放回装暗器的皮囊里。\n");
                set("base_unit", "枚");
                set("base_weight", 2);
        }
        set_amount(1);
        init_throwing(10);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
         if( random(me->query_skill("xuantian-wuji")) > 5) {
                 victim->apply_condition("qtlh_poi", random(2) + 1 +
                        victim->query_condition("qtlh_poi"));
                return "$n中毒了。\n";
        }
}

