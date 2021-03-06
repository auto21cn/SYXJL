// duansi.c 五罗轻烟掌「断思掌」
#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{ 
        object ob;
        string msg;
 
        if( !me->is_fighting() )
                return notify_fail("「断思掌」只能在战斗中使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能用断思。\n");     

        if( (int)me->query("neili") < 100 )
                return notify_fail("你现在的内力不足以运用「断思掌」！\n");

        if( (int)me->query_skill("wuluo-zhang", 1) < 100 )
                return notify_fail("你的五罗轻烟掌不够娴熟，不会使用「断思掌」。\n");

        msg = HIY "$N双目微闭，双掌一合，突然发力，连攻数掌！\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));

          me->add("neili", -250);
          me->start_busy(3);

        return 1;
}
