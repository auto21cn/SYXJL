// Npc: /huatong.c
// Date: 99/06/02 by Byt
#include <ansi.h>
inherit NPC;
int ask_send();

void create()
{
        set_name("花童", ({ "hua tong","tong" }) );
        set("gender", "男性" );
        set("age", 16);

        set("str", 22);
        set("int", 26);
        set("per", 23);
        set("kar", 25);
        set("con", 23);
        set("dex", 23);
        set("long",
	"一个天真可爱的送花童子。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("env/wimpy", 30);

        set("inquiry", ([
            "送花" : (: ask_send :),
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
        if (ob->query_temp("send")==1) return ;
	if (ob->query("class") =="bonze" ) return ;
	if (ob->query("class") =="taoist" ) return ;	
	command("say 这位" +RANK_D->query_respect(ob)+ "，买枝花送给你的心上人吧！\n"NOR);
	add_action("do_send", "song");
}


int ask_send()
{
        command("say 你想送"HIR"(song)"NOR+CYN"花给谁呢？\n"NOR);
        return 1;
}

int do_send(string arg)
{
	object ob,me,where;

	if(!arg || arg=="") {
		command("say 你想送"HIR"(song)"NOR+CYN"花给谁呢？\n"NOR);
		return 1;
	}
	me=this_player();
	ob = find_player(arg);
	if( !ob ) ob = find_living(arg);
	if(arg=="hua tong")
	{
		message_vision(CYN"花童急忙对$N摆摆手，说道：“无功不受禄，您也太客气了。”\n"NOR,me);
		return 1;
	}

	if (!ob) {
		command("say 这个人好象不在耶。。。\n");
		return 1;
	}
	if(me->query_temp("flower")!=1)
	{
		command("say 请您先把花给我吧。\n");
		return 1;
	}
	where = environment(ob);
	if (!where) {
		command("? "+me->query("id"));
		command("say 没有这个人啊。\n");
		return 1;
	}
	if(me->query("gender")=="女性")
			message_vision(CYN"花童对$N笑了笑，说道：“这位姑娘，我这就替您送去了。”\n"NOR,me);
	else 
			message_vision(CYN"花童对$N笑了笑，说道：“这位兄弟，我这就替您送去了。”\n"NOR,me);
	ob->set_temp("send",1);
	this_object()->move(environment(ob));
	call_out("sended",2,me,ob);
	return 1;
}



int accept_object(object me, object ob)
{

        if((ob->query("id") == "bai ju")||(ob->query("id") == "hung ju")||(ob->query("id") == "zi ju")||(ob->query("id") == "lu ju"))
        {
                command("xixi "+me->query("id"));
		me->set_temp("flower",1);
		command("say 你想送"HIR"(song)"NOR+CYN"花给谁呢？\n"NOR);		

	}
	return 1;
}



void sended(object who,object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("hi "+ob->query("id"));	
	command("give flower to "+ob->query("id"));	
	command("say 您的朋友"+who->query("name")+"("+who->query("id")+")托我把这束花送给您，您可收好了。\n");							
	command("bow "+ob->query("id"));	
	who->delete_temp("send");
	who->delete_temp("flower");	
	ob->delete_temp("flower");		
	ob->delete_temp("send");	
	this_object()->move("/d/jingzhou/huadian");
}
