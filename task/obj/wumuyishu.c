#include <ansi.h>
inherit ITEM;
void create()
{
           set_name(HIW"《武穆遗书》"NOR, ({ "wumu yishu","shu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
             set("unit", "本");
             set("material", "paper");
              set("long", "这是岳飞所著的兵书。\n");
          }

    setup();
}

