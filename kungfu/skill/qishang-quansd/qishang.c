// qishang 七伤
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int i, j, damage;
    
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("此招只能对战斗中的对手使用。\n");
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用此招！\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
                
        if( (int)me->query_skill("qishang-quan", 1) < 100 )
                return notify_fail("你的七伤拳还不够娴熟，还没有办法拳出七伤。\n");

        if( (int)me->query("neili", 1) < 800 )
                return notify_fail("以你的目前的内力没有办法发出这一招。\n");

        i=random((int)(me->query_skill("qishang-quan",1)/30));
        if(i<1) i=1;
        if(i>7) i=7;
        msg = HIY "$N凝神运功，使出“七伤拳”最后的绝招，"+chinese_number(i)+"股无比强劲的热气呼啸的扑向$n身上各大要穴。\n"+HIC "$n急提丹田之气与体内来回撞击的"+chinese_number(i)+"股劲气相扩。\n"NOR;
        if (!(me->query("neili")<0)) me->add("neili",-i*30);
        if ((random(me->query_skill("force")) > target->query_skill("force")/2))
        {
                me->start_busy(1);
                target->start_busy(i);
                
                damage = (int)me->query_skill("qishang-quan", 1);
                
                damage = damage/2 + random(damage);
                
                target->receive_damage("qi", (int)((i*(2*damage))/6));
                target->receive_wound("qi", (int)((i*damage)/6));
                if (!(target->query("neili")<0)) target->add("neili",-i*20);
     
                msg += HIY"结果$n抵受不住$N的"+chinese_number(i)+"种劲气在体内来回的撞击。"+GRN"\n($n"+HIR"所受的内伤着实不轻。"+GRN")\n"NOR;
                
        } else 
        {
                me->start_busy(1);
                msg += CYN"可是$p忙运内力与$P的"+chinese_number(i)+"种劲气相扩，把之在体内化之无形。\n"NOR;
                if (!(target->query("neili")<0)) target->add("neili",-i*50);
        }
        message_vision(msg, me, target);
        return 1;
}

