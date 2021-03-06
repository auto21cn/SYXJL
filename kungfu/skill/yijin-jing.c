// yijin-jing 达摩易筋经

inherit FORCE;
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
#include "/kungfu/skill/force.h"

int valid_enable(string usage)
{
    if((int)this_player()->query_skill("yijin-jing", 1) < 199)
         return usage == "force";
    else return (usage == "force") || (usage == "parry");
}

int valid_learn(object me)
{
        int i, nb, nh;
        nb = (int)me->query_skill("buddhism", 1);
        nh = (int)me->query_skill("yijin-jing", 1);

        if ( me->query("gender") != "男性" )
                return notify_fail("你非童男之体，不能练习易筋经内功。\n");

        if ((int)me->query_skill("buddhism", 1) < 100 && nb <= nh )
                return notify_fail("你的禅宗心法修为不够，无法领会更高深的易筋经内功。\n");

        if ((int)me->query_skill("force", 1) < 15)
                return notify_fail("你的基本内功火候还不够，无法领会易筋经内功。\n");

        if ((int)me->query("guilty") > 0 )
                return notify_fail("你屡犯僧家数戒，无法领会更高深的易筋经内功。\n");

        return valid_public(me);
}


int practice_skill(object me)
{
        return notify_fail("易筋经内功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"yijin-jing/" + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIR + me->name()+"脸上红光隐现，气象庄严" NOR,
    "start_my_msg" : "你五心向天，排除一切杂念，内息顺经脉缓缓流动。\n",
    "start_other_msg" : me->name()+"五心向天，一会工夫，从口鼻处缓缓吐出白气，白气越吐越浓，渐渐笼罩了全身。\n",
    "halt_msg" : "$N长出一口气，将内息急速退了回去，站了起来。\n",
    "end_my_msg" : "你将内息走了个小周天，流回丹田，收功站了起来。\n",
    "end_other_msg" : "只见笼罩"+me->name()+"的白气渐渐消散，又从口鼻处吸了回去。\n"
    ]);
}

string *fanzhen_msg = ({
"只震得$n胸内腹中，有如五脏一齐翻转！\n",
"抢先反震，将$n震得脸如白纸，全无血色！\n",
"震得$n心肺欲裂，腾腾腾连退数步！\n",
"功力已布满全身，将$n的力量反震回去！\n",
"震得$n天旋地转，腾腾腾连退七八步！\n",
"和$n一撞，只震的$p胸口气血翻涌！\n",
"$n便如撞在一堵棉花作面，钢铁为里的厚墙上一般，震退数步！\n",
"$n刚碰到$P，突然身子一震，登时飞了出去！\n",
});

int ob_hit(object ob, object me, int damage)
{
        string msg;
        int p, skill, neili, neili1,  i;
        object weapon;
        skill = me->query_skill("yijin-jing", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

        if(living(me) /*&&
           me->query_temp("fanzhen") &&
           random(skill)+30 > ob->query_skill("parry", 1)/2 &&
           me->query("combat_exp") > ob->query("combat_exp")/2 &&
           skill > 199 &&
           neili > 500 &&
           living(ob) &&
           ob->query("jiali") &&
           !ob->query("env/invisibility")*/)
        {
                if(!objectp(weapon = ob->query_temp("weapon")))
                {
                         me->add("neili", -(10+random(70)));
                         msg = random(2)?HIR"$N身上生出一股反震之力，":HIR"$N身上金刚不坏体神功随心而起，";

                         if(neili1 > neili*3 || damage > 3000)
                         {
                             msg += "但却被$n的劲力一招震碎！\n"NOR;
                             me->delete_temp("fanzhen");
                             damage = random(damage);
                             printf("damage = %d\n", damage);
                         }
                         else if(neili1 > neili*2) msg += "但却根本无法阻挡$n的劲力！\n"NOR;
                         else if(neili1 > neili)
                         {
                                msg += "结果抵消了部分$n的劲力！\n"NOR;
                                damage = -damage/2;
                         }
                        else
                        {
                                 msg += fanzhen_msg[random(sizeof(fanzhen_msg))]+NOR;
                                 if(neili > neili1*4) i = 4;
                                 else if(neili > neili1*3) i = 3;
                                 else if(neili > neili1*2) i = 2;
                                 else i = 1;
                                 i *= damage/2;
                                 if(ob->query_skill("force") > me->query_skill("force")) i = i*2/3;
                                 if(i < 10) i = 10;
                                 ob->receive_damage("qi", i, me);
                                 ob->receive_wound("qi", i/5);
                                 p = ob->query("qi")*100/ob->query("max_qi");
                                 msg += "( $n"+eff_status_msg(p)+" )\n";
                                 if(wizardp(me)) tell_object(me, "Fanzhen damage: "+i+"。\n");
                                 damage = -damage;
                         }
                         message_vision(msg, me, ob);
                         return damage;
                 }
                 else
                 {
                         msg = HIR"好似有一堵无形的墙在$N面前阻挡着，";
                         if(neili > neili1*3)
                         {
                                 msg += "结果$n"HIR"一下子被反弹，震得"+ob->name()+HIR"手臂发麻！\n"NOR;
                                 ob->start_busy(1+random(3));
                                 damage = -damage*5;
                         }
                         else if(neili > neili1*2)
                         {
                                 msg += "结果$n"HIR"不能前进一丝一毫！\n"NOR;
                                 printf("damage = %d\n", -damage);
                                 damage = -damage*4;
                         }
                         else if(neili > neili1)
                         {
                                 msg += "结果减缓了$n"HIR"前进的速度！\n"NOR;
                                 damage = -damage/2;
                         }
                         else if(neili*2 > neili1)
                         {
                                 msg += "但并没有起到什么作用！\n"NOR;
                                 damage = 0;
                         }
                         else
                         {
                                 msg += "但却被$n"HIR"一下打破！\n"NOR;
                                 me->delete_temp("fanzhen");
                                 damage = -weapon->query("weapon_prop/damage");
                         }
                         if(wizardp(me)) tell_object(me, "Fanzhen damage: "+i+"。\n");
                         damage = -damage;
                         message_vision(msg, me, weapon);
                         return damage;
                }
        }
}
