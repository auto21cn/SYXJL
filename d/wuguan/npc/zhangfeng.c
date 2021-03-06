// Npc: /d/wuguan/npc/zhangfeng.c
// Date: 99/05/31 by Byt

inherit NPC;
#include <ansi.h>

int ask_toy();
int ask_work();
void create()
{
        set_name("张风", ({ "zhang feng", "zhang" }) );
        set("gender", "男性" );
        set("age", 28);
        set("long", 
            "这人相貌和蔼，笑呵呵的，一手拿个旱烟袋。\n");
        set("combat_exp", 10000);
        set("max_jing", 300);
        set("max_qi", 300);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 20);
        set("attitude", "friendly");
        set("inquiry", ([
            "工具" : (: ask_toy :),
            "工作" : (: ask_work :),
            "job"  : (: ask_work :), 
        ]) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob) != environment() ) return;
        if (ob->query_temp("tasked")==1) return ;
        if (ob->query_temp("task")==1) return ;        
        if (ob->query("biye")==1) return ;                
	if(!this_player()->query_temp("jobed"))	
	{
		command("bow " + ob->query("id"));
		if(ob->query("gender")=="女性")
			command("say 这位小姑娘，我们这缺人手，你可以找我领工作"HIR"(ask zhang about job)"NOR+CYN"来做。\n"NOR);
		else 
			command("say 这位小兄弟，我们这缺人手，你可以找我领工作"HIR"(ask zhang about job)"NOR+CYN"来做。\n"NOR);			
	}
}



int ask_toy()
{
        command("say 你去物品房找老李要吧！\n");
        return 1;
}

int ask_work()
{
	object ob = this_player();
        if (ob->query("combat_exp") >= 10000)
        {
             command("say 你功夫已经足够闯荡江湖，这里没有什么适合你的工作了。\n");	
             ob->set("biye",1);
             return 1;
        }
             
        if(!ob->query_temp("jobed"))
        {
        	switch( random(5) ) 
        	{
		case 0:
			ob->set_temp("job1",1);
			ob->set_temp("jobed",1);			
			command("say 正好现在有好多事要做，你先去东物品房领工具，然后去后院锄草吧。\n");
			break;
		case 1:
			ob->set_temp("job2",1);
			ob->set_temp("jobed",1);						
			command("say 正好现在有好多事要做，你先去东物品房领工具，然后去后院锯木头吧。\n");
			break;
		case 2:
			ob->set_temp("job3",1);
			ob->set_temp("jobed",1);						
			command("say 正好现在有好多事要做，你先去东物品房领工具，然后去后院劈柴吧。\n");
			break;
		case 3:
			ob->set_temp("job4",1);
			ob->set_temp("jobed",1);						
			command("say 正好现在有好多事要做，你先去东物品房领工具，然后去后院浇菜地吧。\n");
			break;
		case 4:
			ob->set_temp("job5",1);
			ob->set_temp("jobed",1);						
			command("say 正好现在有好多事要做，你先去东物品房领工具，然后去后院扫马房吧。\n");
			break;
	      	}
        }
        else
        	command("say 你不是已经领了工作吗？还不快去做。\n");
        	
       	return 1;
}

