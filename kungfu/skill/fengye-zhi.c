// 枫叶指
// bye jfeng
inherit SKILL;
mapping *action = ({
([      "action" : "$N微抬右臂，右指作出五种变化，一式「笑指长空」击向$n的$l",
        "force" : 60,
        "dodge" : 30,
        "lvl" : 0,
        "damage": 80,
        "skill_name" : "笑指长空",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左肩虚抬，一式「寒梅奔放」，右指疾出，指向$n的胸前",
        "force" : 90,
        "dodge" : 60,
        "lvl" : 1,
        "damage": 100,
        "skill_name" : "寒梅奔放",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「莲花绽开」，右指迸出无数道劲气，蓄势点向$n的$l",
        "force" : 120,
        "dodge" : 100,
        "lvl" : 2,
        "damage": 130,
        "skill_name" : "莲花绽开",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「含沙射影」，右指急点，指端射出一缕罡气，穿过$n的$l",
        "force" : 150,
        "dodge" : 120,
        "lvl" : 3,
        "damage": 170,
        "skill_name" : "含沙射影",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「二月春风」，五指齐发，五股罡气象春风般穿过$n的$l",
        "force" : 180,
        "dodge" : 150,
        "lvl" : 4,
        "damage": 200,
        "skill_name" : "二月春风",
        "damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="feiyan-zhang"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练枫叶指必须空手。\n");
        if ((int)me->query_skill("murong-xinfa", 1) < 50)
                return notify_fail("你的慕容心法火候不够，无法学枫叶指。\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力太弱，无法练枫叶指。\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够枫叶指。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -20);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"fengye-zhi/" + action;
}
