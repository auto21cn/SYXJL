// miejian.c  回风拂柳剑  (灭剑)
//create bye cuer
#include <ansi.h>
inherit F_SSERVER;
void end(object,int);
int perform(object me, object target)
{       
        object weapon, ob;        int damage;
        string msg;
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");       
               if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("灭剑只能对同地方的对手使用。\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("灭剑攻击只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("fuliu-jian", 1) < 80 )
                return notify_fail("你的回风拂柳剑不够娴熟，不会使用「灭剑」。\n");
        if( (int)me->query_skill("linji-zhuang", 1) < 30 )
                return notify_fail("你的临济十二庄不够高，不能用内力使出灭剑。\n");
        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("你现在内力太弱，不能使出灭剑。\n");
        if( target->query_temp("sword")==1)
                return notify_fail(target->query("name")+"正被你的攻势所吓，快功击啊。 \n");
        msg = CYN "$N突然向发了疯似的狂刺猛砍冲向$n。\n"NOR;
        me->add("neili", -100);
        me->start_busy(1);              
        if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        { 
                msg += CYN"$p被吓得浑身发抖，使不出全力！\n"NOR;
                target->start_busy(2);
                me->add("neili",-100);          
                damage=me->query_skill("fuliu-jian",1);
                damage=0-damage/8-random(damage/8);
                if(!target->query_temp("apply/attack"))
                    target->set_temp("apply/attack",damage);
                else 
                    target->add_temp("apply/attack",damage);
                if(!target->query_temp("apply/defense"))
                    target->set_temp("apply/defense",damage);
                else 
                    target->add_temp("apply/defense",damage);
                target->set_temp("sword",1);
                call_out("end",30,target,damage);
        }                                                 
        else
        { 
                msg += HIR"$p沉着应战，一点都不受影响！\n"NOR;              
        }
        message_vision(msg, me, target);
        return 1;
}

void end(object target,int damage)
{
  target->delete_temp("sword");
  target->add_temp("apply/attack",0-damage);
  target->add_temp("apply/defense",0-damage);
  message_vision(RED"$N终于从灭剑的阴影里恢复了出来。\n"NOR,target);
}
