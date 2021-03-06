// shenghuo-lingfa 圣火令法
// 1997-5-14
inherit SKILL;

string  *msgl = ({
"$N一式「以意相求」忽地放手，$w的尾端向上弹起，以意想不到方位呼的向$n拍去",
"$N平平一令击出，一式「风回路转」，$w在半空古古怪怪的转了个弯，打向$n的$l",
"$N突然一声清啸，双令一招「三虚七实」虚虚实实，是是而非的击向$n的$l",
"$N忽然低头，一式「头头是道」，一个头锤向$n撞去，手中$w却暗中的向$n的$l击去",
"$N突然纵身而起，一式「翻江倒海」连翻三个空心筋斗，白光忽闪，一令向$n的$l砸去",
"$N坐地锤胸，一式「瞒天过海」呼天抢地的哭号，突然间脚踢飞沙，$w向$n疾刺",
"$N默念口诀，$w一招「应左则后」，明指前胸，突地转弯向$n的向心砸去",
"$N以圣火令中的一招「须右仍前」，虚点右臂，$w向$n的胸前的大穴刺去",
"$N一招「无中生有」，不知如何，手中的$w已快速无比的刺向$n的$l",
"$N手中的$w划着一个个圈子，一招「天方地园」裹向$n，$n顿时眼花缭乱"
});
string  *msgc = ({
"$N反守为攻，一招「乱中求胜」，身体斜飞，连环的向$n踢出四脚",
"$N一式「坐地求全」，忽地在地上一坐，左手抱向$n的$l，右手击向“中都”穴",
"$N突然间一式「以进为退」，接着向前一个空心筋斗，凌空落下，双足向$n$l踢去",
"$N呼的一声，一式「庶天蔽日」，纵身半空翻了几个空心筋斗，伸臂向$n的$l抓去",
"$N一个筋斗，一式「万流归宗」，身在半空，落下时右脚的膝盖在$n关顶一脆",
"$N向前一坐，一式「投怀送抱」，撞入$n的怀中，双肘向$n$l的穴道撞去",
"$N坐地锤胸，一式「飞沙走石」，呼天抢地的哭号，突然间脚踢飞沙，单手向$n疾点"
});
int valid_enable(string usage)
{
        return usage == "blade" || usage== "cuff" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        if (!weapon)
        return ([
                "action":msgc[random(sizeof(msgc))],
                "damage":(random(3)+1)*40,
                "damage_type":"瘀伤",
                "dodge":random(20)-random(8),
                "force":random(160)+100
        ]);
        if (weapon->query("id")=="shenghuo ling"||weapon->query("id")=="tie ling")
                return ([
                "action":msgl[random(sizeof(msgl))],
                "damage":(random(3)+1)*45,
                "damage_type":random(2)?"刺伤":"割伤",
                "dodge":random(35)-random(10),
                "force":random(260)+100,
                "post_action":
                (: call_other, WEAPON_D, "bash_weapon" :)
        ]);
        return ([
                "action":"$N挥舞$w对准$n$l一阵乱砍",
                "damage":30,
                "damage_type":"割伤",
                "dodge":30,
        ]);
}
int practice_skill(object me)
{    
       object weapon = me->query_temp("weapon");
       int i;
       if (!weapon)
               return notify_fail("你没有使用的武器。\n");
       if(weapon->query("id") == "shenghuo ling")
            i = 35;
       else if(weapon->query("id") == "tie ling")
            i = 50;
       else return notify_fail("你必须使用令牌。\n");
       if ((int)me->query("qi") < 50)
               return notify_fail("你的体力不够练圣火令法。\n");         
       if ((int)me->query("neili") < 50)
               return notify_fail("你的内力不够练圣火令法。\n");
       me->receive_damage("qi", i);
       me->receive_damage("neili", 35);
       return 1;
}

int valid_learn(object me)
{
    int skill = me->query_skill("shenghuo-lingfa", 1);
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("你的内力不够。\n");
       if ((int)me->query_skill("shenghuo-shengong", 1) < (skill-10))
               return notify_fail("你的圣火神功火候太浅。\n");      
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"shenghuo-lingfa/" + action;
}
