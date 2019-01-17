// /NPC gongzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "yao yue", "yao", "yue" }));
	set("long",
	    "�����ǡ��ƻ������Ŀ�ɽ��ʦ.\n"+
	    "���ñ�������ɴ������,����͸���ǿ���ɴ����Ȼ��ϡ�ɼ�\n"+
	    "����ɫɷ��,�Բ����˼����˿�����,�㲻�ɵö࿴��һ��.\n");
	set("title", "�ƻ�������");
	set("gender", "Ů��");
	set("age", 36);
	set("nickname", HIR "ɱ�����¸��ĺ�" NOR);
      set("shen_type",-500);
	set("attitude", "peaceful");

    set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 4000);
    set("max_jing", 5000);
      set("neili", 9000);
    set("max_neili", 9000);
      set("jiali", 100);

      set("combat_exp", 10000000);
	set("score", 2000000);
	set_skill("force", 400);
	set_skill("unarmed", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("sword",400);
        set_skill("literate",400);

	set_skill("jueqing-zhang",400);
	set_skill("mingyu-shengong",400);
	set_skill("yifeng-jian",400);
        set_skill("yihua-jiemu",400);

	map_skill("force", "mingyu-shengong");
	map_skill("unarmed", "jueqing-zhang");
		map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "yihua-jiemu");
        map_skill("sword","yifeng-jian");

	create_family("�ƻ���",1, "���¹���");
set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yifeng" :),
			}) );
	setup();
	carry_object("/d/city/obj/changjian")->wield();
    carry_object("/d/yihua/obj/jinlvyi")->wear();
       
}

void attempt_apprentice(object ob)
{
   
   if ((string)ob->query("gender")!="Ů��")
           {
 		command("chat* heihei");
                command("chat ����һ����޵ľ�������,��ȥ����!");
                kill_ob(this_player());
                command("perform yifeng");
		return;
	   }
   if ((int)ob->query_skill("dodge", 1) < 100) 
           {
		command("say " + RANK_D->query_respect(ob) + "�����������!");
		return;
	   }
   if ((int)ob->query_skill("mingyu-shengong", 1) < 130) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö�����ڤ���񹦣�");
		return;
	   }
   if ((int)ob->query_skill("yifeng-jian", 1) < 130) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������Ʒ罣����");
		return;
	   }
   if (ob->query_per() < 19) 
      	   {
		command("say ƾ����ģ���������Ϊʦ.");
		return;
	   }
   if (ob->query_con() < 40) 
      	   {
		command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
		return;
	   }
    if((int)ob->query("score") <2000)
            {
        command("say" + RANK_D->query_respect(ob) + "��Ա��ŵĹ����Ƿ�̫����Щ? ");
        return;
        }
   command("recruit " + ob->query("id"));
   if((string)ob->query("class") != "chuanren")
     ob->set("class", "chuanren");
   return;
}

void init()
{
	object ob;

	::init();

	ob = this_player();

	if (interactive(ob) && (!ob->query("gender") || ob->query("gender")!="Ů��"))
	{
			command("heihei");
			command("say ��ƽ�����������ˣ��㾹Ȼ���������ðɣ��Ҿͳ�ȫ���㣡\n");
			remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
                        command("perform yifeng");
	}
	else if(ob->query("gender")=="Ů��")
	{
	command("smile");
	command("say �����㲻�����˲�Ȼ������úܲҡ�");
	}
}