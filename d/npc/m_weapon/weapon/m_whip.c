// m_sword.c
//modify by ronger 98/07/17
#include <ansi.h>
#include <weapon.h>

inherit M_WEAPON;


int duanlian(object weapon);
int do_hui(object weapon);


//string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
        add_action("do_duanlian","duanlian");
	add_action("do_hui","hui");
}


void create()
{	
	object me;
	string w_name,w_id,w_or;
	int w_lv;
	me = this_player();
//�������������˵õ�����bug���������������Խ����
	if (!(me->query("weapon/name")))
{
		remove_call_out("destrory");
		call_out("destrory",1,me);
		return;
}
//��������
	w_name=me->query("weapon/name");
	w_id = me->query("weapon/id");
	w_or = me->query("weapon/or");
	w_lv = me->query("weapon/lv");
//	set_name(w_name, ({w_id}));
	set("unit", "��");   
	set("zizhi",1);
	set("no_get",1);
	set("no_drop",1);
	set_desc(w_lv,w_or,w_name);
	switch(w_or)
		{
		case "ǧ����ľ" :
			set_weight(500);
			set("material", "iron");
	                set_name(HIR +w_name+ NOR, ({w_id}));
	                set("wield_msg", "$N������һ�����ͳ���һ��"+HIR""+w_name+""+NOR"��\n");
	                set("unwield_msg", "$N����"+HIR""+w_name+""NOR"һ����գ�ۼ���Ȼ����Ӱ�١�\n");
	
			break;
		case "���׽�ĸ" :
			set_weight(1000);
			set("material", "steel");
	                set_name(MAG +w_name+ NOR, ({w_id}));
	                set("wield_msg", "$N������һ�����ͳ���һ��"+MAG""+w_name+""+NOR"��\n");
	                set("unwield_msg", "$N����"+MAG""+w_name+""NOR"һ����գ�ۼ���Ȼ����Ӱ�١�\n");
	
			break;
		case "��˿����" :
			set_weight(30);
			set("material", "bamboo");
	                set_name(HIG +w_name+ NOR, ({w_id}));
	                set("wield_msg", "$N������һ�����ͳ���һ��"+HIG""+w_name+""+NOR"��\n");
	                set("unwield_msg", "$N����"+HIG""+w_name+""NOR"һ����գ�ۼ���Ȼ����Ӱ�١�\n");
	
			break;
		default :
		} 

	init_whip(w_lv * 10 + 2);
	setup();
}	
//destruct ����
void destrory(object ob)
{
	destruct(ob);
}
int do_duanlian(object weapon)
{
	object me;
	string w_name;
	int w_zhi, w_level;
	string w_or;

	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon )
		return notify_fail("��Ҫ����ʲô?\n");

	if( (int)me->query("max_neili") < 10 )
		return notify_fail("��������������޷�����������\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("������������޷�����������\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("�����ڵ�����̫�����޷�����������\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("�����ڵľ����޷����У����ܶ���������\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("���Ǳ�ܲ������޷�����������\n");

	message_vision(HIR "$N������ԣ�һ������˿˿�Ĵ��˽�ȥ��\n" NOR, me);

	me->add("max_neili",-10);
	me->set("neili", (int)me->query("max_neili"));
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("eff_jing",-30);
	me->add("learned_points", 2);

	w_zhi = (int)me->query("weapon/value");
	w_zhi++;
	me->set("weapon/value", w_zhi);
	w_or = (string)me->query("weapon/or");
	w_level = (int)me->query("weapon/lv");
	if( w_zhi >= ((w_level + 1) * (w_level + 1)))
	{
		w_level++;
		me->set("weapon/lv", w_level);
		message_vision(HIY "��������һ����һ���������$N��"+w_name+"�������ˣ�\n" NOR,me);
		message_vision(HIG "$N��"+w_name+"�ĵȼ�����ˣ�\n" NOR, me);
		weapon=this_object();
		if(weapon->query("equipped") ) 
			weapon->unequip();
		reload_object( weapon );
		me->set("weapon/value",0);
		return 1;
	}
	message_vision(RED "$N��"+w_name+"���ʵظ�����!\n" NOR, me);
	return 1;
}


int do_hui(object weapon)
{	
	string w_name;
	object me;
	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon )
		return notify_fail("��Ҫ�ݻ�ʲô?\n");
	message_vision(HIR "$N���һ����һ����ޣ�һ���͵�һ�������ž��һ������"
			+w_name+"��Ϊ����!\n" NOR,me);
        me->delete("weapon");
        destruct( this_object() );
        me->save();
	return 1;
}
void owner_is_killed() { destruct(this_object()); }