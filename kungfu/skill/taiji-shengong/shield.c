#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("��ֻ����̫�����������Լ��ķ�������\n");

        if( (int)me->query("neili") < 200  ) 
                return notify_fail("�������������\n");

        if( (int)me->query_temp("shield") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -150);
        me->receive_damage("qi", 10);

        message_vision(
        HIW "$N����̫���񹦣�ȫ��������һ����֮�У�\n" NOR, me);

        me->add_temp("apply/armor", skill*3);
        me->set_temp("shield", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill*2 :), skill);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->delete_temp("shield");
        tell_object(me, "���̫�����˹���ϣ���⽥����ȥ��\n");
}