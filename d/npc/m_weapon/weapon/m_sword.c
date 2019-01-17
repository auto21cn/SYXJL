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
//��������
//�������������˵õ�����bug���������������Խ����
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
                        break;
                case "���׽�ĸ" :
                        set_weight(1000);
                        set("material", "steel");
                        break;
                case "��˿����" :
                        set_weight(30);
                        set("material", "bamboo");
                        break;
                default :
        }

        set("wield_msg", "$Nһ�󽣾���" + name + "��ӯ�شӽ�����Ծ�˳�����\n");
        if ( me->query("weapon/wield_msg") ){
                set("wield_msg", me->query("weapon/wield_msg") + "\n");
        }
        set("unwield_msg", "$N����" + name + "һ����գ�ۼ���Ȼ����Ӱ�١�\n");
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

        message_vision(HIR "$N��ָ������һ������˿˿�Ĵ��˽�ȥ��\n" NOR, me);

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
                message_vision(HIY "��������һ����һ���������$N�Ľ��壬�����ˣ�\n" NOR,me);
                message_vision(HIG "$N�Ľ��ĵȼ�����ˣ�\n" NOR, me);
                weapon=this_object();
                if(weapon->query("equipped") )
                        weapon->unequip();
                reload_object( weapon );
                me->set("weapon/value",0);
                return 1;
        }
        message_vision(RED "$N�Ľ���������!\n" NOR, me);
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
        message_vision(HIR "$N���һ����һ���潣��һ���������¡������¡һ������"
                        +w_name+"��Ϊ����!\n" NOR,me);
        me->delete("weapon");
        destruct( this_object() );
        me->save();

        return 1;
}

void owner_is_killed() { destruct(this_object()); }