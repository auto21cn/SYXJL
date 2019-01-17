// piao.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("水瓢", ({ "piao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只用来舀水的水瓢，普通百姓的日常用品。\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N拿出一只$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(5);
        setup();
}

