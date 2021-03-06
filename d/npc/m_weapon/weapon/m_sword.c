// m_sword.c
//modify by ronger 98/07/17
#include <ansi.h>
#include <weapon.h>

inherit M_WEAPON;


int duanlian(object weapon);
int do_hui(object weapon);


//string query_autoload() { return 1 + ""; }    //autoload weapon

void init()
{
        add_action("do_duanlian","duanlian");
        add_action("do_hui","hui");
}

void create()
{
        object me;
        string w_name,w_id,w_or, name;
        int w_lv, color;
        me = this_player();
//读入数据
//自制武器被他人得到后有bug，加入以下语句可以解决。
        if (!(me->query("weapon/name")))
{
                remove_call_out("destrory");
                call_out("destrory",1,me);
                return;
}
        w_name=me->query("weapon/name");
        w_id = me->query("weapon/id");
        w_or = me->query("weapon/or");
        w_lv = me->query("weapon/lv");
        color = w_lv;
        switch(color){
                case 1:
                case 2:
                        name = HIR + w_name + NOR;
                        break;
                case 3:
                case 4:
                        name = HIG + w_name + NOR;
                        break;
                case 5:
                        name = HIY + w_name + NOR;
                        break;
                case 6:
                        name = HIM + w_name + NOR;
                        break;
                case 7:
                        name = MAG + w_name + NOR;
                        break;
                case 8:
                        name = HIW + w_name + NOR;
                        break;
                case 9:
                        name = HIC + w_name + NOR;
                        break;
                default:
                        name = HIB + w_name + NOR;
                        break;
        }

        set_name(name, ({w_id}));
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
                        break;
                case "海底金母" :
                        set_weight(1000);
                        set("material", "steel");
                        break;
                case "寒丝羽竹" :
                        set_weight(30);
                        set("material", "bamboo");
                        break;
                default :
        }

        set("wield_msg", "$N一捏剑诀，" + name + "轻盈地从剑鞘中跃了出来。\n");
        if ( me->query("weapon/wield_msg") ){
                set("wield_msg", me->query("weapon/wield_msg") + "\n");
        }
        set("unwield_msg", "$N手中" + name + "一抖，眨眼间已然不见影踪。\n");
        if ( me->query("weapon/unwield_msg") ){
                set("unwield_msg", me->query("weapon/unwield_msg") + "\n");
        }

        init_sword(w_lv * 10);
        setup();
}
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
                return notify_fail("你的内力不够，无法锻炼剑气！\n");

        if( (int)me->query("qi") < 150 )
                return notify_fail("你的气不够，无法锻炼剑气！\n");

        if( (int)me->query("eff_qi") < 30 )
                return notify_fail("你现在的体力太弱，无法锻炼剑气！\n");

        if( (int)me->query("eff_jing") < 10 )
                return notify_fail("你现在的精力无法集中，不能锻炼剑气！\n");

     if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
             return notify_fail("你的潜能不够，无法锻炼剑气！\n");

        message_vision(HIR "$N手指剑脊，一股内力丝丝的传了进去。\n" NOR, me);

        me->add("max_neili",-10);
        me->set("neili", (int)me->query("max_neili"));
        me->add("qi",-100);
        me->add("eff_qi",-20);
        me->add("eff_jing",-20);
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
                message_vision(HIY "剑身忽的一亮，一道金光隐入$N的剑体，不见了！\n" NOR,me);
                message_vision(HIG "$N的剑的等级提高了！\n" NOR, me);
                weapon=this_object();
                if(weapon->query("equipped") )
                        weapon->unequip();
                reload_object( weapon );
                me->set("weapon/value",0);
                return 1;
        }
        message_vision(RED "$N的剑气提升了!\n" NOR, me);
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
        message_vision(HIR "$N大喝一声，一掌擎剑，一掌猛力击下。结果轰隆一声巨响"
                        +w_name+"断为两截!\n" NOR,me);
        me->delete("weapon");
        destruct( this_object() );
        me->save();

        return 1;
}

void owner_is_killed() { destruct(this_object()); }
