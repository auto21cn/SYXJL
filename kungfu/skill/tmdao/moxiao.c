
// moxiao ħЦ
// 99.2.1  by Bless

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
object weapon;
int i,j;

if( !target ) target = offensive_target(me);

if( !target || !target->is_character()|| !me->is_fighting(target) )

 return notify_fail("��ħЦ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
/*
if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail("����ʹ�õ���������\n");
*/
    if (me->query("family/family_name") != "�������" )
        return notify_fail("�㲻��������̵��ӣ�����ʹ�����������\n");
if ( (int)me->query_int() < 35 )
 return notify_fail("������첻�㣬��������ħЦ�߻������\n");


if( (int)me->query_skill("tmdao", 1) < 101 )
 return notify_fail("�����ħ����������죬����ʹ�á�ħЦ����������\n");

if( (int)me->query_skill("tmdafa", 1) < 101 )
 return notify_fail("�����ħ�󷨲�����񣬲���ʹ�á�ħЦ����������\n");

if( (int)me->query("neili")<500)
 return notify_fail("����������̫��������ʹ�á�ħЦ����������\n");

if( (time()-(int)me->query_temp("last_perform_time"))<
  me->query_temp("last_perform_busy") )
 return notify_fail("���������ת��û����ô�졣\n");
me->set_temp("last_perform_time",time());
me->set_temp("last_perform_busy",3);

/* */ if(random(2)==1) {
/* */ i=7;
  message_vision(YEL+"\n$N"+RED+"����೤Ц��������ħ�����������С�\n"NOR,me);
}
else {
/* */ i=6;
 message_vision(YEL+"\n$N"+RED+"����೤Ц��������ħ�����������С�\n"NOR,me);
}

me->start_busy(3);
target->start_busy(2);

me->add("force",-random(200));

/* */ weapon=me->query_temp("weapon");
/* */ for(j=1;j<=i;j++) {
 COMBAT_D->do_attack(me, target, weapon, 1);
}

return 1;
}