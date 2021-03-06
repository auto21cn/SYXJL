// 飘逸剑法
// bye jfeng
inherit SKILL;
mapping *action = ({
([      "name":   "相见时难别亦难",
        "action" : "$N手中$w轻弹,使的正是飘逸剑法的起手式「相见时难别亦难」，悄然划向$n",
        "force" : 30,
        "dodge" : 20,
        "damage" : 50,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "name":   "黄河远上白云间",
        "action" : "$N长啸一声，轻抚手中的$w,刹那间四周笼着一片剑气，一式[黄河远上白云间]刺向$n的脸上",
        "force" : 50,
        "dodge" : 40,
        "damage" : 60,
        "lvl" : 1,
        "damage_type" : "刺伤"
]),
([      "name":   "无边落木萧萧下",
        "action" : "$N微一吸一口气，脸色变得无比肃穆，手中的$w一抖，剑随心意，正是那一式[无边落木萧萧下]",
        "force" : 70,
        "dodge" : 60,
        "damage" : 80,
        "lvl" : 2,
        "damage_type" : "刺伤"
]),
([      "name":   "白云千载空悠悠",
        "action" : "$N左踏一步，右踏一步，手中$w使出一招「白云千载空悠悠」，剑气横流，已将$n笼罩",
        "force" : 90,
        "dodge" : 30,
        "damage" : 150,
        "lvl" : 3,
        "damage_type" : "刺伤"
]),
([      "name":   "日夜思君不见君",
        "action" : "$N脸带幽怨,轻挥长剑，仿佛剑气中也带着伤感，正是那一式[日夜思君不见君],剑意绵绵的刺向$n",
        "force" : 100,
        "dodge" : 70,
        "damage" : 180,
        "lvl" : 4,
        "damage_type" : "割伤"
]),
([      "name":   "轻舟已过万重山",
        "action" : "$N轻灵的弹起，半空中手里的$w一抖，一式[轻舟已过万重山]闪电般刺向$n",
        "force" : 110,
        "dodge" : 100,
        "damage" : 200,
        "lvl" : 5,
        "damage_type" : "割伤"
]),
([      "name":   "桃花依旧笑春风",
        "action" : "$N面带微笑，使出的剑法竟然是一式[桃花依旧笑春风]无形的刺向$n",
        "force" : 130,
        "dodge" : 120,
        "damage" : 250,
        "lvl" : 6,
        "damage_type" : "割伤"
]),
([      "name":   "莫愁前路无知己",
        "action" : "$N面带忧色，长叹一声，剑意大开大合，使出飘逸剑法的[莫愁前路无知己]，砍向$n",
        "force" : 150,
        "dodge" : 150,
        "damage" : 300,
        "lvl" : 7,
        "damage_type" : "砍伤"
]),
});
int valid_enable(string usage){return (usage== "sword") || (usage== "parry");}
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力不够学飘逸剑法。\n");
        if ((int)me->query_skill("murong-xinfa", 1) < 50)
                return notify_fail("你的慕容心法火候太浅。\n");
        if ((int)me->query_skill("sword", 1) < 50)
                return notify_fail("你的基本剑法火候太浅。\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练飘逸剑法。\n");
        me->receive_damage("qi", 40);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"piaoyi-jianfa/" + action;
}
