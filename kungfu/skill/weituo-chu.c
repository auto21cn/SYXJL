inherit SKILL;
 
 mapping *action = ({
 ([

"action":"$N跃在半空，一招「仙鹤展翅入灵山」，手中$w已化成无数棍影，令$n
眼花缭乱，不知所措，连连倒退",
         "force" : 350,
         "dodge" : 10,
         "parry" : 10,
         "damage": 70,
         "lvl" : 20,
         "skill_name" : "仙鹤展翅入灵山",
         "damage_type":"挫伤"
 ]),
 ([

"action":"$N挺$w将$n的$W架住，顺势一招「玉马衔环拜仙宫」，$w上下左右飞快
搅动，身随棍走，向$n压了下来",
         "force" : 380,
         "dodge" : 10,
         "parry" : 15,
         "damage": 75,
         "lvl" : 25,
         "skill_name" : "玉马衔环拜仙宫",
         "damage_type":"挫伤"
 ]),
 ([

"action":"$N一招「鸣鹿踏蹄觅仙草」，屈膝俯身，手中$w连点$n下盘，却未等招数用老，猛的
一提，向$n的胸腹间戳去",
         "force" : 420,
         "dodge" : 15,
         "parry" : 20,
         "damage": 70,
         "lvl" : 30,
         "skill_name" : "鸣鹿踏蹄觅仙草",
         "damage_type":"挫伤"
 ]),
 ([

"action":"$N突然滚到在地，$n错愕间，一招「金鲤跃水潜天池」，竟从$n的裆下窜过，更不回头，
$w反手扫向$n的$l",
         "force" : 450,
         "dodge" : 20,
         "parry" : 25,
         "damage": 75,
         "lvl" : 40,
         "skill_name" : "金鲤跃水潜天池",
         "damage_type":"挫伤"
 ]),
 ([

"action":"$N一招「灵猿献果赴蓬莱」，身形如电，绕着$n飞快奔跑，手中$w一招快似一招，
刹那间向$n连打出十六棍",
         "force" : 480,
         "dodge" : 30,
         "parry" : 30,
         "damage": 70,
         "lvl" : 50,
         "skill_name" : "灵猿献果赴蓬莱",
         "damage_type":"挫伤"
 ]),
 ([

"action":"$N大踏步上前，劲贯双臂，手中$w大开大阖，呼呼风声中一招「飞鹰盘旋扫乾坤」
扫向$n的腰间",
         "force" : 490,
         "dodge" : 30,
         "parry" : 40,
         "damage": 70,
         "lvl" : 70,
         "skill_name" : "飞鹰盘旋扫乾坤",
         "damage_type":"挫伤"
 ]),
 ([

"action":"$N大喝一声，一招「天龙出水腾宇宙」，$w脱手飞出，夹着劲风射向$n的前心，随即抢
到$n的身后，伸手又把$w抄在手中",
         "force" : 530,
         "dodge" : 50,
         "parry" : 40,
         "damage": 80,
         "lvl" : 100,
         "skill_name" : "天龙出水腾宇宙",
         "damage_type":"挫伤"
 ]),
 ([
"action":"$N双目圆睁，口中默诵真言，一招「白象卷云憾天柱」，$w似有千斤，缓缓举起，
又缓缓向$n的当头砸落",
         "force" : 550,
         "dodge" : 60,
         "parry" : 50,
         "damage": 100,
         "lvl" : 120,
         "skill_name" : "白象卷云憾天柱",
         "damage_type":"挫伤"
 ]),
 });
 
 int valid_enable(string usage) { return  (usage == "club") || (usage ==
 "parry"); }
 
 int valid_learn(object me)
 {
         if ((int)me->query("max_neili") < 100)
                 return notify_fail("你的内力不够。\n");
         if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
                 return notify_fail("你的混元一气功火候太浅。\n");
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
         level   = (int) me->query_skill("weituo-chu",1);
         for(i = sizeof(action); i > 0; i--)
                 if(level > action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
 }
 
 int practice_skill(object me)
 {
         object weapon;
 
         if (!objectp(weapon = me->query_temp("weapon"))
                  || (string)weapon->query("skill_type") != "club")
                 return notify_fail("你使用的武器不对。\n");
         if ((int)me->query("jing") < 50)
                  return notify_fail("你的体力不够练韦陀杵。\n");
           me->receive_damage("jing", 20);
         return 1;
}

