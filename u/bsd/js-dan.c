// zengsui-dan.c
// ronger 98/07/19
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG"减岁丹"NOR, ({"jiansui dan" , "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗减岁丹，可以把人变小。\n");
		}
	setup();
}
int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	else{
                me->add("mud_age",-86400*30);
                me->add("age", -30);
         	me->save();

	message_vision(HIG "$N吃下一颗减岁丹，只觉得体内没什么反应，难道上当了吗？\n" NOR, me);
		destruct(this_object());
		return 1;
       } 
}
