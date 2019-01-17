// /d/dali/kungfu/liumai-shenjian.c ������

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹ��һ������, ����Сָ��$n��$lһָ��һ���������ٳ�Ѩ�м����߶����̳�һ��������֮�����˳������ϡ�",

        "force" : 200,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��һ���г彣, ������ָһ��, �г彣��ǰ����$n��$l",
        "force" : 200,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nʳָ�촦��ʹ��һ��������, һת��$n��$l��ȥ��",
        "force" : 200,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$NСָһ����ʹ��һ�кͳ彣��ֱ��$n��$l",
        "force" : 200,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��һ�йس彣������ֱ��$n��$l��ȥ��",
        "force" : 200,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N����������˫��Ĵָͬʱ�����ʹ��һ�����̽�, �����������죬�ֱ����$n���������",
        "force" : 300,
        "dodge" : 70,
        "damage" : 120,
        "lvl" : 40,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "finger" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������������\n");
        return 1;
}



mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("liumai-shenjian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                          return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "finger")
                return notify_fail("�������֡�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�������������\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liumai-shenjian/" + action;
}

string *parry_msg = ({
       "���Ǳ�$n������$v�ܿ���\n",
        "����$n����һ�࣬������$v�񿪡�\n",
});

string *unarmed_parry_msg = ({
        "���Ǳ�$p���ˡ�\n",
        "�����$p�����ˡ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
