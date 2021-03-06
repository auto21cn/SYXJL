// hua.c  化功大法 之 “化”字诀
// by QingP

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int attackp, defendp;

//	if ( !me->query_skill("huagong-dafa", 1)
//	||    me->query_skill_mapped("poison") != "huagong-dafa" )
//		return notify_fail("你不会或者没激发化功大法，无法运“化”字诀。\n");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("“化”字诀只能对战斗中的对手使用。\n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要化掉谁的内力？\n");

	if( me->query_temp("hua") )
		return notify_fail("你刚刚运过“化”字诀, 毒质还未汇聚!\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法化人内力！\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 100 )
		return notify_fail("你的化功大法不够娴熟，不能化掉对方的内力！n");

	if( (int)me->query_skill("beiming-zhenqi", 1) < 130 )
		return notify_fail("你的北冥真气功力不够，不能施化功大法。\n");

	if( (int)me->query("neili",1) < 270 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("max_neili") <= 0 )
		return notify_fail( target->name() + "他已经没有任何内力了！\n");

	message_vision( HIR "$N突然诡异的一笑，左掌倏然收回，右掌以迅雷不及掩耳之势忽地对准$n猛力拍出！\n" NOR,
		me, target );

	attackp = me->query_skill("huagong-dafa", 1) + me->query_skill("beiming-zhenqi", 1) + me->query_skill("zhaixinggong", 1) / 2;
	defendp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("hua", 1);

	if( attackp / 2 + random(attackp) > defendp || !living(target) )
	{
		message_vision(HIY "$p一时难以闪避，只得挺掌相抵。\n" NOR, me, target );
		tell_object(me, HIG "你见" + target->name() + "出掌相迎，心中大喜，当即运起“化”字诀，掌中毒质随内劲直送过去...\n" NOR);
		message_vision(HIY "$p大叫一声“不好！”\n" NOR, me, target );
		tell_object(
			target, HIB "但觉手掌中微微一凉，内力源源不绝的向外飞散，再也凝聚不起来，\n" + 
			"登时心中一惊，只是全身软绵绵的已没了力气，眼中看出来迷迷糊糊的尽是白雾。\n" 
			NOR);

		if( !target->is_killing(me) ) target->kill_ob(me);

		target->add("neili", -1*((int)me->query_skill("huagong-dafa", 1) + target->query("jiali"))*2 );
		target->add("max_neili", -1*((int)me->query_skill("huagong-dafa", 1) + target->query("jiali"))*2 );
		target->set_skill("force", target->query_skill("force", 1) - ((int)me->query_skill("huagong-dafa", 1) + target->query("jiali"))/10 );
		if( target->query("neili") <1 ) target->set("neili", 0);
		if( target->query("max_neili") <1 ) target->set("max_neili", 0);
		if( target->query_skill("force", 1) <1 ) target->set_skill("force", 0);

		if( target->query("combat_exp") >= me->query("combat_exp") )
		{
			if( (int)me->query("potential") - (int)me->query("learned_points") < 110 )
			me->add("potential", 7);
			me->add("combat_exp", 20);
		}

		me->start_busy(7);
		target->start_busy(2 + random(7));
		me->add("neili", -200);

		call_out("del_hua", 10, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，迅速地避开了这一掌。\n" NOR, me, target);
		me->start_busy(4);
		call_out("del_hua", 17, me);
	}

	return 1;
}

void del_hua(object me)
{
	if ( me->query_temp("hua"))
	me->delete_temp("hua");
}