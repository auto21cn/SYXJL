#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIM "大昭密文" NOR, ({ "dzmwen" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "一本大昭寺的密文：
吾寺舍利子不慎丢失，虽然为赤松所盗，贫僧也应被责．
望活佛量罪而处．

                                葛伦\n");
          }

    setup();
}

