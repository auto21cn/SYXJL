// /kungfu/skill/jiuyin-baiguzhao/du.c 九阴白骨爪施毒
// adx 22:44 99-2-10

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
//        object obj;
        string msg;

        if( !target ) target = offensive_target(me);
   	if ((string)me->query("gender")!="女性")
        	return notify_fail("你的外功中没有这种功能。\n");

        if( environment(me)->query("no_fight") )
              return notify_fail("施毒只能在战斗中使用。\n");
        if(!target || !target->is_character()|| !me->is_fighting(target) )
                return notify_fail("施毒只能对战斗中的对手使用。\n");

if(!me->query("jiuyin") && (int)me->query_skill("bibo-shengong", 1) < 100 )
                return notify_fail("你不能使用施毒绝技。\n");
        if( (int)me->query("neili") < 200 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("jiuyin-baiguzhao", 1) < 100 )
                return notify_fail("你的九阴白骨爪不够娴熟，不能施毒。\n");

                msg = HIB "$N将毒质运于指上，双手手指微微泛出蓝光，抓向$n。\n";

        me->start_busy(2);
        if( random( (int)me->query_skill("jiuyin-baiguzhao",1))
          > random(target->query_skill("dodge") ) ) {
                msg += HIB " 结果$p被$N抓出一条长长的"+HIR"血痕！\n" NOR;
            target->receive_damage("qi",(int)me->query_skill("jiuyin-baiguzhao",1));
            target->receive_wound("qi",15 + random(10));
            target->receive_wound("jing", 10);
            target->apply_condition("jy_poison", random(me->query_skill("jiuyin-baiguzhao",1)/5) + 1 +
                        target->query_condition("jy_poison"));
                        target->start_busy(random(2));
        } else {
                msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
                me->start_busy(random(4));
        }
        message_vision(msg, me, target);
        return 1;
}

