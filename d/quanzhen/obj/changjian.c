// changjian.txt





#include <weapon.h>


inherit SWORD;





void create()


{


        set_name("����", ({ "chang jian", "sword" }));


        set_weight(6000);


        if (clonep())


                set_default_object(__FILE__);


        else {


                set("unit", "��");


                set("long", "����һ������ͨͨ�ĳ�������\n");


                set("value", 2000);


                set("material", "steel");


                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");


                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");


        }


        init_sword(30);


        setup();


}