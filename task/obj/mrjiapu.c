#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"慕容家谱"NOR, ({ "mrjiapu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张慕容家谱\n");
          }

    setup();
}


