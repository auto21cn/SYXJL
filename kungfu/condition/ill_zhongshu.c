//ice_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) )
	{
		message("vision", me->name() + "看起来好象病得不轻。\n", environment(me), me);
	}
	else 
	{
		tell_object(me, HIG "突然你胸臆之间一阵翻腾，你感到浑身上下都难受。\n" NOR );
		message("vision", me->name() + "看起来好象中暑了。\n",environment(me), me);
	}
	me->receive_wound("qi",5 + random(5));
	me->receive_wound("jing", 5);
	me->apply_condition("ill_zhongshu", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

