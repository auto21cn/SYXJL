inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIR"朱"NOR"睛"HIC"冰"NOR"蟾"NOR, ({"chan"}));
	set("unit", "只");
	set("value", 40000);
	set("long", "这是一千年难得一见的朱睛冰蟾, 通体透明,
惟眼呈赤色, 能解百毒。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
        message_vision(HIG"$N服下一只朱睛冰蟾，只觉一股清香沁入心肺，
                       顿时灵台一片空明，神意清爽！\n" NOR, me);
        set_temp("nopoison", 3);
	destruct(this_object());
	return 1;
}
