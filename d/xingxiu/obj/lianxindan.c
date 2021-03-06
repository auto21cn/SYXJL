// lianxindan.c 炼心弹
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("炼心弹", ({ "lianxin dan", "dan" }) );
	set("long", 
		"这是一粒黑黝黝的小弹丸，看起来并不起眼，似乎是由硫磺硝磷之类制成的火弹。\n" );
	set_weight(20);
	set("unit", "粒");
	set("value", 10000);

	setup();
}

void init()
{
	add_action("do_throw", "throw");
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
 
  if( obj != present(ob, me) )
       return notify_fail("你想使用什么作暗器？\n");

  if( !objectp(target = present(who, environment(me))) || !target->is_character() )
       return notify_fail("你想对谁使用炼心弹？\n");

  if( target == me)
       return notify_fail("别这么想不开嘛。\n");

  if( me->is_busy())
       return notify_fail("你正忙着呢!\n");

  if( environment(me)->query("no_fight")==1 )
       return notify_fail("这里不许战斗!\n");

  if( (me->query("family"))["family_name"] != "星宿派" )
       return notify_fail("你不是星宿派弟子，不会使用炼心弹\n");

  if( me->query_skill("throwing", 1) < 50 )
       return notify_fail("你还是先学学基本暗器吧。\n");
  
  if( (int)me->query("neili",1) < 15 )
       return notify_fail("你的内力不够，不能施炼心弹。\n");

  me->start_busy(2);

  if( random( me->query_skill("beiming-zhenqi",1) )/2 + me->query_skill("throwing",1)
  > random( target->query_skill("dodge",1) )*2 )
  {
	message_vision(HIG "$N突然左手一扬，衣袖中飞出几点"
		+ HIC "蓝白白" + HIG "的火花，便如数只飞莹般扑出\n落在$n的身上。\n"
		+ HIR "随即发出嗤嗤的声响。\n"NOR, me, target);


	target->receive_damage("qi",me->query("jiali") + me->query_skill("throwing", 1) );
	target->receive_wound("qi",15 + random(10));
	target->receive_wound("jing", 10);
	target->start_busy(2 + random(4));
	
        COMBAT_D->report_status(target, 1);
  }
  else {
	message_vision( HIG "$N突然左手一扬，衣袖中飞出几点"
		+ HIC "蓝白白" + HIG "的火花，便如数只飞莹般向$n扑出。\n"NOR, me, target);
	message_vision(HIY "$N一个侧身将"+(string)obj->query("name")+"避了过去！\n" NOR,target);
	write((string)obj->query("name")+"“嗤”一声不知道飞到那里去了。\n");
	me->start_busy(1);
  }
  
  me->add("neili", -10);
  if( !target->is_killing(me) ) target->kill_ob(me);
  
  destruct(obj);
  
  return 1;
}