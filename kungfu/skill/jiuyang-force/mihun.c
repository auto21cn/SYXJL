// chillgaze.c

#include <ansi.h>
//inherit F_CLEAN_UP;
//inherit SSERVER;
inherit F_SSERVER;

int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage;

	if( !me->is_fighting() )
		return notify_fail("［迷魂大法］只能在战斗中使用。\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的内力不够。\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("你要对谁施展［迷魂大法］？\n");
	}
	if(target->query("name")=="叶开")return notify_fail("你不适合用这种武功.");
	skill = me->query_skill("force");

	me->add("neili", -50);
	me->receive_damage("qi", 20);

	message_vision(
		HIB "\n$N面上神情诡异，双眼变得异常朦胧！\n" NOR, me, target);
	
	if( random(target->query("combat_exp")) > (int)me->query("combat_exp") / 2 ) {
		message_vision("$N很快地转过头去，避开了$n的目光。\n", target, me);
		// me->start_busy(3);
		return 1;
	}
	skill = me->query_skill("force");
	damage = skill * 2 - target->query("force") / 15;
	if( damage < 1 ) {
		message_vision("但是$N对$n的注视视若无睹....。\n", target, me);
	//	me->start_busy(3);
		return 1;
	}

	target->receive_damage("jing", damage);
	if( random(skill) > (int)target->query("cps") * 2 )
		target->start_busy(5);
	message_vision("$N被$n的诡异神情所惑，不自禁地慢了下来。\n", target, me);
	
	me->start_busy(1);
	return 1;
}

