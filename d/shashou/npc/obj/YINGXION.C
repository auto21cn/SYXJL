// yingxion.c Ӣ�۽�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name("Ӣ�۽�", ({ "yingx sword", "sword" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ѽ����ʮ��ƽ�������ʹ�׾�޹⣬ȴ��¶��һ���쳣�о���
		ʹ��һ����֪����һ�������񽣡�\n");
		set("value", 1000000);
		set("material", "steel");
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
		set("wield_msg", HIY "ֻ�������һ����Ӣ�۽����ʷɳ�������Ծ��$N���С�
˲ʱ��ʼ���Ʊ�ɫ������������������һƬ�ޱ�ɱ�⡣\n" NOR);
		set("unwield_msg", HIY "Ӣ�۽���$N���з����ڰ����һת����ৡ���Ծ�뵶�ʡ�\n" NOR);
	}
	init_sword(1000);
	setup();
}