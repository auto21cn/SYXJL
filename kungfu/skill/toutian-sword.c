// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// mkung
// ����
// Ѫ���ŵ��������
// 3651697
// ����
// sword
// ͵�콣��





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N����Ծ��һʽ���н����ҡ���ֻ�����콣������$nȫ��",
"force" :50,
"dodge" :20,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "�н�����"
]),
// ZHAOSHI :1

([
"action" :"$N������Х��һʽ���н����ҡ���ֻ��һ������ֱ��С����ǰҪ��",
"force" :80,
"dodge" :10,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "�н�����"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"͵�콣��"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
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
    level = (int)me->query_skill("toutian-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!