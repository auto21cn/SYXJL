//lingwu.c 领悟
//write by Ronger 01/99

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string skillname;
	int skill;

	if( !arg )
		return notify_fail("你想自己领悟什么功夫？\n");
	if(me->query("combat_exp") < 2000000)
		return notify_fail("你使劲地想啊想，可是发现什么也领会不到。看来经验还不够。\n");

	if ( me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着呢。\n");

	if ( !(skillname = me->query_skill_mapped(arg)) ) {
		if (arg == to_chinese(arg))
			return notify_fail("好象没这种功夫吧？\n");
	}

	if (!me->query_skill(arg,1))
		return notify_fail("你好象不会「" + to_chinese(arg) + "」吧？\n");

	skill = me->query_skill(arg,1);

	if ( (string)SKILL_D(arg)->type() == "knowledge" )
		return notify_fail( to_chinese(arg) + "只能靠学习来提高。\n");

	if ( (string)SKILL_D(arg)->type() == "martial"
		&& skill * skill * skill / 10 > (int)me->query("combat_exp") )
		return notify_fail("你的实战经验不够，再怎么想也没用。\n");

	if( !SKILL_D(arg)->valid_learn(me) ) return SKILL_D(arg)->valid_learn(me);

	if (skill < 150)
		return notify_fail("你的这门功夫级别太低，无法自己领悟，还是去找师父学习吧。\n");

	if ( me->query("jing") < 20 )
		return notify_fail("你已经很累了，休息一下吧。\n");

	if ( me->query("qi") < 20 )
		return notify_fail("你体力不够了，休息一下吧。\n");

	if ( me->query("neili") <= 5 )
		return notify_fail("你内力不够了，休息一下吧。\n");

        if ( me->query("potential") - me->query("learned_points") <= 0 )
		return notify_fail("你的潜能用完了。\n");

	write(HIY "你盘膝坐下，冥思苦想，似乎对" + to_chinese(arg) + "的体会又深了一层。\n" NOR);
	me->receive_damage("jing",10);
	me->receive_damage("qi",30);
        me->add("learned_points", 1);
	me->add("neili",-5);
        me->improve_skill(arg, me->query_int()/10 * skill/4);

	return 1;
}

int help(object me)
{
	write(@TEXT
指令格式：lingwu <技能种类>

这个指令可以让你自己领悟某项技能。当然，在这之前你必须从实际运用中获
得足够的经验以支持你的这项技能。
TEXT
	);
	return 1;
}

