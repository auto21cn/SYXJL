#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIW "暴雨梨花针" NOR, ({ "needle box","box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个七寸长，三寸厚的银匣子，上面刻满了钟鼎文\n");
                set("material", "silver");
        }
        setup();
}
void init()
{
        add_action("do_shoot","shoot");
}
int do_shoot(string arg)
{
        object ob;
        object me;
        int dp;
        int damage;
        if (!arg) return notify_fail("你要打谁？\n");
        if (query("used")) return notify_fail(this_object()->name()+"只能用一次\n");
        me=this_player();
    if( environment(me)->query("no_fight") ||
        environment(me)->query("no_magic") ||
        environment(me)->query("no_spells") 
        )
        return notify_fail("在这不可偷袭！\n");
    ob=present(arg,environment(me));
    if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"只能对活的生物使用\n");
    if (!me->is_fighting(ob)) message_vision("$N阴笑一声，从怀里摸出一件东西．．\n",me);
    message_vision("$N对着$n举起了手中的"+this_object()->name()+"...\n",me,ob);
    message_vision(RED "从匣子中闪电般射出一片银光．．．...\n" NOR,me);
    message_vision("银光打在$N身上，一闪就消失了。\n",ob);
    ob->receive_damage("qi", 0, me);
    dp=COMBAT_D->skill_power(ob,"dodge",SKILL_USAGE_DEFENSE);
    damage=150000-dp;
    damage/=100;
    if (damage<0) damage=0;
    ob->receive_wound("qi",damage,me);    
    COMBAT_D->report_status(ob);                                         
    ob->kill_ob(me); 
    set("used",1);
    me->start_busy(3);
    return 1;
}


