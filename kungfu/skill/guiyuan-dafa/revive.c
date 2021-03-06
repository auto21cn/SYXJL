// revive.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("你自己是清醒的吗？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功！\n");

	if(target == me)
		return notify_fail("你不能对自己运功！\n");

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的真气不够。\n");

        if( living(target) )
		return notify_fail( target->name() +
			"已经是清醒的！\n");

	message_vision(
		HIR "$N坐了下来运起内功，将手掌贴在$n的灵台穴，缓缓地输一股真气....\n\n" NOR,me, target );

	target->revive();
     
	me->add("neili", -50);
	me->set("jiali", 0);
                me->start_busy(2);
                target->start_busy(2);
	return 1;
}
