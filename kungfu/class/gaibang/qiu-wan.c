// gaibang npc code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void halt();
void create()
{
        set_name("裘万家", ({"qiu wanjia", "qiu", "wanjia"}));
        set("title","丐帮二袋弟子");
        set("gender", "男性");
        set("age", 27);
        set("long",
                "这是位衣著邋塌，蓬头垢面的丐帮二袋弟子。\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: halt :),
        }));

        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 50);

        set("combat_exp", 10000);

        set_skill("force", 45);
        set_skill("huntian-qigong", 45);
	set_skill("blade", 45);
	set_skill("liuhe-dao", 45);
        set_skill("hand", 45);
        set_skill("shexing-shou", 45);
        set_skill("dodge", 50);
        set_skill("xiaoyaoyou", 45);
        set_skill("parry", 43);
        set_skill("begging", 50);
        set_skill("stealing", 40);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-shou");
	map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("hand", "shexing-shou");

        create_family("丐帮", 25, "弟子");
        setup();
}

void attempt_apprentice(object ob)
{
//        mapping fam;
	object obj;
if( ob->query("combat_exp") < 5500 && !(ob->query("is_beggar") && ob->query("family/family_name")!="丐帮"))
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你了。");
                ob->set("dai", 1);
		ob->set("is_beggar", 1);
		if (ob->query("class")!="bonze")
           	ob->set("class", "beggar");
                command("recruit " + ob->query("id"));
		if(!present("budai", this_player()))
		{
          	      obj=new("/d/gaibang/obj/gaibang-bag");
          	      obj->move(ob);
		}
                this_player()->set("title","丐帮一袋弟子");
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;


}

int accept_object(object ob, object obj)
{
        object me = this_object();
//        mapping my_fam  = me->query("family");
//        mapping ob_fam  = ob->query("family");
        int n;
        n=ob->query("dai");

        if((obj->query("id") == "qingzhu ling")
	&& ((string)ob->query("family/family_name")== "丐帮"))
        {
            if ((int)ob->query("score")<n*100)
             {
               command("say "+RANK_D->query_respect(ob)+"小兄弟对本门的忠心好象还欠缺了一点");
               return 0;
             }
            if (ob->query("combat_exp")<(2000+500*(n-1))*n*n)
             {
               command("say "+RANK_D->query_respect(ob)+"经验不够，那里来的青竹令");
               return 0;
             }
            if (ob->query("dai")==2)
   	     {
                ob->set_temp("fight_ok_2",1);
                command("say 好，既然已得到简长老许可，我们就来验证一下武功。");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
	    }
	    else
	    {
		command("say "+ RANK_D->query_respect(ob) +"袋位不对，我们不能比划。");
	    	return 0;
	    }
	}
        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

int accept_fight(object ob)
{
        object me  = this_object();

        if ( !ob->query_temp("fight_ok_2") ) return 0;
        if (me->is_fighting())
	{
		command("say 我正在没空，" + RANK_D->query_respect(ob) + "可以等会儿再比。");
		return 0;
	}
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

       	remove_call_out("checking");
        call_out("checking", 1, me, ob);

        ob->delete_temp("fight_ok_2");
        me->set("bihua",1);

        return 1;
}

int checking(object me, object ob)
{

        object obj;
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if (me->is_fighting())
        {
                call_out("checking",2, me, ob);
                return 1;
        }

    	if ( !present(ob, environment()) ) return 1;

        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
        {
                command("say 看来" + RANK_D->query_respect(ob) +
                        "还得多加练习，方能在本帮诸多弟子中出人头地 !\n");
                return 1;
        }

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
        {
                command("say 青出於蓝胜於蓝，不愧是丐帮的佳弟子 ! 恭喜你了 !\n");
                message_vision("$N交给$n一个青竹令。\n", me, ob);
                ob->set_temp("have_win",1);
                obj=new("/d/gaibang/obj/qingzhu-ling2");
                obj->move(ob);
                return 1;
        }


        return 1;
}

void halt()
{
        this_object()->delete("bihua");
        return ;
}
