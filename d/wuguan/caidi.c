// Room: /d/wuguan/caidi.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "菜地");
        set("long", @LONG
这里是块菜地，由于长期得不到良好的照顾，菜地里杂草丛生，
种的菜都长势不好，蔫蔫的，地都荒了。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "west" : __DIR__"houyuan2",
        ]));
        set("objects", ([
                __DIR__"npc/cyguanshi" : 1,
        ]));
            
        setup();
}



void init()
{
        add_action("do_work", "chu");
}

int do_work(string arg)
{
        object me;
        int costj, costq,i;
        me = this_player();
        i = 10+random(5);
        if (me->query_temp("job1")!=1) return notify_fail("你要干什么？\n");   
        if( !arg && arg !="草") return notify_fail("你要干什么？\n");   
        if (me->is_busy())
                return notify_fail("你现在正忙不过来呢。\n");             
        if( !present("chutou", this_player()) ) 
        {  
         	tell_object(me,"\n你想用什么来锄草，用手吗？\n");      
                return 1;
        }

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;

                
        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
        {
               message_vision("$N手一松，不小心锄在了自己的脚上！\n",me);
               me->unconcious();
               return 1;
        }        
        if(me->query_temp("task")==1)
        {
        	message_vision(RED"菜地管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR,me);
        	return 1;
        }        	
        if(me->query_temp("chu")<i) 
        {        
        	message_vision("$N挥起锄头，对着地上的杂草锄了起来。\n",me);      	  
        
        	me->receive_damage("jing", costj);
        	me->receive_damage("qi", costq);       
       		me->start_busy(1);
        	if ( (int)me->query_skill("staff", 1) < 20 && random(10)>5 )
        	{  
                	write(HIM"你在锄草中对于杖的用法有些体会！\n"NOR);
                	me->improve_skill("staff", (int)(me->query("int") / 10));
                }       		
        	me->add_temp("chu",1);       	
       		return 1;
       	}
        else 
        {
        	message_vision(RED"菜地管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR,me);
        	me->set_temp("task",1);        	  
                  me->delete_temp("chu");
        	return 1;     	
        }
}
