// liujian.c 六脉神剑   六剑齐发

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("六剑齐发只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用六剑齐发！\n");
             
        if( (int)me->query_skill("liumai-shenjian", 1) < 120 )
                return notify_fail("你的六脉神剑不够娴熟，不会使用六剑齐发。\n");
              
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在内力太弱，不能使用六剑齐发。\n");
                        
        msg = CYN "$N内力源源涌出，少商、商阳、中冲、关冲、少冲、少泽六脉剑法,$n抵御不住，\n登时被剑气所创。\n"NOR;
          me->add("neili", -1000);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(1);
               target->start_busy(random(3));
                
                damage = (int)me->query_skill("force", 1);
               
                damage = damage*2 + random(damage);
                
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage*4);
                  me->add("neili", -1000 );
                
                if( damage < 20 ) msg += HIY"结果$n受到$N的剑气击中，闷哼一声。\n"NOR;
                else if( damage < 40 ) msg += HIY"结果$n被$N的剑气击中，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 80 ) msg += RED"结果$n被$N的剑气击中，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else msg += HIR"结果$n被$N的剑气击中，口中[哇]的吐出一口鲜血，身子如稻草人一般向后飞出丈许！！\n"NOR;
               
        } else 
 
 
        {
               me->start_busy(3);
                msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

