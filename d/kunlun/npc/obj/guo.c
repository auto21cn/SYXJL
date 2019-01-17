// guo.c

// csy



#include <ansi.h>

inherit ITEM;



void init()

{

        add_action("do_eat", "eat");

}



void create()

{

        set_name( HIR "曼陀萝果" NOR , ({"mantuoluo guo", "guo"}));

        set_weight(100);

        if (clonep())

                set_default_object(__FILE__);

        else

        {

                set("long", "这是一颗曼陀萝果，吃了不知道有没有危险。\n");

                set("unit", "颗");

        }

}



int do_eat(string arg)

{

        if (!id(arg))  return notify_fail("你要吃什么？\n");

        if(arg=="guo") 

        {

                switch (random(6))

                {

                        case 0:

                                this_player()->set("eff_jing",this_player()->query("max_jing"));

                                this_player()->set("jing",this_player()->query("max_jing"));

tell_object(this_player(), HIG "你只觉全身一震，登时精神倍加！\n" NOR );

                                destruct(this_object());

                                break;

                        case 1:

                                this_player()->set_temp("nopoison", 1);

tell_object(this_player(), HIC "你只觉一股清香沁入心肺,顿时灵台一片空明,神意清爽！\n" NOR );

                                destruct(this_object());

                                break;

                        case 2:

                                this_player()->set("eff_qi",this_player()->query("max_qi"));

                                this_player()->set("qi",this_player()->query("max_qi"));

tell_object(this_player(), HIG "你只觉一股暖流直冲丹田，气血恢复不少！\n" NOR );

                                destruct(this_object());

                                break;

                        case 3:

                                this_player()->add("max_neili",2);

tell_object(this_player(), HIG "你只感觉功力增加了不少！\n" NOR );

                                destruct(this_object());

                                break;

                        case 4:

                                this_player()->set("eff_jing",this_player()->query("max_jing"));

                                this_player()->set("jing",this_player()->query("max_jing"));

                                this_player()->set("eff_qi",this_player()->query("max_qi"));

                                this_player()->set("qi",this_player()->query("max_qi"));

tell_object(this_player(), HIG "你只感觉精神气血十分饱满！\n" NOR );

                                destruct(this_object());

                                break;

                        case 5:

                                this_player()->apply_condition("flower_poison", 100);

tell_object(this_player(), HIR "你只觉脑中一阵麻木！\n" NOR );

                                destruct(this_object());

                                break;

                }

        }

        return 1;

}



