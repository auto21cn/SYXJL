luiyun.c 流云水袖
luiyun.c 流云水袖

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
//        object weapon;  
        string msg;
        int d_count, count, qi, maxqi, skill;

        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( !me->is_fighting() )
        return notify_fail("「流云水袖」只能在战斗中使用。\n");

    if( (int)me->query("neili") < 400 )
                return notify_fail("你的内力还不够高！\n");

        if( (int)me->query_skill("xuantian-wuji", 1) < 60)
                return notify_fail("你的玄天无极功的修为不够，不能使用流云水袖! \n");

        if( (int)me->query_skill("strike", 1) < 80 )
                return notify_fail("你的基本掌法还不到家，无法使用流云水袖！\n");

        if( me->query_skill_mapped("strike") != "kunlun-zhang") 
                return notify_fail("你没有激发昆仑掌，无法使用流云水袖！\n");
        
        
msg = HIR "$N轻喝一声使出昆仑掌中的绝学「流云水袖」，臂力陡然增加，衣袖横扫敌人的面门！\n" NOR;
        
        qi = me->query("qi");
        maxqi = me->query("max_qi");
        skill = (int) (me->query_skill("kunlun-zhang",1) / 3);
        count = me->query_str();
        d_count = (int)me->query_dex() / 2;

        if(qi > (maxqi * 0.4))
        {       
        message_vision(msg, me, target);
                
                me->add_temp("str", count * 2); 
                me->add_temp("dex", 0-d_count);
                me->set_temp("liuyun", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

                me->add("neili", -80);
        return 1;
        }
        else{
                msg = HIR "$N拼尽毕生功力使出了昆仑掌中的终极绝技「流云水袖」， 全身骨骼一阵爆响, 欲与敌人同归于尽!\n" NOR;
                message_vision(msg, me, target);
                me->add_temp("str", count * 9);
                me->set_temp("liuyun", 1);

                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*9, 0:), 2);

                me->add_temp("str",  -(count * 29));            
                me->delete_temp("liuyun");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set("neili",0);
                me->add("max_neili",-10);

                msg = HIR "$N用尽了最后一点气力, 喷出一口鲜血, 一头栽倒在地!\n" NOR;
                message_vision(msg, me, target);

                me->set("jing",0);
                me->set("qi",0);

                me->unconcious();


                return 1;
        }
}

void remove_effect(object me, int aamount, int damount)
{
        
        if ( (int)me->query_temp("liuyun") ) 
        {
                me->add_temp("str", -aamount);
                me->add_temp("dex", damount);
                me->delete_temp("liuyun");
                tell_object(me, HIY "你的「流云水袖」神功运行完毕，将内力收回丹田。\n" NOR);
                me->start_busy(random(4));
        }
}




#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
//        object weapon;  
        string msg;
        int d_count, count, qi, maxqi, skill;

        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( !me->is_fighting() )
        return notify_fail("「流云水袖」只能在战斗中使用。\n");

    if( (int)me->query("neili") < 400 )
                return notify_fail("你的内力还不够高！\n");

        if( (int)me->query_skill("xuantian-wuji", 1) < 60)
                return notify_fail("你的玄天无极功的修为不够，不能使用流云水袖! \n");

        if( (int)me->query_skill("strike", 1) < 80 )
                return notify_fail("你的基本掌法还不到家，无法使用流云水袖！\n");

        if( me->query_skill_mapped("strike") != "kunlun-zhang") 
                return notify_fail("你没有激发昆仑掌，无法使用流云水袖！\n");
        
        
msg = HIR "$N轻喝一声使出昆仑掌中的绝学「流云水袖」，臂力陡然增加，衣袖横扫敌人的面门！\n" NOR;
        
        qi = me->query("qi");
        maxqi = me->query("max_qi");
        skill = (int) (me->query_skill("kunlun-zhang",1) / 3);
        count = me->query_str();
        d_count = (int)me->query_dex() / 2;

        if(qi > (maxqi * 0.4))
        {       
        message_vision(msg, me, target);
                
                me->add_temp("str", count * 2); 
                me->add_temp("dex", 0-d_count);
                me->set_temp("liuyun", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

                me->add("neili", -80);
        return 1;
        }
        else{
                msg = HIR "$N拼尽毕生功力使出了昆仑掌中的终极绝技「流云水袖」， 全身骨骼一阵爆响, 欲与敌人同归于尽!\n" NOR;
                message_vision(msg, me, target);
                me->add_temp("str", count * 9);
                me->set_temp("liuyun", 1);

                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*9, 0:), 2);

                me->add_temp("str",  (count * 29));            
                me->delete_temp("liuyun");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set("neili",0);
                me->add("max_neili",-10);

                msg = HIR "$N用尽了最后一点气力, 喷出一口鲜血, 一头栽倒在地!\n" NOR;
                message_vision(msg, me, target);

                me->set("jing",0);
                me->set("qi",0);

                me->unconcious();


                return 1;
        }
}

void remove_effect(object me, int aamount, int damount)
{
        
        if ( (int)me->query_temp("liuyun") ) 
        {
                me->add_temp("str", -aamount);
                me->add_temp("dex", damount);
                me->delete_temp("liuyun");
                tell_object(me, HIY "你的「流云水袖」神功运行完毕，将内力收回丹田。\n" NOR);
                me->start_busy(random(4));
        }
}



