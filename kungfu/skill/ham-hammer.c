// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// tony
// ����
// ��������ν����״�����
// 3441498
// ����
// hammer
// ���촸





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
"force" :50,
"dodge" :20,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "��籩��"
]),
// ZHAOSHI :1

([
"action" :"$NԾ���գ�ʹһ�С�ɽ�����ѡ����߾ٽ�������$n�ľ���  ��",
"force" :80,
"dodge" :10,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "ɽ������"
]),
// ZHAOSHI :2

([
"action" :"$N��һ��������ʹ����������ӿ��������ɨ��$n��ͷ��  ��",
"force" :100,
"dodge" :10,
"damage_type": "����",
"lvl" : 20,
"skill_name" : "������ӿ"
]),
// ZHAOSHI :3

([
"action" :"$Nʹһ�С���֮�֡�������������֮����ֱ��$n��ͷ��  ��",
"force" :130,
"dodge" :5,
"damage_type": "����",
"lvl" : 30,
"skill_name" : "��֮��"
]),
// ZHAOSHI :4

([
"action" :"$Nʹһ�С��������桹���͵�һ�����������¶�������$n���ؿ�  ��",
"force" :150,
"dodge" :-5,
"damage_type": "����",
"lvl" : 40,
"skill_name" : "��������"
]),
 });
// ZHAOSHI :5
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "hammer") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"���촸"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage=="hammer" || usage=="parry"; }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level = (int)me->query_skill("ham-hammer",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "hammer") return notify_fail("��ʹ�õ��������ԡ�\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!