// wineskin.c  �ƴ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
       set_name("ơ��", ({"pi jiu", "pi", "jiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("long", 
        "һ������ơ�ơ�\n");
              set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
               "name": "ơ��",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
