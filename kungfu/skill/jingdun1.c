//jingdun.c 金遁

inherit SKILL;

void create() { seteuid(getuid()); }

void init()
{
    add_action("do_jingdun", "jingdun");
}

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("dex") < 24 ) 
           return  notify_fail("你的天性不适合学习遁术!\n" ) ;
	return 1;
}

