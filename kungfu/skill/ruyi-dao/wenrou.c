// wenrou.c 温柔一刀

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
 
        if( !me->is_fighting() )
                  return notify_fail("「温柔一刀」只能在战斗中使用。\n");
 
          if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
                  return notify_fail("「温柔一刀」开始时必须有刀在手！\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("你的真气不够！\n");

          if( (int)me->query_skill("blade") < 50 || me->query_skill_mapped("blade") != "ruyi-dao")
                  return notify_fail("你的刀还不到家，无法使用温柔一刀！\n");

            msg = HIR "$N使出如意刀绝技"+HIM"「温柔一刀」"NOR""HIR"，刀锋寒芒四射！\n" NOR;
        message_vision(msg, me);

        weapon = me->query_temp("weapon");

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("neili", -200);
        me->start_busy(random(5));

        return 1;
}


