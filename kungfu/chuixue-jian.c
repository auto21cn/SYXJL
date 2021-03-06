// chuixue-jian.c 寒天吹雪剑法
:// ghost 31/5/2000

inherit SKILL;


mapping *action = ({
([      "action":"$n抬眼一望，但见得$N从天直落而下，手中长剑刺向$n的颈部！",
        "force" : 100,
        "dodge" : 100,
        "damage": 100,
        "lvl" : 0,
        "skill_name" : "天降飞雪",
        "damage_type":  "刺伤"
]),
([      "action":"$n抬眼一望，但觉得漫天雪花从天直落而下，不由得一呆！",
        "force" : 150,
        "dodge" : 150,
         "damage": 150,
        "lvl" : 0,
        "skill_name" : "雪花漫天",
        "damage_type":  "刺伤"
]),
([      "action":"$n抬眼一望，但觉得狂风暴雨般得漫天雪花刺向$n，不由得一呆！",
        "force" : 200,
        "dodge" : 200,
        "damage": 200,
        "lvl" : 25,
        "skill_name" : "雪花分飞",
        "damage_type":  "刺伤"
]),
([      "action":"$n抬眼一望，但觉得风吹雪花般的剑气向$n袭来，不由得一呆！",
        "force" : 250,
        "dodge" : 250,
        "damage": 250,
        "lvl" : 5,
        "skill_name" : "风卷残雪",
        "damage_type":  "刺伤"
]),
([      "action":"$n抬眼一望，但觉得满天都是$N的影子，不由得一呆！",
        "force" : 500,
        "dodge" : 500,
        "damage": 500,
        "lvl" : 10,
        "skill_name" : "雪影无踪",
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "parry"; 
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
        level   = (int) me->query_skill("chuixue-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


