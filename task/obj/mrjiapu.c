#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"Ľ�ݼ���"NOR, ({ "mrjiapu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ��Ľ�ݼ���\n");
          }

    setup();
}

