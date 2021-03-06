// m_sword.c

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
//自制武器被他人得到后有bug，加入以下语句可以解决。
	if (!(me->query("weapon/name")))
{
		remove_call_out("destrory");
		call_out("destrory",1,me);
		return;
}
//读入数据
	w_name=me->query("weapon/name");
	w_id = me->query("weapon/id");
	w_or = me->query("weapon/or");
	w_lv = me->query("weapon/lv");
//	set_name(w_name, ({w_id}));
	set("unit", "柄");   
	set("zizhi",1);
	set("no_get",1);
	set("no_drop",1);
	set_desc(w_lv,w_or,w_name);
	switch(w_or)
		{
		case "千年神木" :
			set_weight(500);
			set("material", "iron");
	                set_name(HIR +w_name+ NOR, ({w_id}));
	                set("wield_msg", "$N往怀中一摸，掏出了一把"+HIR""+w_name+""+NOR"。\n");
	                set("unwield_msg", "$N手中"+HIR""+w_name+""NOR"一抖，眨眼间已然不见影踪。\n");
	
			break;
		case "海底金母" :
			set_weight(1000);
			set("material", "steel");
	                set_name(MAG +w_name+ NOR, ({w_id}));
	                set("wield_msg", "$N往怀中一摸，掏出了一把"+MAG""+w_name+""+NOR"。\n");
	                set("unwield_msg", "$N手中"+MAG""+w_name+""NOR"一抖，眨眼间已然不见影踪。\n");
	
			break;
		case "寒丝羽竹" :
			set_weight(30);
			set("material", "bamboo");
	                set_name(HIG +w_name+ NOR, ({w_id}));
	                set("wield_msg", "$N往怀中一摸，掏出了一把"+HIG""+w_name+""+NOR"。\n");
	                set("unwield_msg", "$N手中"+HIG""+w_name+""NOR"一抖，眨眼间已然不见影踪。\n");
	
			break;
		default :
		} 

	init_staff(w_lv * 10);
	setup();
}	
//destruct 武器
void destrory(object ob)
{
	destruct(ob);
}
int do_duanlian(object weapon)
{
	object me;
	int w_zhi, w_level;
	string w_or;

	me=this_player();
	if( !weapon )
		return notify_fail("你要锻炼什么?\n");

	if( (int)me->query("max_neili") < 10 )
		return notify_fail("你的内力不够，无法锻炼杖体！\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("你的气不够，无法锻炼杖体！\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("你现在的体力太弱，无法锻炼杖体！\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("你现在的精力无法集中，不能锻炼杖体！\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("你的潜能不够，无法锻炼杖体！\n");

	message_vision(HIR "$N手握杖端，一股内力丝丝的传了进去。\n" NOR, me);

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
		message_vision(HIY "杖身忽的一亮，一道金光隐入$N的杖体，不见了！\n" NOR,me);
		message_vision(HIG "$N的杖的等级提高了！\n" NOR, me);
		weapon=this_object();
		if(weapon->query("equipped") ) 
			weapon->unequip();
		reload_object( weapon );
		me->set("weapon/value",0);
		return 1;
	}
	message_vision(RED "$N的杖的硬度提高了!\n" NOR, me);
	return 1;
}


int do_hui(object weapon)
{	
	string w_name;
	object me;
	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon )
		return notify_fail("你要摧毁什么?\n");
	message_vision(HIR "$N大喝一声，一掌擎杖，一掌猛力击下。结果轰隆一声巨响"
			+w_name+"断为两截!\n" NOR,me);
        me->delete("weapon");
        destruct( this_object() );
        me->save();

	return 1;
}
void owner_is_killed() { destruct(this_object()); }
