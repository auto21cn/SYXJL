// ci.c 六脉神剑 - 刺
// Written by Doing Lu 1999/1/4

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int lvl;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「刺」字决攻击只能对战斗中的对手使用。\n");

        if (objectp(weapon = me->query_temp("weapon")))
                        return notify_fail("你不能使用武器！\n");

        lvl = (int) me->query_skill("liumai-shenjian", 1);
        if( lvl < 100 )
                return notify_fail("你的六脉神剑太生疏，不会使用「刺」字决。\n");

        if ( me->query("neili") < 400)
                return notify_fail("你的内力不够，现在无法使用「刺」字决。\n");
        me->add("neili", -40);


        msg = HIG "$N使出六脉神剑「刺」式，指尖飞扬，霎时间剑气纵横，将$n包围在内。\n";

        me->start_busy(2);
        if( random( me->query("neili") + me->query("liumai-shenjian") * 10 ) > random((int) target->query("neili") + (int) target->query("dodge") * 10)) {
                msg += HIR " 结果$p一声闷哼，连被数创。\n" NOR;
                target->receive_damage("qi", random(lvl) + lvl);
                target->receive_wound("qi", random(lvl));
        } else {
                msg += "可是$p连连招架，堪堪挡住了$P攻势。\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

