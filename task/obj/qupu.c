#include <ansi.h>
inherit ITEM;
void create()
{
       set_name(HIY"��Ц��������"HIW"����"NOR, ({ "qu pu","pu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
             set("unit", "��");
             set("material", "paper");
             set("long", "һ�����������������׵�Ц����������\n");
          }

    setup();
}

