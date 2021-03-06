// 飞燕掌
// bye jfeng
inherit SKILL;
mapping *action = ({
([      "action" : "$N使一招「飞燕归来」，双手划了个半圈，按向$n的$l",
        "force" : 50,
        "dodge" : 30,
        "damage": 35,
        "skill_name" : "飞燕归来",
        "lvl" : 0,
        "damage_type" : "内伤"
]),
([      "action" : "$N右掌不住向外扫出，是一式「新燕琢泥」，左掌旋转着向$n攻去",
        "force" : 100,
        "dodge" : 60,
        "damage": 105,
        "skill_name" : "新燕琢泥",
        "lvl" : 60,
        "damage_type" : "内伤"
]),
([      "action" : "$N右手经腹前经左肋向前撇出，使一招「燕宴九客」，向$n锤去",
        "force" : 140,
        "dodge" : 100,
        "damage": 200,
        "skill_name" : "燕宴九客",
        "lvl" : 100,
        "damage_type" : "内伤"
]),
([      "action" : "$N右掌不住向外扫出，是一式「燕舞九天」，左掌旋转着向$n攻去",
        "force" : 180,
        "dodge" : 150,
        "damage": 220,
        "skill_name" : "燕舞九天",
        "lvl" : 120,
        "damage_type" : "内伤"
]),
([      "action" : "$N长身而起，双掌幻起漫天掌影攻向$n,正是那一式「燕归南去」。",
        "force" : 100,
        "dodge" : 120,
        "damage": 250,
        "skill_name" : "燕归南去",
        "lvl" : 220,
        "damage_type" : "内伤"
]),
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="fengye-finger"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练飞燕掌必须空手。\n");
        if ((int)me->query_skill("murong-xinfa", 1) < 20)
                return notify_fail("你的慕容心法火候不够，无法学飞燕掌。\n");
        if((int)me->query("max_neili") < 100)
                return notify_fail("你的内力修为不够，无法学飞燕掌。\n");
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
                return notify_fail("你的内力不够。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}
