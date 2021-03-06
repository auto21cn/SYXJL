// Overlord Sword 霸天云龙剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(WHT"霸天云龙剑"NOR,({ "overlord sword", "overlord", "sword"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 1);
                set("material", "steel");
                set("long", WHT"这是一柄被天界封印的绝世神剑。剑长六尺,雪白的剑鞘上镶嵌一颗散发柔和金光的无价宝
珠。\n暗灰色的剑身散发着一丝丝逼肤生痛的霸气。\n"NOR);
        }
        init_sword(1);
        setup();
}

int init()
{
	add_action("do_wield","wield");
	add_action("do_unwield","unwield");
}

int do_wield(string arg)
{
	object me;
	me=this_player();

	if(!arg&& arg!="sword") return notify_fail(HIR"你要解封什么？\n"NOR);
	if(me->query("id")!="aeolus"){
		message_vision(HIR"你没有解封神剑的力量！\n"NOR, me);
		return 1;
	}
	set("wield_msg",HIY"$N右手紧握霸天云龙剑的剑柄，左手食、中二指紧贴剑锋，缓缓地输入傲世霸气。突然，$N大
叱一声：“放！”。\n刹时间，霸天云龙剑从暗灰色变成了刺目的金黄色，令天地为之一惊，使日月也变得黯然失色。\n"NOR);
	set_name(HIY"霸天云龙剑"NOR,({ "overlord sword", "overlord", "sword"}) );
	set("long", HIY"被烈炎解封的绝世神剑。剑长六尺,雪白的剑鞘上镶嵌一颗散发柔和金光的无价宝珠。\n暗灰色的剑
身散发着一丝丝逼肤生痛的霸气。\n"NOR);
        init_sword(9999);
        set("value", 10000000);
}

int do_unwield(string arg)
{
	object me;
	me=this_player();

	if(!arg && arg!="sword") return notify_fail(HIR"你要封印什么？\n"NOR);
	if(me->query("id")!="aeolus"){
		message_vision(HIR"你没有解封神剑的力量！\n"NOR, me);
		return 1;
	}
        set_name(HIB"霸天云龙剑"NOR,({ "overlord sword", "overlord", "sword"}) );
        set("unwield_msg",HIB"$N双手齐握霸天云龙剑，高举过头，把剑中的傲世霸气尽数重归丹田。继而，$N对着神剑喊
了一声：“收！”。\n与此同时，霸天云龙剑刺目金黄色光芒渐渐地暗了下来，取而代之的是笼罩剑身的一片暗蓝。\n"NOR);
        init_sword(1);
        set("value", 1);
}
