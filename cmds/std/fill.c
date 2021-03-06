#include <ansi.h>

#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;

int do_fill(string arg)
{
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if( !environment(this_player())->query("resource/water") )
                return notify_fail("这里没有地方可以装水。\n");
        if(query_temp("decayed")) {
                message_vision("$N将"+name()+"里面的冰块倒了出来",this_player());
                message_vision("$N将"+name()+"装满热水。\n",this_player());
                delete_temp("decayed");
                        }
                        
        else if( query("liquid/remaining") ){
                message_vision("$N将" + name() + "里剩下的" + query("liquid/name") + "倒掉。\n", this_player());
                message_vision("$N将" + name() + "装满清水。\n", this_player());}
        else message_vision("$N将" + name() + "装满清水。\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        set("liquid/type", "water");
        set("liquid/name", "清水");
        set("liquid/remaining", query("max_liquid"));
        set("liquid/drink_func", 0);

        return 1;
}

