#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("“震”字诀只能对战斗中的对手使用。\n");

        if(me->query("family/master_name")!="天山童姥")
                return notify_fail("你没有经过天山童姥的指点，无法领悟此招的精髓！\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用“震”字诀！\n");
             
        if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
                return notify_fail("你的六阳掌不够娴熟，不会使用“震”字诀。\n");
              
        if( (int)me->query("neili", 1) < 5000 )
                return notify_fail("你现在内力太弱，不能使用“震”字诀。\n");
                        
        msg = HIC "$N默运神功，使出天山六阳掌「震」字诀，企图以内力震伤$n"NOR;
          me->add("neili", -3000);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(8);
               target->start_busy(random(1));
                
                damage = (int)me->query_skill("force", 1);
               
                damage = damage*2 + random(damage);
                
                target->receive_damage("qi", damage/4);
                target->receive_wound("qi", damage/2);
                  me->add("neili", -3000 );
                
                if( damage < 20 ) msg += HIY"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 40 ) msg += HIY"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 80 ) msg += RED"结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else msg += HIC"结果$n被$N的内力一震，  连吐几口鲜血，受伤着实不轻！\n"NOR;
               
        } else 
 
 
        {
               me->start_busy(10);
                msg += HIC"可是$p看破了$P的企图，并没有上当。\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

