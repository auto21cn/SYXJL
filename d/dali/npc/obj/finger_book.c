//tianlong-jing by mop because no need jing
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("一阳秘籍", ({ "tianlong-jing", "shu" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本线装书，里面密密麻麻的画了不少打坐吐呐的姿势。\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name":       "finger",
   "exp_required" :100000,
                        "jing_cost":  60,
                        "difficulty": 20,
                        "max_skill":  100
                ]) );
        }
}

