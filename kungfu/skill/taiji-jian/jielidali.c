#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招"HIW"「借力打力」"NOR"？\n");

        if(!me->is_fighting())
                return notify_fail(""HIW"「借力打力」"NOR"只能在战斗中使用！\n");

        if((int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力不够！\n");

   if((int)me->query("neili") < 1000 )
     return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("taiji-jian", 1) < 150)
                return notify_fail("你的太极剑级别还不够，连基本的都耍不完全，怎么玩必杀？\n");

        me->delete("env/brief_message");
   target->delete("env/brief_message");

message_vision(HIC"\n$N飞身跃起，如一鹤冲天，啸声中剑已出鞘！\n"NOR,me,target);
message_vision(HIW"$N默念：“连！！”\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIY"$N默念：“沾！！”\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIM"$N默念：“滞！！”\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIB"$N默念：“随！！”\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HIM"$N默念：“缠！！”\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIR"$N默念：“跟！！”！\n"NOR,me,target);                
        me->set_temp("taiji-jian_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIC"\n$N七剑使罢，轻吁口气，回头看了看$n。\n"NOR,me,target);        
        
        me->delete_temp("taiji-jian_perform");

        me->receive_damage("jing", 50);
        me->add("neili", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1);
        return 1;
}

