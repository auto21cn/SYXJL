// feifeng-bian.c 飞凤鞭法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":               "$N身形轻盈一转，一招「凤凰展翅」，手中$w舞的笔直，对着$n直刺过去",
        "force":                100,
        "dodge":                10,
        "damage":               100,
        "lvl" : 0,
        "skill_name" : "凤凰展翅",
        "damage_type":  "刺伤"
]),
([      "action":               "$N身形一转，一招「凤翼天翔」，手中$w抖的笔直，突然猛地击向$n太阳穴",
        "force":                150,
        "dodge":                10,
        "damage":               150,
        "lvl" : 10,
        "skill_name" : "凤翼天翔",
        "damage_type":  "劈伤"
]),
([      "action":               "$N唰的一抖$w，一招「百鸟朝凤」，手中$w好似变成了百根长鞭，罩住了$n的周身穴道",
        "force":                200,
        "dodge":                30,
        "damage":               200,
        "lvl" : 20,
        "skill_name" : "百鸟朝凤",
        "damage_type":  "刺伤"
]),
([      "action":               "$N力贯鞭梢，一招「宛如凤凰」，手中$w突然好似变成了一只活凤凰，直刺$n全身各大要穴",
        "force":                200,
        "dodge":                40,
        "damage":               250,
        "lvl" : 30,
        "skill_name" : "宛如凤凰",
        "damage_type":  "刺伤"
]),
([      "action":               "$N运气于腕，一招「百凤求凰」，手中$w舞出漫天鞭影，吓的$n倒退三步",
        "force":                250,
        "dodge":                50,
        "damage":               300,
        "lvl" : 40,
        "skill_name" : "百凤求凰",
        "damage_type":  "内伤"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        object weapon;

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

        return 1;
}

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
        level   = (int) me->query_skill("feifeng-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练飞凤鞭法。\n");
        me->receive_damage("qi", 5);
        return 1;
}
