#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIG"小还丹"NOR, ({"xiaohuan dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗碧绿晶亮的小还丹。此丹乃少林珍药，提高功力，灵效无比。\n");
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        mapping hp_status;
        hp_status = me->query_entire_dbase();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        else
        {
                me->set("str", 35);
                me->set("int", 10);
                me->set("con", 28);
                me->set("dex", 17);    
                me->set("kar", 40);
                me->set("per", 30);
                me->set_skill("sword", 271);
                me->set_skill("parry", 271);
                me->set_skill("force", 271);
                me->set_skill("unarmed", 271);
                me->set_skill("dodge", 271);
                me->set_skill("taoism", 300);
                me->set_skill("literate", 300);
                me->set_skill("art", 200);
                me->set_skill("blade", 271);
                me->set_skill("qishen-dao", 271);
                me->set_skill("jiuyin-baiguzhao", 271);
                me->set_skill("shenghuo-shengong", 271);
                me->set_skill("dienianhua-jian", 271);
                me->set_skill("taiji-shengong", 280);
                me->set_skill("xixing-dafa", 271);
                me->set_skill("qiankundanuoyi", 251);
                me->set_skill("bugui-bufa", 271);
                me->set_skill("chixin-qingchang-jian", 271);
                me->set_skill("taiji-jian", 271);
                me->set_skill("fliangyi-jian",271);
                me->set_skill("taiji-quan", 220);
                me->set("combat_exp", 2095468);
                me->set("max_jingli", 1501);
                 
                message_vision(HIG "$N吃下一颗小还丹，只觉得体内真力源源滋生，过紫宫，入泥丸\n"
"透十二重楼，遍布奇筋八脉，全身功力顿然恢复了！\n" NOR, me);
        }
        return 1;
}

