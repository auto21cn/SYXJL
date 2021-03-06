// fanyun-zhang.c 翻云掌

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一式「碧海连天」，左掌微拂，右掌乍伸乍合，猛地插往$n的$l",
	"force" : 180,
	"dodge" : 5,
	"parry" : 20,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "碧海连天",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N掌心隐隐发红，一式「天光血影」，掌力如海水般向$n击去",
	"force" : 240,
	"dodge" : 10,
	"parry" : 25,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "天光血影",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N身形往上一纵，使出一式「月落星辰」，双掌一摊，笔直地向$n的$l拍去",
	"force" : 300,
	"dodge" : 15,
	"parry" : 30,
	"damage": 45,
	"lvl" : 40,
	"skill_name" : "月落星辰",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N身形一变，使一式「天残地缺」，双掌带着萧刹的劲气，猛地击往$n的$l",
	"force" : 360,
	"dodge" : 20,
	"parry" : 35,
	"damage": 60,
	"lvl" : 60,
	"skill_name" : "天残地缺",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N突地一招「紫燕追魂」，双掌挟着一阵风雷之势，猛地劈往$n的$l",
	"force" : 420,
	"dodge" : 35,
	"parry" : 40,
	"damage": 75,
       "lvl" : 80,
	"skill_name" : "云海波涛",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N一式「旭光普照」，身形向上窜起丈余，双掌一高一低，看似简单，却令$n无法躲闪",
	"force" : 480,
	"dodge" : 40,
	"parry" : 50,
	"damage": 90,
	"lvl" : 100,
	"skill_name" : "旭光普照",
	"damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练六合掌必须空手。\n");
	if ((int)me->query_skill("wuxin-jing", 1) < 20)
		return notify_fail("你的无心经火候不够，无法学六合掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练六合掌。\n");
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
	level   = (int) me->query_skill("liuhe-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练六合掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liuhe-zhang/" + action;
}
