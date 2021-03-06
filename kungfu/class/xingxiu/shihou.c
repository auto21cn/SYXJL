// shihou.c 狮吼子
// by QingP
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("狮吼子", ({ "shihou zi", "shihou" }));
	set("nickname", "星宿派二师兄");
	set("long", 
		"他就是丁春秋的二弟子狮吼子。\n"
		"他四十来岁年纪，双耳上各垂着一只亮晃晃的黄金大环，狮鼻阔口，\n"
		"形貌颇为凶狠诡异，显然不是中土人士。\n");
	set("gender", "男性");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 1100);
	set("max_neili", 1100);
	set("jiali", 30);
	set("combat_exp", 200000);
	set("score", 30000);

          set_skill("force", 95);
          set_skill("dodge", 80);
          set_skill("strike", 85);
          set_skill("claw", 80);
	  set_skill("poison", 90);
	  set_skill("throwing", 60);
          set_skill("staff", 70);
          set_skill("parry", 90);
	  set_skill("literate", 85);
	set_skill("beiming-zhenqi", 85);
	set_skill("zhaixinggong", 75);
	set_skill("xingchen-zhang", 110);
	set_skill("wugong-zhao", 100);
	set_skill("tianshan-zhang", 50);

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

     void init()
{
        object ob;

        ::init();

        ob = this_player();
               if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="shihou zi")
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
