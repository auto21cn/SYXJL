// baihong-jian.c
// by ronger

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIC"白虹剑"NOR, ({ "baihong", "jian" }));
	set_weight(8000);
        set("unique", 1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIC"一看就知道绝对是一把利器，锃白闪亮的剑身让人不寒而戾。\n"NOR);
                set("value", 500000);
                set("material", "steel");
                set("wield_msg", HIG"突然间，晴天之中一道青色的霹雳划过，$N手中已然多了\n"
                        "一把闪烁着耀眼白光的古物——"HIC"白虹剑"HIG"！\n"NOR);
                set("unwield_msg", HIC"白虹剑"HIW"在划出一阵寒风过后，已然回归鞘中。\n" NOR);
        }
        init_sword(120);
        set("no_drop", "这样的宝物你怎么能随便丢弃呢？ \n");
        set("no_give", "这样的宝物你怎么能随便送人呢？ \n");
        set("no_put", "这样的宝物你怎么能随便丢弃呢？ \n");
        set("no_sell", "这样的宝物卖给谁都不会敢要的！ \n");
        setup();
}


