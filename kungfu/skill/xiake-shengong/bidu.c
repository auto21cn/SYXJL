// heal.c

#include <ansi.h>
#include <cond.h>

string poison;
int duration;

int exert(object me, object target)
{
string *names;
        if( me->is_fighting() )
              {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail(YEL"战斗中疗毒会导致走火入魔！\n"NOR);
               }

        if ((int)me->query_skill("xiake-shengong", 1) < 30)
              {
               if(test_zouhuorumo(me)) return notify_fail("");  
                return notify_fail(YEL"你的侠客神功火候不够,如果强行疗毒会引起走火入魔。\n"NOR);
               }
        if((int)me->query("max_neili") < 500)
          return notify_fail(HIC"你的内力修为不够。\n");
        if( (int)me->query("neili") < 600 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
          {
             if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
            }

        if(!zhongdu(me))
         return notify_fail(HIC"你查不出你到底中了什么毒，无法辽毒。\n"NOR); 

   write( HIW "你用真气护住了丹田，然后慢慢引导这股真气游走全身，\n" NOR);
   write( HIW "把毒逐渐逼至双手。\n......\n"NOR);
   
        message("vision",
HIW + me->name() + "的脸色逐渐有青慢慢转白，脸上冒出豆大的汗珠，\n" NOR,
                environment(me), me);
        message("vision",
HIW + me->name() + "颤抖的手指上不时滴下黑色的发着腥臭味的液体。\n" NOR,
                environment(me), me);

        names=keys(my_cond);
        poison=names[0];
        duration=me->query_condition(poison);
        me->apply_condition(poison,0);
        me->start_busy(5);
        remove_call_out("result");
         call_out("result",5,me); 
        me->set("jiali", 0);

        return 1;
}


void result(object me)
 {
  me->add("neili",-600);
  me->set("qi",me->query("qi")/2);
  me->set("jing",me->query("jing")/2);
  message_vision(HIC "$N脸色苍白的站了起来，浑身衣服都湿透了，嘴角挂着\n"+
   "一丝鲜血，脚底下流着一滩又黑又难闻的液体。\n"NOR,me);
  if((duration > 10) && (me->query("neili") < 600))
   {
    tell_object(me,HIC"你好象觉得毒并没有完全被解掉。\n"NOR);
    me->apply_condition(poison,duration-10); 
    return ;
    }
 if(sizeof(my_cond)>1)
  tell_object(me,HIC"你体内中了不止一种毒。\n"NOR);
 else
  tell_object(me,HIC"你体内的毒素终于全部被逼出来了。\n"NOR);
  }
