// qingzhu-ling1.c ������
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("������", ({"qingzhu ling", "qingzhu", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��������ɼ���ǩ����ƾ�˿��Ժ�ͬ�Ŵ�ʦ�ֱ�
����\n");
                set("material", "steel");
                set("no_give_user", 1);
                set("no_get", "�Ƕ����ǲ�������\n");
        }
}