// nizhuan.c 逆转九阴

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( !target ) target = me;
        
        //if(me->query("oyf_hamagong") < 2) 
          //      return notify_fail("逆运蛤蟆功使经脉倒转？找死啊？\n");
        if((int)me->query("neili") < 300  ) 
                return notify_fail("你的内力不够。\n");
        if((int)me->query("jingli") < 200  ) 
                return notify_fail("你的精力不够。\n");
        if((int)me->query_temp("nizhuan") ) 
                return notify_fail("你已经逆运了九阴。\n");

        skill = me->query_skill("force") / 2;
        skill = skill + me->query_skill("hamagong");
        skill = skill / 2;
        me->add("neili", -200);
        me->add("jingli", -20);
        me->receive_damage("qi", 0);

        message_vision(
        HIW "$N双手撑地，口中发出一连窜低喉声，一股股内劲勃发使$N双足离地，呈头下足上之势。\n" NOR, me);
        tell_object(me, HIW "你感觉体内蛤蟆功随九阴逆转，好像有股巨大的力量要崩发出来一样。\n" NOR);

        me->add_temp("apply/parry", skill);
          me->add_temp("apply/strength",skill/2);
        me->set_temp("nizhuan", 1);

        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
          me->add_temp("apply/strength", - amount/2);
            me->add_temp("apply/parry",- amount);
        me->delete_temp("nizhuan");
        tell_object(me, HIW "你逆转九阴运功过久，经脉又渐渐复原。\n" NOR);
}

