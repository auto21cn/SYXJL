// hubo.c



//inherit ITEM;

inherit SKILL;



void create() { seteuid(getuid()); }



void init()

{

    add_action("do_dun","dun");

      add_action("do_yin","yin");

}



string type() { return "knowledge"; }



int valid_learn(object me) 

{

        if( (int)me->query("dex") < 24 ) 

           return  notify_fail("你的天性不适合学习奇门遁甲之术!\n" ) ;

	return 1;

}

