//kuangwu.c 魔蛇狂舞

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

        if(!me->is_fighting())
              return notify_fail("「魔蛇狂舞」只能在战斗中使用！\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你的真气不够！\n");

        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力不够！\n");
       
        if (!objectp(weapon = me->query_temp("weapon"))
            || weapon->query("skill_type") != "staff"
            || me->query_skill_mapped("staff") != "lingshe-zhangfa"
            || me->query_skill_mapped("force") !="hamagong")
                return notify_fail("你现在无法使用『魔蛇狂舞』。\n");

        if(me->query("family/master_name")!="欧阳锋")
                return notify_fail("你没有经过欧阳锋的指点，无法领悟此招的精髓！\n");

        if((int)me->query_skill("lingshe-zhangfa", 1) < 150)
                return notify_fail("你的灵蛇杖法等级不够，无法使用『魔蛇狂舞』！\n");
 
        if((int)me->query_skill("hamagong", 1) < 150)
                return notify_fail("你的蛤蟆功等级不够，无法使用『魔蛇狂舞』！\n");
             weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           message_vision(HIY"\n$N将蛤蟆功凝于气海穴，口中发出「咕、咕」的声音......n"NOR, me);
           message_vision(HIB"\n突然只见$N使出灵蛇杖法最后一招『魔蛇狂舞』！\n"NOR, me);
              me->set("lingshe", 7);
           message_vision(HIR"\n魔\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

           me->set("lingshe", 9);
           message_vision(HIY"\n蛇\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

           me->set("lingshe", 8);
           message_vision(HIB"\n狂\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

           me->set("lingshe", 9);
           message_vision(MAG"\n舞\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));  
           message_vision(HIW"\n$N趁内力回归丹田之前奋力又发数招！\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           message_vision(HIC"\n$N无法控制内息流动，只好后跃收招。\n"NOR, me, weapon);

           me->delete("lingshe");

           me->add("neili", -100);

          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(4);
   return 1;
}


