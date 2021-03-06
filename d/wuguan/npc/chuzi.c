// Npc: /d/wuguan/npc/chuzi.c
// Date: 99/05/31 by Byt

inherit NPC;
#include <ansi.h>

int ask_food();
int ask_water();

void create()
{
        set_name("胖厨子", ({ "pang chuzi", "chuzi" }) );
        set("gender", "男性" );
        set("age", 58);
        set("long", 
            "他是荆州武馆的厨子，胖胖的，敦厚老实。\n");
        set("combat_exp", 10000);
        set("max_jing", 300);
        set("max_qi", 300);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 20);
        set("attitude", "friendly");
        set("inquiry", ([
            "食物" : (: ask_food :),
            "food" : (: ask_food :),
            "水"   : (: ask_water :),
            "water" : (: ask_water :),                                    
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
		command("bow " + ob->query("id"));
		if(ob->query("gender")=="女性")
			command("say 这位小姑娘，这里是厨房，你可以先看看有什么吃的和喝的，如果没了你就向我\n要食物"HIR"(ask chuzi about 食物)"NOR+CYN"和喝的"HIR"(ask chuzi about 水)"NOR+CYN"吧。\n"NOR);
		else 
			command("say 这位小兄弟，这里是厨房，你可以先看看有什么吃的和喝的，如果没了你就向我\n要食物"HIR"(ask chuzi about 食物)"NOR+CYN"和喝的"HIR"(ask chuzi about 水)"NOR+CYN"吧。\n"NOR);			
}


int ask_food()
{
 	object ob;
 	object me = this_player();
	switch( random(3) ) 
        	{
		case 0:
			ob = new("/d/wuguan/obj/baozi");
			ob->move(me);
			command("say 谁知盘中餐，粒粒皆辛苦！别浪费了。\n");
        		message_vision("胖厨子给$N一个包子。\n",me);			
			break;
		case 1:
			ob = new("/d/wuguan/obj/yuebing");
			ob->move(me);			
			command("say 谁知盘中餐，粒粒皆辛苦！别浪费了。\n");		
        		message_vision("胖厨子给$N一块月饼。\n",me);							
			break;
		case 2:
			ob = new("/d/wuguan/obj/rice");
			ob->move(me);			
			command("say 谁知盘中餐，粒粒皆辛苦！别浪费了。\n");
        		message_vision("胖厨子给$N一碗米饭。\n",me);									
			break;
		}
	return 1;
}	



int ask_water()
{
 	object ob;
 	object me = this_player();
	ob = new("/d/wuguan/obj/tea");
	ob->move(me);			
	command("say 这杯大碗茶就给你吧，请慢点喝哟。\n");	
	message_vision("胖厨子给$N一杯大碗茶。\n",me);				
	return 1;
}	

