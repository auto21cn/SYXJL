//box ....angle
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("小箱子", ({ "box"}) );
        set_weight(300);
        set_max_encumbrance(50000);
        set("unit", "个");
        set("long", "一个生满铁锈的小铁箱，一看就知道是一件古物，上面没有锁，应该可以打开它。\n");
        set("no_get", 1);
        set("no_sell", 1);
        set("no_put", 1);
        set("no_give", 1);
        set("material", "steel"); 
        setup();

}


