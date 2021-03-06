// dagou-bang.c 打狗棒法

#include <ansi.h>;
inherit SKILL;
#include "/u/hate/skill/msg.h";

string *xue_name = ({ 
"强间穴","风府穴","大雅穴","灵台穴","悬枢穴",}); 

string  *msg = ({

"$N举起$w，居高临下使一招「打草惊蛇」敲向$n的$l",

"$N手中$w左右晃动，一招「拨草寻蛇」向$n的$l攻去",

"$N施出「拨狗朝天」，$w由下往上向$n撩去",

"$N使出一招「棒打双犬」，听得棒声飒然，横扫$n的$l",

"$N倏地伸出$w，棒头搭在$n的$l上，一招「压肩狗背」，轻轻向下按落",

"$N手中$w高高扬起，一招「立地劈狗」，打向$n的$l",

"$N手中$w横扫左右，一招「扫地赶狗」，舞起一片杖影",

"$N手臂一伸，反手$w向$n打出，好一招「关门打狗」",
 
"$N$w从旁递出，一招「恶狗拦路」，竹棒侧抖旁缠，向外斜甩",

"$N一招「风驰电闪」，手中$w化作两道青光砸向$n的$l",

});


int valid_enable(string usage) { return (usage == "stick") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query_skill("stick", 1) < 30)
                return notify_fail("你的基本棒法太差, 还领会不了打狗棒法。\n");

if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("你的混天气功修为不够。\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力不够。\n");
        
    if ((me->query_skill("dagou-bang",1)>20) && (me->query_skill("begging",1)<180))
        if (me->query_skill("dagou-bang", 1) > me->query_skill("begging", 1)+20)
        return notify_fail("打狗棒法需要相应等级的叫花绝活。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
                i=me->query_skill("begging",1);
                level=me->query_skill("dagou-bang",1);
        if (i>140) i=140+i/10;
                if (level>140) level=140+level/10;

        if ( random(10) > 6
        &&      ( (int)me->query_skill("stick", 1) >= 120 ) 
        &&      ( (int)me->query_skill("dagou-bang", 1) >= 120 )
        &&      ( (int)me->query_skill("force",1) >= 120 )
        &&      ( (int)me->query("neili") >= 500 )
        &&      ( (int)me->query_skill("begging", 1) >= 100 )
        &&      ( (string)weapon->query("id") == "yuzhu zhang" ) ) {
                me->add("neili", -50);
                return ([
                "action": HIG"$N眼中射出一道青芒，手中$w使出"RED"「天下无狗」"HIG"，劈天盖地般攻向$n"NOR,
                "damage": 300,
                "dodge":50,
                "parry":80,
                "force": 600,
                "damage_type": "内伤"]);
        }
return ([
                "action":msg[random(sizeof(msg))],
                "damage":random(50)+i/2+level/2+50,
                "parry":random(i/8)+20+random(level/8),
                                "dodge":random(i/5)+20,
                "force":level+i/2+50+random(50),
                "damage_type": "挫伤",
        ]);
       
}

int practice_skill(object me)
{
        object weapon;
     if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "stick")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("jing") < 40)
                return notify_fail("你的体力不够练打狗棒法。\n");  


        me->receive_damage("jing",30);
        me->add("neili", -15);  
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"dagou-bang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg,name;
    int i,j,damage;
    object weapon, weapon1;     
         name = xue_name[random(sizeof(xue_name))];
    weapon = me->query_temp("weapon");
    weapon1 = victim->query_temp("weapon");
    i = me->query_skill("begging", 1);
    j = me->query_skill("dagou-bang", 1);

    if( damage_bonus < 100 ) return 0;
    

    if(!victim->is_busy() && i > 100 &&
       victim->query("neili") && j > 100 &&
       me->query_skill_mapped("parry") == "dagou-bang" &&
       me->query("neili") > 400 && me->query("max_neili") > 1200 &&
        j > random(victim->query_skill("parry",1))){
       if (random(20)>13){
              switch(random(4)){
            case 0 :
               message_vision(GRN"$N"+weapon->name()+"挥出，以“绊”字诀着地扫去，一绊不中，二绊续至，连环钩盘，绵绵而不绝。\n"NOR,me, victim);
               victim->start_busy(3);
                           if (!random(2))
                           message_vision(HIR"$n纵身稍慢，被"+weapon->name()+"在左胫上一拨，右踝上一钩，扑地倒了。\n"NOR,me, victim);             
               else
                           message_vision(HIR"$n尚未落地，被"+weapon->name()+"又是一挑一打，$n立足不住，仰天一交摔倒。\n"NOR,me, victim);             
               break;
            case 1 :
                message_vision(GRN"$N使出“劈”字诀，挥舞起手中"+weapon->name()+"如狂风暴雨般的打去！\n"NOR,me, victim);
                damage = damage_bonus/10 + random(damage_bonus)/5;
                victim->receive_danage("qi",damage/5);
                                victim->receive_wound("qi", damage/5);
                me->add("neili", -damage/5);
                            break;
                        case 2 :
              message_vision( GRN"$N使出“戳”字诀，手中"+weapon->name()+"直上直下，点东打西，招招向$n的要害戳去！\n"NOR,me, victim);
                damage = damage_bonus/5 + random(damage_bonus)/10;
                victim->receive_wound("qi", damage/2);
                me->add("neili", -damage/2);
              break;
            case 3 :
             message_vision( GRN"$N棒法再变，使出了“转”字诀。但见"+weapon->name()+"化成了一团碧影，猛点$n后心各大要穴。\n"NOR,me, victim);
                           if((!random(5)))
                                {
                                victim->start_busy(2);
                                me->add("neili",-40);
                                victim->receive_damage("qi", me->query_skill("dagou-bang",1)/5+damage_bonus/5);
                                victim->receive_wound("qi", me->query_skill("dagou-bang",1)/10+damage_bonus/5);       
                                 message_vision(HIR"$n被"+weapon->name()+"点中"RED+name+HIR"，受了点伤！\n" NOR,me, victim);
                        }                 
               break;
            }
           } else if (weapon1 && random(20)<7) 
                   {
             switch(random(2)){
            case 0 :
                           if (random(2)!=1){ 
                message_vision( GRN"$N"+weapon->name()+"疾翻，搭在"+weapon1->name()+"尺许之处，运起“引”字诀，顺势向外牵引! \n"NOR,me, victim);
               } else {
              message_vision( GRN"$N"+weapon->name()+"缩回，使起“挑”字诀，搭住"+weapon1->name()+"向上甩出，将$n疾奔的力道传到"+weapon1->name()+"上! \n"NOR,me, victim);
                           }
                           victim->start_busy(1);
                           if (!random(4)){
                         message_vision( HIR"$n只感"+weapon1->name()+"似欲脱手飞出，一个把握不住，手中兵器被对方夺了过去。\n"NOR,me, victim);            
               weapon1->unequip();
               weapon1->move(environment(victim));
                           }
                           break;
            case 1 :
              message_vision( GRN"$N使个“缠”字诀,"+weapon1->name()+"挥到东，"+weapon->name()+"跟向东，"+weapon1->name()+"打到西，"+weapon->name()+"随到西，如影随形，借力制敌。\n"NOR,me, victim);
               damage = damage_bonus/10 + random(damage_bonus)/5;
                                if ((int)victim->query("jing")<=damage) 
                                 { victim->set("jing",0); }
                                 else {
                 victim->receive_damage("jing", damage); 
                                 }
                victim->start_busy(3);  
                me->add("neili", -damage);    
                           break;
                          }
                  }
           }
}
