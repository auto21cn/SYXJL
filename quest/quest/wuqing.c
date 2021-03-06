//ds
 
#include <ansi.h>
inherit NPC;

int time_period(int timep,object me);
int potential_lv(int exp);
 
void create()
{
        set("chat_chance", 25);
 
        set_name("无情", ({ "wu qing", "wu"}) );
        set("title",HIW "铁面"NOR);
        set("gender", "男性" );
        set("age", 28);
        set("long",
                "伤心人，断肠客。\n");
	set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set_max_encumbrance(100000000);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set("qi",10000);
        set("max_qi", 10000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 150);
        set("combat_exp", 5000000);
        set("score", 250000);


        set_skill("force", 90);
        set_skill("taiji-shengong", 80);
        set_skill("dodge", 90);
        set_skill("tiyunzong", 80);
        set_skill("unarmed", 90);
        set_skill("taiji-quan", 80);
        set_skill("parry", 90);
        set_skill("sword", 100);
        set_skill("taiji-jian", 90);
        set_skill("taoism", 150);
        set_skill("literate", 60);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

 
	set("inquiry", ([  "无情": "就是本大爷！ \n",]) );
 
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();

}
int accept_fight(object me)
{
        command("say 你想找死啊！");
        return 0;
}
 
void init()
{
        add_action("give_quest", "quest");
}
 
int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num;
        string tag = "1000000";
	string *levels = ({
			"1000",
			"1500",
			"2000",
			"3000",
			"5000",
			"8000",
			"10000",
			"13000",
			"17000",
			"22000",
			"30000",
			"45000",
			"60000",
			"80000",
			"100000",
			"200000",
			"350000",
			"600000",
			"1000000",
			"1500000",
			"2500000",
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
 
        if(combatexp<1000)
          {
        message_vision("无情对$N哼了一声道: 滚！我不要你这种小孩子帮忙！\n",me);
         return 1;
          }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
        if( ((int) me->query("task_time")) >  time() )
        {
          message_vision("无情对$N阴险得笑了起来： 还是先把你的任务完成吧。\n", me);
                  message_vision("然后歪头想了想又说道：你要是决定放弃，就得付点儿费用了。\n",me);
          return 0;
        }
        else
        {
          message_vision("无情对着$N叹了一口气:哎，我就再给你一次机会吧。\n", me);
          me->add("qi",-(int)(me->query("qi")/10));
        }
        }
 
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                      num=j;
                          factor=10;
                          break;
                        }
        }
        if (num>0)
        {
                if (random(50)>45)
                {
                num=num-1;
                }
        } else {
                if ((num<sizeof(levels)-1)&&(random(100)>95))
                {
                num=num+1;
                factor=15;
                }
        }
        tag=levels[num];
        quest = QUEST_D(tag)->query_quest();
        timep = quest["time"];
 
 //       while (quest["quest_type"] == "杀")
 //       {
 //       quest = QUEST_D(tag)->query_quest();
 //       timep = quest["time"];
 //       }
 
        time_period(timep, me);
        if(quest["quest_type"]=="杀")
        tell_object(me,"先替我杀了『"+quest["quest"]+"』,或许我给你好处。\n" NOR);
        else
        tell_object(me,"先找回『"+quest["quest"]+"』给我,或许我给你好处。\n" NOR);
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];
 
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
        return 1;
}
 
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
 
        if(d) time = chinese_number(d) + "天";
        else time = "";
 
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分钟";
        time += chinese_number(s) + "秒";
 
        tell_object(me,HIW "无情说道：\n在" + time + "内");
        return 1;
}
 
int accept_object(object who, object ob)
{
        int bonus, exp, pot,factor;
//	string test;
        mapping quest;

	if (ob->query("money_id")) {
		if ( who->query("quest/quest_type") == "把信送给" ) {
			message_vision("无情对着$N叹了一口气:哎，送信的任务也跑到我这里来取消？\n", who);
			return 0;
		}
		if(!who->query("quest")) {
			message_vision("无情笑道: 那我可就不客气了。\n",who);
			return 1;
		}
		if ( ob->value() < 10000) {
			message_vision("无情盯着$N:这点钱可不够我们的开销呀!\n", who);
			return 1;
		}
		else {
			message_vision("无情无情道: 没用的家伙，给钱了事。\n",who);
			who->set("quest",0);
			return 1;
		}
	}
 
	if(!(quest =  who->query("quest"))) {
		tell_object(who,"无情说道：这不是我想要的。\n");
		return 0;
	}
 
	if( ob->query("name") != quest["quest"]) {
		tell_object(who,"无情说道：这不是我想要的。\n");
		return 0;
	}
 
        if ((int) who->query("task_time") < time() ) {
		tell_object(who,"无情说道：真可惜！你没有在指定的时间内回来！\n");
		destruct(ob);
		return 0;
	}
	else {
		tell_object(who,"无情说道：哦，你还真行，应该得到奖励！\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
//		score = questscore/2 + random(questscore/2);
		factor=who->query("quest_factor");
//		destruct(ob);
 
		if (factor) {
			exp=exp*factor/10;
			pot=pot*factor/10;
//			score=score*factor/10;
		}
 
		bonus = (int) who->query("combat_exp");
		bonus += exp;
		who->set("combat_exp", bonus);
		bonus = (int) who->query("potential");
		bonus = bonus - (int) who->query("learned_points");
		bonus = bonus + pot;
		if ( bonus > potential_lv((int)who->query("combat_exp")) )
		bonus = potential_lv((int)who->query("combat_exp"));
		bonus += (int) who->query("learned_points");
		who->set("potential", bonus );
/*
		bonus = (int) who->query("score");
		bonus += score;
		who->set("score", bonus);
*/
		tell_object(who, HIW"你被奖励了\n" + chinese_number(exp)
			+ "点实战经验\n"+ chinese_number(pot) + "点潜能\n"NOR);
//			+ chinese_number(score)+"点综合评价\n"NOR);
		tell_object(who, "恭喜你完成一个任务！\n");
		who->set("quest", 0 );
		return 1;
	}
	return 1;
}

int potential_lv(int exp)
{
        int grade;

	grade = 100 + exp / 500;
        return grade;
}

