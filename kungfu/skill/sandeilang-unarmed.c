// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// king
// 火神子
// [1;31m思过中...[2;37;0m
// 2792324
// 男性
// unarmed
// 蛤蟆三叠浪





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「蛤蟆出浪」，二掌直出，攻向$n的上中下三路.$N纵身一跃，内吸暗运.「蛤蟆出尘」对准$n的头部位缓缓拍出一掌.",
"force" :50,
"dodge" :10,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "出浪试"
]),
// ZHAOSHI :1

([
"action" :"$RED$ $N飞身跃起,后腿跪地,一式「蛤蟆起浪」双手迅猛无比的攻向$n的左肩.$HIW$ $N突然转身,双手又一式「平风起浪」对准$n的双腿轻拍过去.",
"force" :80,
"dodge" :-10,
"damage_type": "瘀伤",
"lvl" : 12,
"skill_name" : "起浪试"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"蛤蟆三叠浪"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"蛤蟆三叠浪"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
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
    level = (int)me->query_skill("sandeilang-unarmed",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
