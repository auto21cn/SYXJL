//yangpi1.c
inherit ITEM;
void create()
{
        set_name( "yangpi1", ({ "yangpi1"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","这是一小块很破旧的羊皮。\n");
                set("value", 0);
                set("material", "bamboo");
              }
}

