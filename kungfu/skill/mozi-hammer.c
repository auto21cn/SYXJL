// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// lks
// 兰特
// 白驼山派第二代弟子
// 2149672
// 男性
// hammer
// 墨子剑法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N将手中$w舞个水泻不通，突然剑鞘从一个不可思议的角度直刺$n的咽喉。",
"force" :50,
"dodge" :20,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "以守代攻"
]),
// ZHAOSHI :1

([
"action" :"$N使出墨子补遗三大杀招中的“以攻为守”之旋风式，$w弹上半空，旋转一个圈，力道",
"force" :80,
"dodge" :10,
"damage_type": "瘀伤",
"lvl" : 12,
"skill_name" : "以攻为守"
]),
// ZHAOSHI :2

([
"action" :"$N一声狂喝，使出压箱底的“攻守兼备”，时而轻灵飘逸，时而雷霆万钧，水银泻地的向$n攻去。",
"force" :100,
"dodge" :10,
"damage_type": "瘀伤",
"lvl" : 20,
"skill_name" : "攻守兼备"
]),
// ZHAOSHI :3

([
"action" :"$N仰天长啸，锤风劲啸之声倏然响起，森森芒气，从四面八方涌来，使$n生出身陷千军万马中的感觉。",
"force" :130,
"dodge" :5,
"damage_type": "瘀伤",
"lvl" : 30,
"skill_name" : "寸步难行"
]),
 });
// ZHAOSHI :4
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "hammer") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"墨子剑法"+"。\n");
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
    level = (int)me->query_skill("mozi-hammer",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "hammer") return notify_fail("你使用的武器不对。\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
