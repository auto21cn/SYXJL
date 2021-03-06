//guizhen.c  归真一剑
// renee

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
string* xuedao1 = ({
        "小腹",
        "胸口",
        "太阳穴",
        "右臂",
        "右脚",
        "左腿",
        "左臂"
});


int perform(object me, object target)
{
        mapping prepare_status;
        string weapon, op_weapon, op_skill, *pname;
        int my_power, op_power, my_li, op_li, my_jing, my_nei, op_jing, op_nei;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『归真一剑』只能对战斗中的对手使用。\n");

        if( !me->query("wudang/guizhen") )
                return notify_fail("『归真一剑』的精髓你还没有体会到！\n");

        if( me->query_skill_mapped("force") != "taiji-shengong" )
                return notify_fail("你所用的并非太极神功，无法运劲施展『归真一剑』！\n");

        if( me->query_skill("force") < 200 )
                return notify_fail("你的太极神功火候未到，无法运劲施展『归真一剑』！\n");

        if( me->query_skill("sword") < 200 )
                return notify_fail("你的太极剑法修为不足，还不会使用『归真一剑』！\n");

        if( me->query("neili") <= 3000 )
                return notify_fail("你的内力不够使用『归真一剑』！\n");
        if( me->query("jing") <= 1000 )
                return notify_fail("你的精力不够使用『归真一剑』！\n");

        weapon = me->query_temp("weapon");

        if ( !objectp(op_weapon = target->query_temp("weapon")) ) {
                if ( mapp(prepare_status = target->query_skill_prepare()) ) {
                        pname  = keys(prepare_status);
                        op_skill = pname[0];
                }
                else op_skill = "unarmed";
        }
        else {
                op_skill = op_weapon->query("skill_type");
        }

        my_jing = me->query("jing") - 100;
        my_nei = me->query("neili") - 700;

        if ( target->query("neili") < me->query("neili") ) {
                op_nei = target->query("neili")*9/10;
        }
        else op_nei = my_nei;

        if ( target->query("jing") < me->query("jing") ) {
                op_jing = target->query("jing")*9/10;
        }
        else op_jing = my_jing;

        message_vision(HIW "\n$N的剑气聚于剑上，白光如虹，剑招由变幻莫测转为平平无奇。\n"
                          GRN"$N挥动"+weapon->name()+"往$n的" + xuedao1[random(7)] + "刺去！\n\n" NOR, me, target);
        tell_object(target, HIR "你只觉得敌招来势猛恶无伦，压得你透不过气来！\n" NOR);

        my_power = me->query_skill("sword") + me->query_skill("dodge") + me->query_skill("force")
                   + me->query_skill("parry") + me->query("combat_exp") / 1000;

        op_power = target->query_skill(op_skill) + target->query_skill("dodge") + target->query_skill("force")
                   + target->query_skill("parry") + target->query("combat_exp") / 1000;
                
        my_li = me->query("jing") + me->query("neili");

        op_li = target->query("jing") + target->query("neili");

        if ( random(my_power) > op_power/2 ) {

           if ( random(my_li) > random(op_li) ) {
                if ( objectp(op_weapon) ) {
                        message_vision(HIR "$N闪避不及，只好咬牙举起"+op_weapon->name()+"奋起全力强接攻势。\n" NOR, target);
                        message_vision(HIR "硬砰之下，"+op_weapon->name()+"竟断为几截，但仍阻不了归真一剑来势！\n" NOR, target);
                        op_weapon->unequip();
                        op_weapon->move(environment(me));
                        op_weapon->set("name", "断掉的" + op_weapon->name());
                        op_weapon->set("value", 0);
                        op_weapon->set("weapon_prop", 0);
                }
                
                message_vision(HIR "$N避无可避，发出一声凄历的惨嚎 ！\n" NOR, target);
//              weapon->move(target);
                target->receive_wound("qi", target->query("max_qi")*9/10);
//              target->die();
           }
           else if ( me->query_str() > target->query_str() ) {
                if ( objectp(op_weapon) ) {
                        message_vision(HIR "硬砰之下，"+op_weapon->name()+"竟断为几截，终於抵消了飞剑来势！\n" NOR, target);
                        message_vision("归真一剑攻势受阻，力尽跌落。$N虽挡过一击，却也因精与内力钜耗，摇摇欲坠！\n", target);
//                      weapon->move(environment(me));
                        op_weapon->unequip();
                        op_weapon->move(environment(me));
                        op_weapon->set("name", "断掉的" + op_weapon->name());
                        op_weapon->set("value", 0);
                        op_weapon->set("weapon_prop", 0);
                }
                else {
                        message_vision(HIR "$N奋力闪躲，但却力有不逮，发出一声凄历的惨嚎，中剑重伤！\n" NOR, target);
                        target->receive_wound("qi", target->query("max_qi")*6/9);
                }
           }
           else if ( random(2) == 1 && objectp(op_weapon) ) {
                message_vision(HIR "硬砰之下，$N的"+weapon->name()+"及$n的"+op_weapon->name()+"双双跌下！\n" NOR, me, target);
                weapon->move(environment(me));
                op_weapon->move(environment(me));
           }
           else if ( objectp(op_weapon) ) {
                message_vision(HIR "硬砰之下，$N的"+weapon->name()+"及$n的"+op_weapon->name()+"双双损毁！\n" NOR, me, target);
                op_weapon->unequip();
                op_weapon->move(environment(me));
                op_weapon->set("name", "断掉的" + op_weapon->name());
                op_weapon->set("value", 0);
                op_weapon->set("weapon_prop", 0);
                weapon->unequip();
                weapon->move(environment(me));
                weapon->set("name", "断掉的" + weapon->name());
                weapon->set("value", 0);
                weapon->set("weapon_prop", 0);
           }
           else {
                message_vision(HIR "$N奋力闪躲，但却力有不逮，发出一声凄历的惨嚎，中剑受伤！\n" NOR, target);
                target->receive_wound("qi", target->query("max_qi")*4/9);
           }

           target->add("jing", -op_jing);
           target->add("neili", -op_nei);
        }
        else {
//              weapon->move(environment(me));  
                message_vision(HIY "$N身形连闪，只守不攻，好不容易将此招避过，已吓得亡魂直冒！\n" NOR, target);
                message_vision(HIY "一击未中，"+weapon->name()+"的剑气从归你体内。\n" NOR, me);
        }

        me->add("neili", -my_nei);
        me->add("jing", -my_jing);
        target->start_busy(2);
        target->kill_ob(me);
        
        return 1;
}
