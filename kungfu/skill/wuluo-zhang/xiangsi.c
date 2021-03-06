// xiangsi.c 五罗轻烟掌「相思」绝技

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("相思只能对战斗中的对手使用。\n");           

        if( (int)me->query_skill("wuluo-zhang", 1) < 80 )
                return notify_fail("你的五罗轻烟掌不够娴熟，不会使用「相思」。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");  

        if( (int)me->query("neili", 1) < 100 )
                return notify_fail("你现在内力太弱，不能使用「相思」。\n");

        msg = CYN "只见$N脸冒轻烟，使出五罗轻烟掌中的「相思」绝技，双掌硬轰$n。\n"NOR;

          me->start_busy(2);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR " 结果$p被$P攻了个措手不及！\n" NOR;
                target->start_busy( (int)me->query_skill("wuluo-zhang") / 20 );
        } else {
                msg += CYN"可是$p看破了$P的招意，轻易的躲开了。\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
