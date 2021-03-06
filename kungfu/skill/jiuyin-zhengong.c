// jiuyin-zhao.c 九阴白骨爪

#include <ansi.h>
inherit SKILL;
mapping *action_claw = ({
([ "action" : BLU"$N势若疯虎，形若邪魔，双爪如钢抓铁钩，左手手腕翻处，右手疾伸，五根手指抓向$n$l"NOR,
   "force" : 150,
   "damage" : 30,
   "dodge" : 5,
   "lvl" : 0,
   "damage_type" : "抓伤"
]),
([ "action" : BLU"突然人影闪动，$N迫到$n身后，袖中伸出手，五根手指向$n$l插了下去"NOR,
   "force" : 200,
   "weapon" : "五指",
   "damage" : 50,
   "dodge" : 10,
   "lvl" : 10,
   "damage_type" : "刺伤"
]),
([ "action" : BLU"$N手臂关节喀喇一响，手臂斗然长了半尺，一掌按在$n$l，五指即要插进"NOR,
   "force" : 250,
   "weapon" : "手指",
   "damage" : 60,
   "dodge" : 5,
   "lvl" : 20,
   "damage_type" : "刺伤"
]),
([ "action" : BLU"$N双手微张，十根尖尖的指甲映出灰白光忙，突然翻腕出爪，五指猛地插落"NOR,
   "force" : 300,
   "weapon" : "手爪",
   "damage" : 70,
   "dodge" : 5,
   "lvl" : 30,
   "damage_type" : "刺伤"
]),
([ "action" : BLU"$N左手突然在$n眼前上围下钩，左旋右转，连变了七八般，蓦地里右手一伸，五根手指直插$n$l"NOR,
   "force" : 350,
   "weapon" : "五根手指",
   "damage" : 80,
   "dodge" : 5,
   "lvl" : 40,
   "damage_type" : "刺伤"
]),
});

mapping *action_strike = ({
([ "action" : HIC"$N双掌不住地忽伸忽缩，手臂关节喀喇声响，右掌一立，左掌啪的一下朝$n$l击去"NOR,
   "force" : 150,
   "dodge" : 15,
   "lvl" : 0,
   "damage_type" : "瘀伤"
]),
([ "action" : HIC"$N身形挫动，风声虎虎，接着朝$n连发八掌，一掌快似一掌，一掌猛似一掌"NOR,
   "force" : 250,
   "dodge" : 5,
   "lvl" : 10,
   "damage_type" : "瘀伤"
]),
([ "action" : HIC"$N攸地变爪为掌，身子不动，右臂陡长，潜运内力，一掌朝$n$l劈去"NOR,
   "force" : 300,
   "weapon" : "掌缘",
   "damage" : 30,
   "dodge" : 5,
   "lvl" : 20,
   "damage_type" : "割伤"
]),
([ "action" : HIC"$N一声怪啸，形如飘风，左掌已如风行电挚般拍向$n，掌未到，风先至，迅猛已极"NOR,
   "force" : 350,
   "dodge" : 10,
   "lvl" : 30,
   "damage_type" : "瘀伤"
]),
});
int valid_enable(string usage)
{ 
     return usage=="claw" || usage=="parry" 
            || usage=="strike"; 
}

int valid_learn(object me)
{
       if( (int)me->query_skill("jiuyin-zhengong", 1 ) >= 140 )
               return notify_fail("你现在不能学习九阴真功。\n");
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("练九阴真功必须空手。\n");
       if ((int)me->query_skill("claw", 1) < 41)
               return notify_fail("你的基本爪功火候不够，无法学习。\n");
       if ((int)me->query_skill("strike", 1) < 41)
               return notify_fail("你的基本掌法火候不够，无法学习。\n");
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("你的内力太弱，无法练九阴真功。\n");
       return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action_claw)-1; i >= 0; i--)
                if(level >= action_claw[i]["lvl"])
                        return action_claw[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("jiuyin-zhengong",1);

        if (me->query_temp("9yin_claw")) {
                me->add_temp("9yin_claw", -1);
                for(i = sizeof(action_claw); i > 0; i--)
                  if(level >= action_claw[i-1]["lvl"])
                    return action_claw[NewRandom(i, 20, level/5)];
        }
        else{
             if(random(5) >= 3)
                me->add_temp("9yin_claw", 1);
             for(i = sizeof(action_strike); i > 0; i--)
               if(level > action_strike[i-1]["lvl"])
                  return action_strike[NewRandom(i, 20, level/5)];      
        }
}

int practice_skill(object me)
{
       object *ob;   
       int i;
       if( me->query("family/master_name") != "周芷若")
               return notify_fail("你现在不能练习九阴真功。\n");
       if( !present("corpse", me))
               return notify_fail("你手中没有骸骨，现在不能练习九阴真功。\n");
       if( (int)me->query_skill("jiuyin-zhengong", 1 ) >= 140 )
               return notify_fail("你现在不能练习九阴真功。\n");
       if ((int)me->query("qi") < 30)
               return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("你的内力不够练九阴真功。\n");

       ob = all_inventory(environment(me));
       for(i=0; i<sizeof(ob); i++) {
       if( !living(ob[i]) || ob[i]==me ) continue;
       message_vision(HIR"$N正在用五指插向手中的骸骨，见到这里有旁人，$N不禁要杀人灭口。\n"NOR, me);
       if( !ob[i]->is_killing(me) )  me->kill_ob(ob[i]);
       }
       me->receive_damage("qi", 30);
       me->add("neili", -10);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jiuyin-zhengong/" + action;
}


void skill_improved(object me)
{
    tell_object(me, "你练着练着忽然从心底生出一股邪念！\n");
    me->add("shen", -(me->query_skill("jiuyin-zhengong", 1)*50));
}
