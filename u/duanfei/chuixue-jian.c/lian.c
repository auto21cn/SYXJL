#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        msg = HIY "$N使出寒天吹雪剑法「连」字诀，招式陡然变快。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/20 )
        {
                attack_time = random((int)me->query_skill("taiji-jian", 1) / 20);
                if(attack_time < 1)
                        attack_time = 1;

                msg += CYN " 结果$p被$P攻了个措手不及！\n" NOR;
                for(i = 0; i < attack_time; i++){
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                        }

                me->start_busy(2);
                me->add("neili", -100);
        }
        else
        {

                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

