// liuyang-zhang.c 天山六阳掌
// cck 10/8/97

inherit SKILL;

mapping *action = ({
([      "action":"$N一着「凤鸣朝阳」，双掌飘飘，盘旋飞舞，着着进迫，向$n的$l直击了过去",
        "force" : 430,
        "dodge" : 40,
        "parry" : 40,
        "damage" : 185,
        "lvl" : 0,
        "skill_name" : "凤鸣朝阳",
        "damage_type":"瘀伤"
]),
([      "action":"$N使一式「阳春白雪」，双掌似有似无，若往若还，朦朦胧胧的击向朝$n的$l",
        "force" : 450,
        "dodge" : 40,
        "parry" : 45,
        "damage" : 195,
        "lvl" : 20,
        "skill_name" : "阳春白雪",
        "damage_type":"瘀伤"
]),
([      "action":"$N一式「山阳夜笛」，右掌斜引，划出层层圆圈，左掌重重叠叠，横击而出",
        "force" : 480,
                  "dodge" : 50,
                  "parry" : 50,
        "damage" : 200,
        "lvl" : 40,
        "skill_name" : "山阳夜笛",
        "damage_type":"瘀伤"
]),
([      "action":"$N双掌掌心向外，手腕回转运使，一式「阳煦山立」，双掌掌力交织成一片屏障",
        "force" : 490,
                  "dodge" : 60,
                  "parry" : 60,
        "damage" : 210,
        "lvl" : 60,
        "skill_name" : "阳煦山立",
        "damage_type":"劈伤"
]),
([      "action":"$N一式「三阳开泰」，双掌连划三个半圆，此消彼长，有如冬去春来，万般气象",
        "force" : 520,
                  "dodge" : 65,
                  "parry" : 65,
        "damage" : 215,
        "lvl" : 75,
        "skill_name" : "三阳开泰",
        "damage_type":"瘀伤"
]),
([      "action":"$N一式「阳开阴闭」，右掌力微而实，左掌力沉而虚，虚实交互，拍向$n的$l",
        "force" : 540,
                  "dodge" : 70,
                  "parry" : 70,
        "damage" : 320,
        "lvl" : 90,
        "skill_name" : "阳开阴闭",
        "damage_type":"内伤"
]),
([      "action":"$N一式「阳关三叠」，双掌内拢，冷若御风，掌力翩跹不定，上下翻飞，层出不穷",
        "force" : 570,
                  "dodge" : 75,
                  "parry" : 75,
        "damage" : 335,
        "lvl" : 105,
        "skill_name" : "阳关三叠",
        "damage_type":"内伤"
]),
([      "action":"$N一式「阳歌天钧」，双掌一立，却不合拢，气随心使，掌力若有若无，淡淡抹出",
        "force" : 590,
                  "dodge" : 85,
                  "parry" : 80,
        "damage" : 340,
        "lvl" : 120,
        "skill_name" : "阳歌天钧",
        "damage_type":"内伤"
]),
([      "action":"$N一着「燮理阴阳」，有招似无招，奇正、虚实、远近、迂直、阴阳、快慢、进退，尽在无形中",
        "force" : 600,
                  "dodge" : 95,
                  "parry" : 95,
        "damage" : 355,
        "lvl" : 135,
        "skill_name" : "燮理阴阳",
        "damage_type":"瘀伤"
]),
});

int valid_enable(string usage) { return (usage == "strike") || (usage == "parry"); }

int valid_combine(string combo) { return combo=="zhemei-shou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练天山六阳掌必须空手。\n");
        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力不够。\n");
        if ((me->query_skill("bahuang-gong", 1) < 100) && (me->query_skill("beiming-shengong",1)<100))
               return notify_fail("你的内功心法火候太浅。\n");
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
        level   = (int) me->query_skill("liuyang-zhang",1);
                  for(i = sizeof(action); i > 0; i--)
                                         if(level > action[i-1]["lvl"])
                                                                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        int lvl = me->query_skill("liuyang-zhang", 1);
        int i = sizeof(action);
        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练天山六阳掌。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的体力不够练天山六阳掌。\n");
        me->add("jingli", -40);
        me->add("neili", -15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liuyang-zhang/" + action;
}

