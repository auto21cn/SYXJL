// qidingshanhe.c  段家剑法 [气定山河]

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
    string msg;
 
    if( !me->is_fighting() )
            return notify_fail("「段家剑法」绝招只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");

        if((int)me->query_dex() < 35)
                return notify_fail("你的身法不够, 目前还不能使用这项绝技! \n");

        if((int)me->query_skill("kurong-changong",1) < 180)
                return notify_fail("你的枯荣禅功的修为不够, 不能使用这一绝技 !\n");

        if((int)me->query_skill("dodge") < 135)
                return notify_fail("你的轻功修为不够, 不能使用段家剑法绝招！\n");
 
        if((int)me->query_skill("sword") < 135)
                return notify_fail("你的剑法修为不够， 目前不能使用段家剑法绝招! \n");

    if( (int)me->query("neili") < 1200 )
                return notify_fail("你的真气不够！\n");


    msg = HIG "$N使出段家剑法的绝技「气定山河」，大吼一声：＂定！＂身法陡然加快！手中$w脱手直刺$n \n" NOR;
    message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->add("neili", -300);
        me->start_busy(random(2));
    return 1;
}
