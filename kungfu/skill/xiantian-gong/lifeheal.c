#include <ansi.h>

int exert(object me, object target)
{
        if( !target )
                return notify_fail("你要用真气为谁疗伤？\n");

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法运功疗伤！\n");

        if(target == me)
                return notify_fail("你没有为自己疗伤的能力！\n");

       if( (int)me->query_skill("xiantian-gong") < 50 )
                return notify_fail("你的先天功修为不够，乱给人点穴是会出人命的。\n");

        if( (int)me->query("max_neili") < 300 )
                return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("neili") < 150 )
                return notify_fail("你的真气不够。\n");

        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");

        message_vision(
                HIG "$N一手扶住$n背部，一手迅速点了$n的天门、白汇等几个大穴....\n"
                "过了不久，$n吐出一口瘀血，脸色看起来好多了。\n" NOR,
                me, target );

        target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
        target->add("qi", 10 + (int)me->query_skill("force")/3 );
        if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

        me->add("neili", -150);
        me->set("jiali", 0);
                me->start_busy(2);
                target->start_busy(2);
        return 1;
}
