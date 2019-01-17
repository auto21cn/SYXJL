// yinsuo-jinling.c ��������

#include <ansi.h>

inherit SKILL;

string  *msg = ({
"$N�����������$w����˦�˳�����ֱ��$n��$l����һ������������Ϣ����
�Ⱦ�û�������",
"$N�ֳ�$w��ʸ�����߻���$n���ټ���ö���򲻶Ϸ�������֮����������������",
"�����ý����з����������죬���䲻��ȴ��ʮ�ֹ��죬�������ҡ�ǡ�$n
��֮�£�����������$w�������缱�Ӷ���",
"$N����΢����$w������ȥ�����¶��ϣ�����$n����$l���ġ��Ϲ�Ѩ��",
"$N˫����ӣ�����$w����ˮ�߰����Ѷ������������죬���������������죬
$n�����ϵġ����Ѩ������$w����",
"$N΢΢һЦ��ǰһ��������$wһ����$w��ز���裬�ñȲʷﳯ��һ�����$n",
});

int valid_enable(string usage)
{ 
    return (usage == "whip") || (usage == "parry"); 
}

mapping query_action(object me, object weapon)
{
    return ([
           "action":msg[random(sizeof(msg))],
           "damage":(random(3)+1)*50,
           "damage_type":random(2)?"����":"����",
           "dodge":random(55)-random(15),
           "force":random(300)+100
           ]);
}

int valid_learn(object me)
{
       object weapon;

       if( (int)me->query("max_neili") < 500 )
               return notify_fail("����������㣬û�а취����������, ����Щ���������ɡ�\n");
       if ((int)me->query_skill("yunu-xinjing", 1) < 100)
               return notify_fail("�����Ů�ľ��ڹ����̫ǳ��\n");
       if ( !objectp(weapon = me->query_temp("weapon"))
       || ( string)weapon->query("skill_type") != "whip" )
               return notify_fail("��ʹ�õ��������ԡ�\n");
       return 1;
}
 
int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "whip")
               return notify_fail("��ʹ�õ��������ԡ�\n");
       if ((int)me->query_skill("yunu-xinjing", 1) < 100)
               return notify_fail("�����Ů�ľ��ڹ����̫ǳ��\n");
         if ((int)me->query("jing") < 50)
               return notify_fail("��������������������塣\n");
       if ((int)me->query("neili") < 30)
               return notify_fail("��������������������塣\n");
        me->receive_damage("jing", 35);
         me->add("neili", -15);
       return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
      object weap,weap1;
      weap = victim->query_temp("weapon");
      weap1 = me->query_temp("weapon");
     if( (me->query_skill("yinsuo-jinling") > 80) && (me->query("neili") > 700)
       && (victim->query_temp("weapon")) 
       && random(10) > 7){
       message_vision(HIY "ֻ��$N���ٻ���" + weap1->name() + "��ת����������СȦ�ӣ�������֮����ס�Է���" + weap->name() +"��\n" NOR, me ); 
       victim->start_busy(1);
       if (random(me->query_str()) > victim->query_str()/2 ){
       message_vision(HIY "\n$N�����ֱ�����һק��" + weap->name()
  + "ȴ�޷���"+weap1->name()+"�Ĳ������ѿ����鼱֮��ֻ�÷��������еı��С�\n" NOR, victim );
       weap->move(environment(me));
       victim->reset_action();
       } else {
      message_vision(HIY "\n$N�����ɾ���" + weap->name()
   + "˳�ŷ��������ת���£��⿪��"+weap1->name()+"�Ĳ��ơ�\n" NOR, victim );
      victim->add("neili", -50);
      }
      me->add("neili", - (20+random(30)));
      }
      return 1;
}

string perform_action_file(string action)
{
      return __DIR__"yinsuo-jinling/" + action;
}
