// meihua-zhang.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「轻解罗裳」，对准$n的$l轻飘飘的扫去",
		"dodge":		10,
		"parry":		20,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N扬起右手，一招「独上兰舟」便往$n的$l拍去",
		"dodge":		10,
		"parry":		40,
		"damage_type":	"瘀伤"
	]),
		([	"action":		"$N左手虚晃，右手「月满西楼」往$n的l击出",
		"dodge":		20,
		"parry":		60,
		"damage_type":	"瘀伤"
	]),
        ([      "action":               "$N左手微分，右手一长使出一招「雁字回时」，抓向$n的$l",
                "dodge":                50,
                "parry":                80,
                "force":                100,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               "$N倏地一个转身，双手一挑「一种相思」直掼$n的$l",
                "dodge":                10,
                "parry":                120,
                "force":                210,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N左手虚晃，右掌飘飘，一招「两处闲愁」击向$n的$l",
                "dodge":                20,
                "parry":                140,
                "force":                240,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               "$N右手在$n的$l划过，随後一招「才下眉头」左手又向同一方位抓到",
                "parry":                160,
                "force":                300,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               "$N左手虚晃，右手握成拳，一招「却上心头」击向$n的$l",
                "dodge":                20,
                "parry":                160,
                "force":                340,
                "damage_type":  "挫伤"
        ]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练梅花掌必须空手。\n");
	if ((int)me->query_skill("guiyuan-dafa", 1) < 20)
		return notify_fail("你的归元大法火候不够，无法学梅花掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练梅花掌。\n");
	return 1;
}


mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	me->receive_damage("jing", 30);
	return 1;
}
int effective_level() { return 15;}

string *parry_msg = ({
        "$n一招「红藕香残玉簟秋」，右手猛击$N的面门。\n",
        "$n右手虚幌，左手一招「云中谁寄锦书来」，逼得$N后退三步。\n",
        "$n以守为攻，一招「花自飘零水自流」，拂向$N的手腕。\n",
        "$n一招「此情无计可消除」，轻轻一托$N的手，引偏了$N的攻势。\n",
});

string *unarmed_parry_msg = ({
        "$n一招「薄雾浓云愁永昼」，逼得$N中途撤招。\n",
        "$n脚走阴阳，一招「东篱把酒黄昏后」，攻$N之必救。\n",
        "$n左手拂下，右手一招「花自飘零水自流」，将$N封于尺外。\n",
        "$n双手齐出，使出一招「此情无计可消除」，$N的功势入泥牛入海，消失得无影无踪。\n",

});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return -20;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
	return __DIR__"meihua-zhang/" + action;
}
