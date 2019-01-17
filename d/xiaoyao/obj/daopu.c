inherit ITEM;

void create()
{
        set_name( "刀谱" , ({ "daopu" }));
        set_weight(200);
        set("unique", 1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
               set("long", "这是一本关于基本刀法的书。\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "blade",        
                        "exp_required": 100000, // minimum combat experience required
                        "jing_cost": 30,        // jing cost every time study this
                        "difficulty":   30,     // the base int to learn this skill
                        "max_skill":    101,    // the maximum level you can learn
                ]) );
        }
}

