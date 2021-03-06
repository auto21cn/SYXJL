// Room: /d/wuguan/npc/chunzi.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("小春子", ({ "xiao chunzi","chunzi"}) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"神秘人物。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
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
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query("mud_age")<1000)	
	{
		command("hi " + ob->query("id"));
		command("say 嗨！你想拜师学艺吗？想成为高手吗？那么听我说说吧。\n");
		call_out("teach1",5,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 跟你说说如何拜师吧。\n");	
	command("say apprentice(bai)是拜师命令。\n");			
	command("say 如果你已经是某一门派的弟子，又去拜其他门派，就等于叛师了。\n");	
	command("say 叛师的话，将会受到很严重以及很惨的罚款，所以要三思。\n");
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 接着是说说如何学艺。\n");	
	command("say 其一，可以向师傅学习，命令：learn(xue)。但要减潜能。\n");	
	command("say 其二，可以阅读书籍，命令：study(du)。但要找到书籍。\n");							
	command("say 其三，可以自练，命令：practice(lian)。但这只能练特殊武艺。\n");					
	command("say 要自练，就必须先激发武艺，命令：enable(jifa)。然后practice(lian)。\n");
	command("say 自练的好处在于能够将特殊武艺练到基本功夫支持的最高级数，且不减潜能。\n");					
	command("say 还有abadon(fangqi)命令，是用来放弃一些“不小心”练出来的技能。\n");								
	command("say 因为武学之道是：在于精，不在于滥。\n");	
	call_out("teach3",7,ob);
}



void teach3(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 最后谈一谈关于打坐练内力的命令：exercise(dazuo)\n");	
	command("say 内力越高，武功修为就越高，玩家可以通过打坐来增加内力。\n");	
	command("say 但先决条件是，必须已经激发了特殊内功；内力越高，内力的上限就越难练。\n");							
	command("say 好了，我只是大概地介绍一下学艺的指令。\n");					
	command("say 想知道更详细的话，可以用help查一查命令说明，以及以后自己的实践了。\n");							
}	
	
