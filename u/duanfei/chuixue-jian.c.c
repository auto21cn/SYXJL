// hantian-chuixue-jian.c 寒天吹雪剑法

inherit SKILL;

mapping *action = ({
([      "action":"\n突然之间，白影急幌，犹如满天雪花向$n扑来，可立时又回到了原地。",
        "force" : 200,
        "dodge" : 100,
        "parry": 100,
        "damage": 400,
        "lvl" : 0,
        "skill_name" : "天河倒泻",
        "damage_type":  "刺伤"
]),
([      "action":"\n$N突然间招法一变，$w忽伸忽缩，招式飘忽轻盈。$n惊骇之中方寸大乱!",
        "force" : 300,
        "dodge" : 100,
        "parry" : 100,
        "damage": 500,
        "lvl" : 8,
        "skill_name" : "雪花漫天",
        "damage_type":  "割伤"
]),
([      "action":"\n$N身形飘忽，有如雪随风舞，几起几落，几进几出，移步到$n的左侧!",
        "force" : 160,
        "dodge" : 150,
        "parry" : 150,
        "damage": 700,
        "lvl" : 15,
        "skill_name" : "雪雨腥风",
        "damage_type":  "刺伤"
]),
([      "action":"$N一声冷笑，剑气以风吹残雪之势向$n席卷而去，一瞬之间，与$n相距已不到一尺，$w随
即递出!",
        "force" : 240,
        "dodge" : 200,
        "parry" : 200,
        "damage": 900,
        "lvl" : 20,
        "skill_name" : "风花雪月",
        "damage_type":  "割伤"
]),
([      "action":"$N飞身跃起，你抬眼一望，但觉得漫天雪花从天直落而下，不由得一呆！",
        "force" : 500,
        "dodge" : 200,
        "parry" : 200,
        "damage": 1000,
        "lvl" : 20,
        "skill_name" : "飞雪连天",
        "damage_type":  "割伤"
]),  
([      "action":"$N一啸冲天，$n眼前仿佛突然出现了满天的$N，满天剑花一起刺向$n!",
        "force" : 220,
        "dodge" : 250,
        "parry" : 250,
        "damage": 1200,
        "lvl" : 30,
        "skill_name" : "雪影风声",
        "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("bahuang-gong", 1) < 100)
                return notify_fail("你的八荒功火候太浅。\n");
        if ((int)me->query_skill("force", 1) < 40)
                return notify_fail("你的基本内功火候太浅。\n");
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
        level   = (int) me->query_skill("hantian-chuixue-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练寒天吹雪剑法。\n");
        me->receive_damage("qi", 25);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"hantian-chuixue-jian/" + action;
}

