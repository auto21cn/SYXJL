// zhen.c 化功大法 之 “震”字诀
// by QingP from // zhen.c 太极拳「震」字诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, attackp, defendp;

//	if ( !me->query_skill("huagong-dafa", 1)
//	||    me->query_skill_mapped("poison") != "huagong-dafa" )
//		return notify_fail("你不会或者没激发化功大法，无法运“震”字诀。\n");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("“震”字诀只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用“震”字诀！\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 70 )
		return notify_fail("你的化功大法不够娴熟，不会使用“震”字诀！n");

	if( (int)me->query_skill("beiming-zhenqi", 1) < 100 )
		return notify_fail("你的北冥真气功力不够，不能使用“震”字诀。\n");

	if( (int)me->query("neili",1) < 200 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	message_vision( HIC "$N默运神功，聚毒于掌，使出化功大法“震”字诀，企图以至毒内力震伤$n心脉。\n"NOR, me, target );

	attackp = me->query_skill("huagong-dafa", 1) + me->query_skill("beiming-zhenqi",1);
	defendp = target->query_skill("force");

	if ( attackp / 2 + random( attackp ) / 2 > defendp || !living(target) )
	{
		damage = (int)me->query_skill("huagong-dafa", 1) + (int)me->query_skill("beiming-zhenqi", 1);
		damage = damage + random(damage/2);
		
		target->receive_damage("jing", damage);
		target->receive_wound("jing", damage/2);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);

		me->start_busy(3);
		me->add("neili", -damage/3);
		target->start_busy(2 + random(3));
		
		if( damage < 20 )
			message_vision( HIY "结果$n受到$N的内力反震，闷哼一声。\n"NOR, me, target);
		else if( damage < 40 )
			message_vision( HIY "结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR, me, target);
		else if( damage < 80 )
			message_vision( RED "结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR, me, target);
		else
			message_vision( HIR "结果$n被$N的内力一震，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR, me, target);

		tell_object( target, HIG "你立感心痛如绞，真气涣散，身形顿时被震飞得激射了出去。\n"NOR );

		if( !target->is_killing(me) ) target->kill_ob(me);

	}
	else 
	{
		message_vision( CYN "可是$p看破了$P的企图，并没有上当。\n"NOR, me ,target);
		me->start_busy(2);
	}

	return 1;
}