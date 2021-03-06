// Room: /d/wuguan/caiang.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "柴房");
        set("long", @LONG
这间屋里叮叮哐哐的，你仔细一看，几个人在劈柴火，屋子特别大，
屋子一边堆满了已经锯短的木头，但是另一边劈好的柴火却没有多少。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "west" : __DIR__"houyuan",
        ]));
        set("objects", ([
                __DIR__"npc/cfguanshi" : 1,
        ]));
        setup();
}



void init()
{
        add_action("do_work", "pi");
}

int do_work(string arg)
{
        object me;
        int costj, costq;
        me = this_player();
        if (me->query_temp("job3")!=1) return notify_fail("你要干什么？\n");   
        if( !arg && arg !="柴") return notify_fail("你要劈什么？\n");   
        if (me->is_busy())
                return notify_fail("你现在正忙不过来呢。\n");             
        if( !present("chaidao", this_player()) ) 
        {  
         	tell_object(me,"\n你想用什么来劈柴，用手劈吗？\n");      
                return 1;
        }

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
                message_vision("$N手一歪，不小心劈在自己的腿上\n",me);
                me->receive_wound("qi", 20);
                me->set_temp("last_damage_from", "不小心被自己劈");
                me->unconcious();
                return 1;
                }
        if(me->query_temp("task")==1)
        {
        	message_vision(RED"柴房管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR,me);
        	return 1;
        }        	        
        if(me->query_temp("pi")<(10+random(5))) 
        {        
        	message_vision("$N摆正一块木头，一刀劈了下去，“哐”的一声，木头被劈为两片。\n",me);      	  
        
        	me->receive_damage("jing", costj);
       		me->receive_damage("qi", costq);   
       		me->start_busy(1);

        	if ( (int)me->query_skill("blade", 1) < 20 && random(10)>5 )
        	{  
                	write(HIM"你在劈柴中对于刀的用法有些体会!\n"NOR);
                	me->improve_skill("blade", (int)(me->query("str") / 10));
                }       		
        	me->add_temp("pi",1);       	
       		return 1;
       	}
        else 
        {
        	message_vision(RED"柴房管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR,me);
        	me->set_temp("task",1);
                  me->delete_temp("pi");
        	return 1;     	
        }
}
