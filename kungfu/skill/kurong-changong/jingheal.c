// recoverjing.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("你要用真气为谁恢复精力？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功！\n");

	if(target == me)
		return notify_fail("你没有为自己运功的能力！\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"已经受伤过重，经受不起你的真气震荡！\n");

	message_vision(
                HIR "$N运起枯荣禅功，和$n手掌相贴，一股热流缓缓地流入$n的体内....\n\n"
		"过了不久，$N长舒一口气，收回双掌，$n看起来好多了。\n" NOR,
		me, target );

	target->receive_curing("jing", 10 + (int)me->query_skill("force")/3 );
	target->add("jing", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("jing") > (int)target->query("eff_jing") ) target->set("jing", (int)target->query("eff_jing"));

	me->add("neili", -150);
	me->set("jiali", 0);
                me->start_busy(5);
                target->start_busy(5);
	return 1;
}
