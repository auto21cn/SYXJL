// tianlang.c 天狼子
// by QingP
#include <ansi.h>

inherit NPC;
#include "/quest/quest.h"
string ask_me();

void create()
{
	set_name("天狼子", ({ "tianlang zi", "tianlang" }));
	set("nickname", "星宿派三师兄");
	set("long", 
		"他就是丁春秋的三弟子天狼子。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 150000);
	set("score", 30000);

          set_skill("force", 75);
          set_skill("dodge", 75);
          set_skill("strike", 75);
          set_skill("claw", 75);
	  set_skill("poison", 80);
	  set_skill("throwing", 55);
          set_skill("staff", 70);
          set_skill("parry", 70);
	  set_skill("literate", 70);
	set_skill("beiming-zhenqi", 70);
	set_skill("zhaixinggong", 70);
	set_skill("xingchen-zhang", 70);
	set_skill("wugong-zhao", 70);
	set_skill("tianshan-zhang", 75);

	map_skill("force", "beiming-zhenqi");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingchen-zhang");
	map_skill("claw", "wugong-zhao");
	map_skill("parry", "xingchen-zhang");
	map_skill("staff", "tianshan-zhang");
	
	prepare_skill("strike", "xingchen-zhang");
	prepare_skill("claw", "wugong-zhao");
	
	create_family("星宿派", 2, "弟子");

	setup();

	carry_object("/clone/misc/cloth")->wear();
}
/*
     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("shen")>=0&&ob->query("family/master_id")=="tianlang zi")
        {
                      command("chat "+ob->query("name")+"!装什么正道人士，给我滚出星宿派。\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","星宿派" + RED + "弃徒" NOR);   
        }

}      
void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}
*/
