// 玄铁剑法
#include <ansi.h>;

inherit SKILL;

string  *msg = ({
"$N当胸平平刺出一剑，实在是毫无任何变化，而却有轰轰之声，$n只觉
一股大力由$w直逼周身",
"$N凌空跃起，身随剑起，借助下行之势向下猛劈一剑，将$n周身笼于剑气之下",
"$N轻叹一声，随手横劈一剑，缓缓指向$n，看似无丝毫变化，却尽得剑
法精髓，当真平淡中蕴涵所有变化，无招胜有招",
"$N迅疾挑出一剑，此剑之快，匪夷所思，无法分辨剑路去来，顺刺，逆击，横
削，倒劈，无不是剑法的入门，当真返朴归真，却已不再存任何破绽",
"$N仰首长啸，令风云变幻，狂风遽起，旋及一剑平指，剑气弥漫于$n周
身各处，$n只觉身处惊涛骇浪之中", 
"$N祭起$w，左手捏成剑诀，咄喝一声，正是剑法至尊的 [ 御剑式 ]，空
中满是剑影，宛若千道银链，只在$n身边游动",
"$N连出十余剑，一时迅疾如流星划空，一时凝重迟缓，招招无迹可寻，平淡至
极又匪思至极", 
"$n却见$N剑势如虹，快似闪电，无可当锋，惊怖中更觉$N剑力有如海潮一
般，一波一浪阵阵涌来，绵延不绝，愈发愈强",
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}
mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(3)+1)*40,
                "damage_type":random(2)?"刺伤":"割伤",
                "dodge": random(10)-5,
                "force":300+random(50),
        ]);
}

int practice_skill(object me)
{    
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
       if ((int)me->query("qi") < 40)
                return notify_fail("你的体力不够练玄铁剑法。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -15);
        return 1;        
}

int valid_learn(object me)
{
       int skill = me->query_skill("xuantie-jianfa", 1);
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("你的内力不够。\n");
       if ((int)me->query_skill("yunu-xinjing", 1) < (skill-50))
               return notify_fail("你的玉女心经火候太浅。\n");      
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuantie-jianfa/" + action;
}

