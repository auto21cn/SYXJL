// Npc: /d/wuguan/npc/fang.c
// Date: 99/05/31 by Byt
#include <ansi.h>
inherit NPC;
int ask_literate();
void create()
{
	set_name("方先生", ({ "fang xiansheng", "fang" }));
	set("long", "这位先生年纪不大，正在认真地读书。。\n");
	set("gender", "男性");
	set("age", 65);

	set_skill("literate", 50);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400);
	set("shen_type", 1);

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
			command("say 这位小姑娘，到我这学些知识"HIR"(xue fang literate)"NOR+CYN"吧。\n"NOR);
		else 
			command("say 这位小兄弟，到我这学些知识"HIR"(xue fang literate)"NOR+CYN"吧。\n"NOR);
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/方"))
                return 0;
        ob->add_temp("mark/方", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/方"))
                who->set_temp("mark/方", 0);
        if (ob->query("money_id") && ob->value() >= 100) 
        {
                message_vision("方先生同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/方", ob->value() / 50);
                return 1;
        }
}
