// huagong-dafa.c 化功大法
// by QingP

inherit SKILL;

int valid_enable(string usage)
{
	return usage=="poison";
}

int valid_learn(object me)
{
	if ((int)me->query_skill("beiming-zhenqi", 1) < 100)
		return notify_fail("你的北冥真气功力不够，不能学化功大法。\n");

	if ((int)me->query_skill("poison", 1) < 130)
		return notify_fail("你的基本毒功不够娴熟，不能学化功大法。\n");

	if ( !me->query_skill("beiming-zhenqi",1))
		return notify_fail("你不先学会北冥真气，怎能学化功大法？\n");

	if ( !me->query_skill("poison",1))
		return notify_fail("你不先学基本毒功，怎能学化功大法？\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练化功大法必须空手。\n");

	return 1;
}

int practice_skill(object me)
{
	object ob;
	
	if ((int)me->query_skill("beiming-zhenqi", 1) < 100)
		return notify_fail("你的北冥真气功力不够，不能学化功大法。\n");

	if ((int)me->query_skill("poison", 1) < 130)
		return notify_fail("你的基本毒功不够娴熟，不能学化功大法。\n");

	if ( !me->query_skill("beiming-zhenqi",1))
		return notify_fail("你不先学会北冥真气，怎能学化功大法？\n");

	if ( !me->query_skill("poison",1))
		return notify_fail("你不先学基本毒功，怎能学化功大法？\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练化功大法。\n");

	if (!objectp(ob = present("shenmu wangding", me)))
		return notify_fail("你没有神木王鼎，怎么练化功大法？！\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练化功大法必须空手。\n");

	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力太差了，不能练化功大法。\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够练化功大法。\n");
	if (me->query_skill("huagong-dafa", 1) < 50)
		me->receive_damage("qi", 20);
	else
		me->receive_damage("qi", 70);
	me->add("neili", -70);
	return 1;
}

void skill_improved(object me)
{
	me->add("shen", -1300);
}

string perform_action_file(string action)
{
	return __DIR__"huagong-dafa/" + action;
}