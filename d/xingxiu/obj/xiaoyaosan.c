// xiaoyaosan.c 三笑逍遥散
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("三笑逍遥散", ({ "xiaoyao san", "san" }) );
        set("long", "这就是三笑逍遥散，星宿三宝之一。\n" );
        set_weight(10);
        set("unit", "份");
        set("no_get", 1);

        setup();
}

void init()
{
        add_action("do_take", "take");
        add_action("do_throw", "throw");
}

int do_take(string arg)
{
        object me = this_player();

        if (arg!="xiaoyao san" && arg!="san")
                return notify_fail("什么？");

//          if (objectp(present(arg, me)))
//                  return notify_fail("三笑逍遥散带多了很危险，把身上的用完了再拿吧。\n");

        if ((string)me->query("family/family_name") != "星宿派") {
                message_vision("$N拿起一份三笑逍遥散。\n", me);
                me->apply_condition("xys_poison", 2);
                call_out("destruct_ob", 0, present(arg, environment(me)));
        }
        else {
                if(me->query_skill("huagong-dafa", 1) >= 70) {
                        message_vision("$N大袖一卷，劲风过处，三笑逍遥散已尽数收入袖中。\n", me);
                        call_out("move_ob", 0, present(arg, environment(me)), me);
                }
                else return notify_fail("三笑逍遥散你也敢碰，活得不耐烦了呀！？\n");
        }
        return 1;
}

int do_throw(string arg)
{
  string ob,who;
  object me = this_player();
  object target;
  object obj = this_object();
  
  if(!arg)  
       return notify_fail("命令格式:throw <暗器> at <生物>\n");

  if(sscanf(arg,"%s at %s",ob,who)!=2)
       return notify_fail("命令格式:throw <暗器> at <生物>\n");
 
  if( !obj = present(ob, me) )
       return notify_fail("你想使用什么作暗器？\n");

  if( !objectp(target = present(who, environment(me))) || !target->is_character() )
       return notify_fail("你想对谁使用三笑逍遥散？\n");

  if( target == me)
       return notify_fail("别这么想不开嘛。\n");

  if( me->is_busy())
       return notify_fail("你正忙着呢!\n");

//    if( environment(me)->query("no_fight")==1 )
//         return notify_fail("这里不许战斗!\n");

  if( (me->query("family"))["family_name"] != "星宿派" )
       return notify_fail("你不是星宿派弟子，不会使用三笑逍遥散。\n");

  if( me->query_skill("throwing", 1) < 110 )
       return notify_fail("你还是先学学基本暗器吧。\n");
  
  if( (int)me->query("neili",1) < 170 )
       return notify_fail("你的内力不够，不能施三笑逍遥散。\n");

  me->start_busy(3);

  tell_object(me, HIW "你不动声色，大袖微扬，潜运内力，将“逍遥三笑散”毒粉向" + target->name() + "挥去。\n" NOR );

  if( random( me->query_skill("huagong-dafa",1) + me->query_skill("beiming-zhenqi", 1) )*2/3 + me->query_skill("throwing",1)
    > random( target->query_skill("force", 1) ) + target->query_skill("dodge", 1) ) {
        if( (int)me->query("neili") > (int)target->query("neili") ) {
                target->apply_condition("xys_poison", 2);
                target->start_busy(1 + random(1));
        }
        else {
                me->apply_condition("xys_poison", 2);
                me->start_busy(2);
        }
  }

  me->add("neili", -120);
        
  call_out("destruct_ob", 0, obj);
  
  return 1;
}

void move_ob(object ob, object me)
{
        ob->move(me);
}

void destruct_ob(object ob)
{
        destruct(ob);
}

void owner_is_killed() { destruct(this_object()); }
