// huanying.c  ���е��������λ�Ӱ��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"��ʲô��Ц��ûװ������ôʹ�����λ�Ӱ����\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("�����λ�Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("yanxing-dao", 1) < 60 )
        return notify_fail(WHT"�����е���������죬ʹ���������λ�Ӱ����\n"NOR);
    if ((int)me->query_skill("linji-zhuang", 1) < 90 )
        return notify_fail(RED"���ټ�ׯ��򲻹��������λ�Ӱ��������ʽ��\n"NOR);
    if ((int)me->query("max_neili")<300)
        return notify_fail(RED"���������Ϊ���㣬�޷����㡸���λ�Ӱ����������\n"NOR);
    if ((int)me->query("neili")<200)
    {
        return notify_fail(HIC"����������������û�ܽ������λ�Ӱ��ʹ�꣡\n"NOR);
    }
    msg = HIC "$N���һ����ȫ���Ĵ��ζ���$nֻ����$N����������Ӱ�����쵶\n"NOR;
    msg += HIC"��ϯ��������$n����һ�ܣ���$N������·��$nֻ��סһ����\n"NOR;
    message_vision(msg, me, target);

    me->clean_up_enemy();
    target = me->select_opponent();

    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    me->add("neili", -100);
    me->start_busy(random(5));
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}
