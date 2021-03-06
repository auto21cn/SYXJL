// du.c  化功大法 之 “毒”字诀
// by QingP

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, attackp, defendp;

//	if ( !me->query_skill("huagong-dafa", 1)
//	||    me->query_skill_mapped("poison") != "huagong-dafa" )
//		return notify_fail("你不会或者没激发化功大法，无法运“毒”字诀。\n");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("“毒”字诀只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用“毒”字诀！\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 45 )
		return notify_fail("你的化功大法不够娴熟，不能使用“毒”字诀！\n");

	if( (int)me->query_skill("beiming-zhenqi", 1) < 70 )
		return notify_fail("你的北冥真气功力不够，不能使用“毒”字诀。\n");

	if( (int)me->query("neili",1) < 120 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	message_vision( HIR "$N暗暗聚毒于掌，双掌四周顿时泛起一团若有若无的毒雾，\n"
		 + HIY"只见毒雾陡然间变得漆黑罩向$n全身。\n" NOR,
		me, target );

	attackp = me->query_skill("huagong-dafa", 1) + me->query_skill("beiming-zhenqi", 1) / 2 + me->query_skill("zhaixinggong",1) / 4;
	defendp = target->query_skill("force") + target->query_skill("dodge");

	if( attackp + random(attackp) > defendp || !living(target) )
	{
		message_vision(HIG "$p的身子晃了晃，却未闪避，结果被攻了个正着。\n" NOR, me, target );
		tell_object( target, HIG "你的头脑一阵眩晕，登时恍恍忽忽的若有所失，眼看掌力袭来却无法躲避。\n"
			 + HIR "你的肌肤与掌心一碰到，顿时灼热异常。\n" NOR);

		if( !target->is_killing(me) ) target->kill_ob(me);

		damage = ((int)me->query_skill("huagong-dafa", 1) + (int)me->query_skill("beiming-zhenqi", 1))/2;
		damage = damage/2 + random(damage);
		
		target->receive_damage("jing", damage/2);
		target->receive_wound("jing", damage/3);
		target->receive_damage("qi", damage/2);
		target->receive_wound("qi", random(damage/2));

		me->start_busy(2);
		me->add("neili", -100);
		target->start_busy(2 + random(1));

	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，迅速地避开了毒掌。\n" NOR, me, target);
		me->start_busy(random(2));
	}

	return 1;
}