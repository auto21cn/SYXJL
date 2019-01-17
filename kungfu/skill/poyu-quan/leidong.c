// leidong �׶�����
// by winder 98.12

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount, int amount1);

int perform(object me)
{
        int skill, count, count1;

        if( (int)me->query_temp("leidong") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");
        if( !me->is_fighting() )
                return notify_fail("�׶�����ֻ����ս����ʹ�á�\n");
        if( (int)me->query("neili") < 500  ) 
                return notify_fail("�������������\n");

        count = me->query_str();
        skill = me->query_skill("cuff");
        if( skill < 135  ) 
                return notify_fail("�������ȭ��Ϊ��������\n");

        me->add("neili", -400);
        message_vision( HIM "$N��������һ���������϶�ʱ������ʢ������Խ��Խ�أ�\n" NOR, me);

        count = me->query("str") + (int)(skill/10);
        count1 = me->query("dex") + (int)(skill/10);

        me->add_temp("str", count);
        me->add_temp("dex", count1);
        me->set_temp("leidong", 1);
        me->start_call_out( (: call_other,  __FILE__, "remove_effect", me, count, count1 :), skill/3 );

        return 1;
}

void remove_effect(object me, int amount, int amount1)
{
        if ( (int)me->query_temp("leidong") ) 
        {
                me->add_temp("str", -amount);
                me->add_temp("dex", -amount1);
                me->delete_temp("leidong");
                tell_object(me, CYN"����׶�����������ϣ��������ջص��\n"NOR);
                me->start_busy(4);
        }
}