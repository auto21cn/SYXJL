// xiangniu-jian.c (selang) 色狼帮降妞剑法

#include <ansi.h>
inherit SKILL;

mapping *action = ({ // 12 招
([      "action":HIC"$N一式「涩情」，手中$w指向自己胸口，剑柄斜斜向外，缓缓划向$n的$l。
右手却向$n胸脯抓去！"NOR,
        "force" : 180,
                  "dodge" : 5,
                  "parry" : 5,
        "damage": 500,
        "lvl" : 0,
        "skill_name" : "涩情",
        "damage_type":"刺伤"
]),
([      "action":HIR"$N身形微侧，左手后摆，右手$w一招「化蝶」，就要扯$n的裤子！"NOR,
        "force" : 230,
                  "dodge" : 10,
                  "parry" : 10,
        "damage": 500,
        "lvl" : 10,
        "skill_name" : "化蝶",
        "damage_type":"刺伤"
]),
([      "action":BLU"$N纵身近前，$w斗然弯弯弹出，剑光爆长，一招「凝烟」，$n一愣
之际，裙子已被剑气掀起，春光大泻！"NOR,
        "force" : 280,
                  "dodge" : 10,
                  "parry" : 15,
        "damage": 550,
        "lvl" : 20,
        "skill_name" : "凝烟",
        "damage_type":"刺伤"
]),
([      "action":YEL"$N左手捏个剑决，平推而出，决指上仰，右手剑朝天不动，一招「子铃」，
刺向$n"NOR,
        "force" : 360,
                  "dodge" : 10,
                  "parry" : 10,
        "damage": 600,
        "lvl" : 31,
        "skill_name" : "子铃",
        "damage_type":"刺伤"
]),
([      "action":HIM"$N剑招忽变，使出一招「怜花」，全走斜势，但七八招斜势
中偶尔又挟着一招正势，瞬间$n的衣服已为剑气所碎！"NOR,
        "force" : 410,
                  "dodge" : 15,
                  "parry" : 20,
        "damage": 500,
        "lvl" : 43,
        "skill_name" : "怜花",
        "damage_type":"刺伤"
]),
([      "action":HIY"$N手中$w剑刃平刺，锋口向着左右，一招「用情」，眼光里满是
柔情蜜意，$n不觉痴了。"NOR,
        "force" : 450,
                  "dodge" : 20,
                  "parry" : 20,
        "damage": 800,
        "lvl" : 52,
        "skill_name" : "用情",
        "damage_type":"刺伤"
]),
([      "action":HIG"$N一招「绝恋」，横提$w，剑尖斜指向地，由下而上，撩向$n的裙带"NOR,
        "force" : 420,
                  "dodge" : 25,
                  "parry" : 30,
        "damage": 850,
        "lvl" : 62,
        "skill_name" : "绝恋",
        "damage_type":"刺伤"
]),
([      "action":RED"$N抢前一步，$w微微抖动，剑光点点，一招「旖旎」，终而复始，
绵绵不绝，$n在似为$N为所吸引，轻轻的倒在了$N的怀中！"NOR,
        "force" : 480,
                  "dodge" : 30,
                  "parry" : 30,
        "damage": 950,
        "lvl" : 74,
        "skill_name" : "江河不竭",
        "damage_type":"刺伤"
]),
([      "action":MAG"$N左手剑鞘一举，快逾电光石光，一招「涟漪」，用剑鞘套住
$n手中兵器，右手向$n的粉脸摸去！"NOR,
        "force" : 460,
                  "dodge" : 40,
                  "parry" : 40,
        "damage": 1000,
        "lvl" : 85,
        "skill_name" : "涟漪",
        "damage_type":"刺伤"
]),
([      "action":HIB"$N翻身回剑，剑诀斜引，一招「雪月」，剑锋从半空中直泻下来，
罩住$n上方"NOR,
        "force" : 540,
                  "dodge" : 35,
                  "parry" : 35,
        "damage": 1050,
        "lvl" : 95,
        "skill_name" : "雪月",
        "damage_type":"刺伤"
]),
([      "action":HIC"$N一式「风流」，$N手中剑花团团，无数影子色迷迷的象$n扑去！"NOR,
        "force" : 500,
                  "dodge" : 40,
                  "parry" : 45,
        "damage": 115,
        "lvl" : 107,
        "skill_name" : "风流",
        "damage_type":"刺伤"
]),
([      "action":HIW"$N腾空而起，突然使出一招「速战」，悄无声息地疾向$n的背部刺去"NOR,
        "force" : 550,
                  "dodge" : 50,
                  "parry" : 55,
        "damage": 600,
        "lvl" : 120,
        "skill_name" : "速战",
        "damage_type":"刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

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
        level   = (int) me->query_skill("xiangniu-jian",1);
                  for(i = sizeof(action); i > 0; i--)
                                         if(level > action[i-1]["lvl"])
                                                                return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"xiangniu-jian/" + action;
}

