// Room: /d/wuguan/npc/xiaoqian.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("丁秋白", ({ "ding qiubai","xiaoqian","ding"}) );
	set("gender", "男性" );
	set("age", 25);
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
		command("say 武林中少不了打打杀杀的，没有了打杀，就不是武林了。\n");
		call_out("teach1",5,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 玩家之间的互杀称之为PK(Player Killer)，现在教你如何战斗吧。\n");	
	command("say 战斗分别有三个命令：fight，hit，kill。\n");			
	command("say fight是点到即止的切磋武艺，有时会被对方拒绝。\n");	
	command("say hit是强行向对方出招，逼对方与你打斗，有可能导致死亡。\n");
	command("say kill就是杀死对方，对NPC使用的话，NPC也会企图杀死你。\n");			
	command("say 这三个命令，可以用help得到更详细的消息，也可以自己体会一下。\n");	
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 如果想自己攻击时更具杀伤力的话，可以enforce(jiali)和prepare(bei)。\n");	
	command("say enforce(jiali)是加力，即是每次击中敌人时，发出内力伤敌。\n");	
	command("say prepare(bei)是组合拳术技能，可以同一时间使用两种拳术。\n");							
	command("say 但必须这两种拳术可以互相组合。\n");					
	command("say 还有，如果手上有兵器的话，攻击力自然要比空手厉害。\n");
	call_out("teach3",7,ob);
}



void teach3(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 我只是简单地介绍一下战斗的指令，具体的还是亲自去体会一下吧。\n");	
	command("say 武林险恶，一切小心从事，切记切记。\n");	
	command("bye " + ob->query("id"));
}	
	
