// liandu.c 毒液练药

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        mapping p;
	string msg;
        object ob;
        int amount;
        int exp;
	int lvl;
 
        if (! target)
		return notify_fail("你要取哪条蛇的毒液练药？\n");

        if (! target->is_snake())
                return notify_fail("看清楚些，那不是蛇，你瞎搞什么？\n");

        if (living(target))
                return notify_fail("那条蛇还精神着呢，你找死啊。\n");

	if ((int)me->query_skill("shedu-qiqiao", 1) < 80)
		return notify_fail("你的蛇毒奇巧还不够娴熟, 不能炼制毒药 !\n");


	if ((int)me->query("neili") < 200)
		return notify_fail("你现在的内力不够！\n");

        me->add("neili", -50);
        me->start_busy(random(3));

        msg = HIG "\n$N伸出双指，捏住" +
              target->name() + "的嘴巴，以内力迫出毒液练药。\n" NOR;

        p = target->query("snake_poison");
        lvl = (int) me->query_skill("poison", 1) / 2 +
              (int) me->query_skill("shedu-qiqiao", 1);

        amount = p["level"] * p["remain"];
        if (amount > lvl)
                amount = lvl;
        
        p["remain"] = (p["level"] * p["remain"] - amount) /
                       p["level"];
        target->apply_condition("poison-supply", 1);

        if (! amount)
        {
                msg += WHT "$N挤了半天，结果啥也没有挤出来，算是白忙活了。\n\n" NOR;
                message_vision(msg, me);
                return 1;
        }

        if (amount < lvl)
        {
                msg += WHT "$N挤了一点毒液出来。\n\n" NOR;
                message_vision(msg, me);
                tell_object(me, "可惜这点毒液连练一颗毒药都不够。\n");
                return 1;
        }

        msg += HIM "$N将" + target->name() + "的毒液悉数挤出，在内力的"
               "作用下化成了一颗晶莹剔透的药丸。\n\n" NOR;
        message_vision(msg, me);
        tell_object(me, "你炼制了一颗蛇毒药丸。\n");

        // improve skill
        exp = lvl / 5;
        me->improve_skill("poison", 2 + exp + random(exp));
	if (me->can_improve_skill("shedu-qiqiao"))
        	me->improve_skill("shedu-qiqiao", 2 + exp + random(exp));

	if (me->can_improve_skill("hamagong"))
        	me->improve_skill("hamagong", 2 + exp / 6 + random(exp / 6), 1);

        // create the object
        ob = new("/clone/misc/shedu");
        ob->set("poison", ([
                "level" : lvl,
                "id"    : me->query("id"),
                "name"  : "蛇毒",
                "duration" : 10,
        ]));
        ob->move(me);

	return 1;
}
