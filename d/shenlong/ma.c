// ma.c

#include <ansi.h>

inherit NPC;
int ask_me();

string ask_me(object who);

void create()
{
        set_name("马竟终", ({ "ma jingzhong","ma" }) );
        set("title", "浣花剑派总管");
        set("gender", "男性" );
        set("age", 56);

        set("str", 22);
        set("int", 26);
        set("per", 23);
        set("kar", 25);
        set("con", 23);
        set("dex", 23);
        set("long",
                
"马竟终出道很早，对武林中的大小事务都很熟悉，\n"
"武林中的事可没几件能瞒得过他。\n");

        set("combat_exp", 300000);
        set("attitude", "friendly");
        set("env/wimpy", 30);

        set("max_neili", 1000);  
        set("neili", 1000);             
	set("jiali", 70);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.zhenjian" :),
                }) );
         set_skill("cuff", 100);
         set_skill("strike",100);
         set_skill("force", 100);
         set_skill("dodge", 100);
         set_skill("parry", 100);
         set_skill("sword", 100);
         set_skill("literate",100);
	 set_skill("unarmed",100);
         set_skill("huanhua-jian",100);
	 set_skill("tiexian-quan",100);
	 set_skill("guiyuan-dafa",100);
         set_skill("feihua-wuping",100);

	 map_skill("force","guiyuan-dafa");
	 map_skill("unarmed","tiexian-quan");
	 map_skill("sword","huanhua-jian");
	 map_skill("dodge","feihua-wuping");
	
	 set("chat_chance",30);
         set("chat_msg",({
         "马竟终自言自语道：江湖上的事。。嘿嘿\n",
         "马竟终大笑道：谁能够瞒得过我的眼睛！\n",
        }));
      	set("inquiry", ([
	     "任务" : (: ask_me :), 
	  ]));



      
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

        add_money("gold", 10);
}

void init()
{
	add_action("do_where", "where");
}

int do_where(string arg)
{
	object ob,me,where;
	mapping fam;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "浣花剑派")
		{command( "say 你不是本派弟子，我不能告诉你。");return 1;}
		
	if(!arg || arg=="") {
		command("say 你想找谁？");
		return 1;
	}
	me=this_player();
	ob = find_player(arg);
	if( !ob ) ob = find_living(arg);
	if (!ob) {
		command("say 现在没这个人.");
		return 1;
	}
	where = environment(ob);
	if (!where) {
		command("say 这个人不知道在那里耶...");
		return 1;
	}
	printf(CYN"马竟终想了想，说道：%s(%s)现在在%s.\n"NOR,
		(string)ob->name(),
		(string)ob->query("id"),
		(string)where->query("short"));
	return 1;
}


int ask_me()
{
    object me,obj;
    me=this_player();
    obj=this_object();
    mapping fam;
    if (!(fam = this_player()->query("family")) || fam["family_name"] != "浣花剑派")
		{command( "say 你不是本派弟子，我不能分配你任务。");return 1;}

    command("sigh");
    command("say 这位"+RANK_D->query_respect(me)+"二少爷出门很久了，也不知道现在怎么样了。");
    command("say 你能不能帮我送封信给他呢？");
    me->set_temp("send_letter",1);
           }
     return 1;
}
