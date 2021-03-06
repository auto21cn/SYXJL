
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int number, size;
        object *tar;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这招“十字冥华斩”？\n");

        if((int)me->query("neili") < 1000)
                return notify_fail("你的内力不够！\n");

        if((int)me->query("qi") < 300 )
                return notify_fail("你的气血不足，使不出十字冥华斩。\n");

        if((int)me->query_skill("liusheng-xinyinliu", 1) <150)
                return notify_fail("你的柳生新阴流级别还不够！\n");

        tar=all_inventory(me);
        size = sizeof(tar); 
        
        
        

        me->add("neili", -10);
        me->receive_damage("qi", 200);

        msg = HIC"
$N纵声狂喝，使出了飞雪剑法中的绝招----"NOR MAG"「十字冥华斩」" NOR HIC"！
但见$N的一把剑如出水蛟龙，剑光铺天盖地席卷而来，狂风四起，飞沙走石。
狂风中暗含杀气，剑光霍霍，左一剑，右一剑似十字光华！\n
$n但觉天昏地暗，无处躲藏！\n" NOR;

        ap = me->query_skill("liusheng-xinyinliu", 1);
// + me->query_skill("parry");
        ap = ( ap * ap * ap / (4 * 400) );
// + (int)me->query("qi");
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (4 * 400) );
// + (int)target->query("qi");
        dp = dp*250 + target->query("combat_exp"); 
        if( random((ap + dp)/1000+1) <  dp/1000 ) {
                msg += HIC "$n用尽全身力气纵身向后一跃堪堪避过，惊出了一身冷汗。\n\n"NOR;
                message_vision(msg, me, target);
        } else {
                damage = (int)me->query_skill("liusheng-xinyinliu",1) / 20 +
                        (int)me->query("neili") / 50 + random((int)me->query("neili") / 50 ) +
                        (int)me->query("qi") / 50 + random((int)me->query("qi") / 50 );
                msg += RED "刹那间满天鲜血乱飞，两剑将$n砍得遍体鳞伤，$n一个踉跄，栽倒在地！！\n" NOR;
                if (number < 10) damage +=random(number+1);
                else damage +=random(10);
                        target->receive_damage("qi", me->query("eff_qi")*damage/350, me);
                        target->receive_damage("jing", me->query("eff_jing")*damage/220, me);
                        target->receive_wound("jing", me->query("eff_jing")*damage/400, me);
                        target->receive_wound("qi", me->query("eff_qi")*damage/300, me);
                        target->unconcious();
                        me->improve_skill("liusheng-xinyinliu", 1, 100);
                message_vision(msg, me, target);
                COMBAT_D->report_max_status(target);
         }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        
        me->start_busy(0);
        return 1;
}

