inherit ITEM;

void create()
{
        set_name("华山剑谱", ({ "sword book", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"封面上写著「华山剑法 -- 卷二（精通）」\n");
                set("value", 200);
                set("material", "paper");
                set("skill", ([
                        "name":                 "sword",                // name of the skill
                        "exp_required": 0,                  // minimum combat experience required
                                                                                        // to learn this skill.
                        "jing_cost":            30,                             // jing cost every time study this
                        "difficulty":   30,                             // the base int to learn this skill
                                                                                        // modify is jing_cost's (difficulty - int)*5%
"max_skill":    60    
                                                                                        // from this object.
                ]) );
        }
}
