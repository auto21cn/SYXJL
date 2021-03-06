// 一叶知秋
// bye jfeng
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「一叶知秋」只能对战斗中的对手使用。\n");
        if((int)me->query_skill("fengye-zhi",1) < 100)
                return notify_fail("你枫叶指的火候不够不能使用一叶知秋!\n");
        if((int)me->query_skill("finger") < 100)
                return notify_fail("你的指法修为不够,目前还不能使用一叶知秋绝技!\n");
        if((int)me->query("neili") < 700)
                return notify_fail("你真气现在不够, 不能使用一叶知秋! \n");
        if((int)me->query("max_neili") < 500)
                return notify_fail("你内力修为不够, 不能使用一叶知秋! \n");
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧!\n");
        msg =
HIC "$N使出枫叶指绝技「一叶知秋」，十指连发，只见漫天指影
罩向$n，$n只觉得无从招架，待闪避时已不来不急,
才知道天外有天，人外有人。\n";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3 )
        {
                msg +=  HIR "结果$p被$P指力点中檀中大穴! \n" NOR;
                target->start_busy( (int)me->query_skill("fengye-zhi",1) / 40 + 2);
                me->add("neili", -150);
        }
        else
        {
                msg += HIY "$p仰天长笑，尔之鼠技，焉能伤我？话声未落，人已在十丈以外。\n" NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        return 1;
}
