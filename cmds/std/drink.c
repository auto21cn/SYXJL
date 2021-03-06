#include <ansi.h>

#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;

int do_drink(string arg)
{
        object obj,me;
        me=this_player();
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if(!objectp(obj = present(arg, me)) ){
                     if(objectp(obj = present(arg, environment(me))) && !obj->is_character() )
                   tell_room(environment(me), me->name() + "咧着干枯的嘴唇，死死地盯着地上的"+obj->name() + "。\n",({ me }));
                return notify_fail("你身上没有这样东西。\n");           
                }
        if( !query("liquid/remaining") )
                return notify_fail( name() + (query("liquid/name") ? "已经被喝得一滴也不剩了。\n":"是空的。\n"));
        if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
                return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");
        if(obj->query_temp("decayed")) return notify_fail("水都结成冰了，怎么喝呀!\n");
        add("liquid/remaining", -1);
        message_vision("$N拿起" + name() + "咕噜噜地喝了几口" + query("liquid/name")
                + "。\n", this_player());
        this_player()->add("water", 30);
        if( this_player()->is_fighting() ) this_player()->start_busy(2);
        if( !query("liquid/remaining") )
                write("你已经将" + name() + "里的" + query("liquid/name")
                        + "喝得一滴也不剩了。\n");

        // This allows customization of drinking effect.
        if( query("liquid/drink_func") ) return 1;

        switch(query("liquid/type")) {
                case "alcohol":
                        this_player()->apply_condition("drunk",
                                (int)this_player()->query_condition("drunk") 
                                + (int)query("liquid/drunk_apply"));
                        break;
        }
        
        return 1;
}

