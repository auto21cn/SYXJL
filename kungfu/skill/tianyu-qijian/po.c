// tun.c 段家剑法 -气吞山河 
// Written by Doing Lu 1999/1/4

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        object ob;              // 对手的武器
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「九弧破日」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (! objectp(ob = target->query_temp("weapon")))
                        return notify_fail("对方手中并没有武器。\n");

        if( (int)me->query_skill("tianyu-qijian", 1) < 100 )
                return notify_fail("你的天羽奇剑还不够纯熟，不能使用「九弧破日」。\n");

        if ( me->query("neili") < 100)
                return notify_fail("你的内力不够，现在无法使用「九弧破日」。\n");
        me->add("neili", -30);

        msg = HIY
"$N使出天羽奇剑的绝技「九弧破日」，大吼一声：「破」手中"+ weapon->name()+"直刺$n的右手。\n";

        me->start_busy(2);
        if( random( me->query_skill("force") ) > random((int) target->query_skill("force") ) )
        {
                if (ob->query("item_make"))
                {
                        msg += HIR " $p忙用" + ob->query("name") + "招架，只觉得虎口剧震，所幸兵器完好无损。\n" NOR;
                } else
                {
                        msg += HIW " $p连忙招架，只听见「啪」地一声，$p手中的" + ob->name()
                                + "已经断为数截，激飞上天！\n" NOR;
                        ob->unequip();
                        ob->move(environment(target));
                        ob->set("name", "断掉的" + ob->query("name"));
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                }
                target->start_busy(2);
        } else
        {
                msg += "$p真气贯注" + ob->query("name") + "，和$P剑气相交，冒出点点火光。\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}


