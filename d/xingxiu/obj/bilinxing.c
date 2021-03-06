// bilinxing.c 碧磷星
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("碧磷星", ({ "bilin xing", "xing" }) );
	set("long", 
		"这是一粒暗红色的小弹丸，看起来并不起眼，似乎是由硫磺硝磷之类制成的火弹。\n" );
	set_weight(15);
	set("unit", "粒");
	set("value", 30000);

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
       return notify_fail("你想对谁使用碧磷星？\n");

  if( target == me)
       return notify_fail("别这么想不开嘛。\n");

  if( me->is_busy())
       return notify_fail("你正忙着呢!\n");

  if( environment(me)->query("no_fight")==1 )
       return notify_fail("这里不许战斗!\n");

  if( (me->query("family"))["family_name"] != "星宿派" )
       return notify_fail("你不是星宿派弟子，不会使用碧磷星。\n");

  if( me->query_skill("throwing", 1) < 70 )
       return notify_fail("你还是先学学基本暗器吧。\n");
  
  if( (int)me->query("neili",1) < 55 )
       return notify_fail("你的内力不够，不能施碧磷星。\n");

  me->start_busy(3);

  message_vision( HIB "$N眼中陡然放出异样光芒，左手袖袍一拂，一点"
	+ HIG "碧油油的磷火" + HIB "射向$n身上，\n"
	+ HIY "当真比流星还快。\n" NOR, me, target);

  if( random( me->query_skill("beiming-zhenqi",1) )*2/3 + me->query_skill("throwing",1)
  > random( target->query_skill("dodge",1) ) )
  {
	message_vision( CYN "$p待要闪避，却哪里来得及，嗤的一声响，$p全身衣服都着了火！\n" NOR, me, target);

	target->receive_damage("qi",me->query("jiali") + me->query_skill("throwing", 1) * 3 / 2 );
	target->receive_wound("qi",40 + random(20));
	target->receive_wound("jing", 30);
	target->start_busy(4 + random(5));

        COMBAT_D->report_status(target, 1);
  }
  else {
	message_vision(HIY "$N一个侧身将"+(string)obj->query("name")+"避了过去！\n" NOR,target);
	write((string)obj->query("name")+"“嗤”一声不知道飞到那里去了。\n");
	me->start_busy(2);
  }
  
  me->add("neili", -40);
  if( !target->is_killing(me) ) target->kill_ob(me);
  
  destruct(obj);
  
  return 1;
}