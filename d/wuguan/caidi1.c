// Room: /d/wuguan/caidi1.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "菜地");
        set("long", @LONG
这里是块菜地，菜地旁有几口大缸，里面盛满了水，可是菜地看起来
都干裂了，几棵菜蔫蔫的长着，看样子是缺水太多了。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"houyuan2",
        ]));
        set("objects", ([
                __DIR__"npc/cy1guanshi" : 1,
        ]));
                    
        setup();
}




void init()
{
        add_action("do_work", "jiao");
}

int do_work(string arg)
{
        object me;
          int costj, costq;
        me = this_player();
        if (me->query_temp("job4")!=1) return notify_fail("你要干什么？\n");   
        if( !arg && arg !="水") return notify_fail("你要干什么？\n");   
        if (me->is_busy())
                return notify_fail("你现在正忙不过来呢。\n");             
        if( !present("piao", this_player()) ) 
        {  
         	tell_object(me,"\n你想用什么来浇水？\n");      
                return 1;
        }

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
        {
              message_vision("$N弯腰到大缸里舀水，结果一失足栽进了缸里！\n",me);
              me->set("water", 350);
              me->unconcious();
              return 1;
        }        
        if(me->query_temp("task")==1)
        {
        	message_vision(RED"菜地管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR,me);
        	return 1;
        }        	        
        if(me->query_temp("jiao")<(10+random(5))) 
        {        
        	message_vision("$N用瓢从缸里舀起水，在菜地里浇起水来。\n",me);      	  
        
       		me->receive_damage("jing", costj);
       		me->receive_damage("qi", costq);       
       		me->start_busy(1);
        	me->add_temp("jiao",1);       	
       		return 1;
       	}
        else 
        {
        	message_vision(RED"菜地管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR,me);
        	me->set_temp("task",1);        	  
                  me->delete_temp("jiao");
        	return 1;     	
        }
}
