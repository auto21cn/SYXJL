#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/hamagong/test.h";


int exert(object me, object target)
{
        int damage, p;
        string msg;

	 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你的蛤蟆功绝技只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("hamagong", 1) < 100 )
                return notify_fail("你的蛤蟆功还不够熟练，不能使用蛤蟆绝招对敌！\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「蛤蟆功」！\n");

        if (me->query_skill_mapped("force") != "hamagong")
                return notify_fail("你的内功中无此功夫。\n");
/*
//add by cool
        if (interactive(me)&&(int)me->query_condition("hama_po"))
                 return notify_fail(RED "你蛤蟆神功已破，无法使用「蛤蟆」绝招。"NOR);

        if (me->query_skill_prepared("strike") != "hamagong" ||
            me->query_skill_mapped("strike") != "hamagong")
                return notify_fail("你必须先将蛤蟆功运用于掌法之中才行。\n");
*/
        if( (int)me->query("max_neili", 1) < 1500 )
                return notify_fail("你现在内力不足，使不出蛤蟆功的绝招！\n");     

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力不足，使不出蛤蟆功的绝招！\n");     

       // if( (int)me->query_skill("strike", 1) < 100 )
         //       return notify_fail("你的掌法不够娴熟，使不出蛤蟆功的绝招！\n");

        if (me->query_str() < 30 )
                return notify_fail("你的力量太小，使不出用蛤蟆绝招！\n");

        msg = BLU "\n$N身子蹲下，左掌平推而出，使的正是$N生平最得意的「蛤蟆功」绝招，掌风直逼$n而去！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") /3 )
        {                     
                me->start_busy(1);
                target->start_busy(1); 
                me->add("neili", -200);
                me->add("qi", -20);
                damage = (int)me->query_skill("hamagong", 1);                
               // damage = damage*2 + random(damage);
                damage = damage + random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
        } else 
        {
                me->start_busy(3);
                target->start_busy(1);
                me->add("neili", -100);
    msg += HIY"\n$p但觉一股微风扑面而来，风势虽然不劲，然已逼得自己呼吸不畅，知道不妙，连忙跃开数尺。\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage;
        string msg;

        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = BLU "\n$N左掌劲力未消，右掌也跟着推出，功力相叠，「蛤蟆功」掌风排山倒海般涌向$n！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("hamagong", 1) > 124 )
        {                
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -400);
                me->add("qi", -30);                
                damage = (int)me->query_skill("hamagong", 1);                
                //damage = damage*3 + random(damage);
                damage = damage + random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);    
        } else 
        {
                me->start_busy(4);
                me->add("neili", -200);
    msg += HIY"\n$p喘息未定，又觉一股劲风扑面而来，连忙跃开数尺，狼狈地避开。\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

int perform3(object me, object target, int p)
{
        int damage;
        string msg;
  
        if(!living(target))
              return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = BLU "\n$N双腿一登，双掌相并向前猛力推出，$n连同身前方圆三丈全在「蛤蟆功」劲力笼罩之下！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 2 &&
            me->query_skill("hamagong", 1) > 149 )
        {
                me->start_busy(4);
                target->start_busy(random(2));
                me->add("neili", -600);
                me->add("qi", -40);                
                damage = (int)me->query_skill("hamagong", 1);                
                //damage = damage*3 + random(damage);
                damage = damage*2 + random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);

                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "瘀伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
                
        } else 
        {
                me->start_busy(5);
                target->start_busy(1);
                me->add("neili", -300);
                target->add("qi", -100);
    msg += HIY"\n$p用尽全身力量向右一纵一滚，摇摇欲倒地站了起来，但总算躲开了这致命的一击！\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}


