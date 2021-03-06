// dragon.c created by aeolus 烈炎 5/8/99
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
int ask_sword();
int ask_ball();
int ask_go();
int do_powerup();

void create()
{
        set_name(HIW"小云龙"NOR ,( { "dragon"} ) );

        set("nickname", HIG "烈炎的宠物" NOR );
        set("title", HIW "火云殿守护兽" NOR );
        set("long", 
                "这是一只守护神殿的云龙。别看它平时这么乖巧哦！你要是激怒了它可不是闹着玩的。\n");              
        set("age", 10);
        set("attitude", "heroism");
	set("qi", 1000);
	set("jing", 1000);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("shen_type", 1);
        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("kar", 25);
        set("per", 30);
	set_skill("dodge", 250);
	set_skill("force", 250);
	set_skill("parry", 250);
	set_skill("hand", 250);
	set_skill("claw", 250);
	set_skill("yunlong-shenfa", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("yunlong-shou", 250);
	set_skill("yunlong-zhua", 250);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-zhua");
	map_skill("claw", "yunlong-zhua");

	prepare_skill("hand", "yunlong-shou");
	prepare_skill("claw", "yunlong-zhua");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

        set("limbs", ({ "龙角", "龙头", "龙腹", "龙爪", "龙背", "龙尾" }) );

        set("inquiry", ([
	    "出发"	: (: ask_go :),
	    "follow me"	: (: ask_go :),
	    "powerup"	: (: do_powerup :),
	    "龙珠"	: (: ask_ball :), 
	    "ball"	: (: ask_ball :), 
	    "aeolus"	: "我的主人，他待我可好了。当年他为了赋予我生命都不知透支了多少法力。\n",
	    "烈炎"	: "我最最尊敬的人。\n",
	    "renee"	: "烈炎少爷心仪的人。\n",
	    "batian"	: (: ask_sword :),
	    "霸天云龙剑": (: ask_sword :),
	]));
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
        
        set("combat_exp", 1000000);

	set("env/wimpy", 60);
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "powerup" :),
        }) );
        setup();
	add_money("gold", 10);
}

void init()
{
object ob;
ob=this_player();
::init();
remove_call_out("greeting");
call_out("greeting", 1, ob);

	add_action("do_attack","attack");
	add_action("do_stop","stop");
	add_action("do_send","gift");
	add_action("do_kill","murder");
}

int do_powerup()
{
  object me;
  string host_id;
  me=this_player();

	if(query("id")!="dragon")
	{	
		sscanf(query("id"),"%s's dragon",host_id);
		if(me->query("id")==host_id)
		{
		message_vision("$N"HIY"突然仰空发出一声龙吟，能量以倍数上升.\n"NOR,this_object());
		add("combat_exp",100000);
		return 1;
		}
	}
	message_vision("$N"CYN"鄙视地说道:呸,你凭什么命令我？\n"NOR, this_object());
	return 1;
}

int ask_ball()
{
	object me;
	object ball;
	me=this_player();

	set("ball_count",7);

	if(me->query("id")!=("aeolus")&&me->query("weiwang")<10000){
		message_vision("$N"CYN"说:你在武林中寂寂无名，凭什么问津秘宝龙珠？\n"NOR, this_object());
		return 0;
	}
	if(query("ball_count")<1){
		message_vision("$N"CYN"说:说:对不起!秘宝龙珠已经全被拿走了.\n"NOR, this_object());
		return 0;
	}
	if(!present("dragon ball", me)
	&& query("ball_count") >= 1)
	{
		add("ball_count", -1);
		ball = new("/u/aeolus/dragonball");
		ball->move(me);
		message_vision(HIY"小云龙张开口，突然金光四射。在夺目的金光笼罩下赫然是一颗传闻中的秘宝－“龙珠”。\n"NOR,this_player());
	return 1;
	}
}

int ask_sword()
{
	object me;
	object sword;
	me=this_player();

	if(me->query("id")!=("aeolus")&&me->query("weiwang")<10000){
		message_vision(HIY"$N说：“烈炎少爷，$n竟想要霸天云龙剑！\n"NOR, this_object(),this_object());
	return 0;
	}
	else
	{
		sword = new("/u/aeolus/batian.c");
		sword->move(me);
		message_vision(HIY"$N说：“烈炎少爷接霸天云龙剑！。\n"NOR,this_object());
	return 1;
	}
}
int ask_go()
{
	object me;
	string new_name,new_id,host_id;
	me=this_player();

	if(query("id")!="dragon"){
		 sscanf(query("id"),"%s's dragon",host_id);
		 if(query("id")==host_id)
           {say(query("name")+"睁大深蓝色的大眼睛看着"+me->query("name")+"，说:当然啦,我对主人绝对忠心。\n");
            		return 1;
           }
	 if(me->query("id")!=host_id)
           {say(query("name")+"眨了眨深蓝色的大眼睛看着"+me->query("name")+"，说:不行,我得听我主人的。\n");
			return 1;
           }
	 }
	 if(me->query("id")=="aeolus")
	   {
	   write( HIY "小云龙道:烈炎少爷创造了我小白龙，是我小白龙最尊敬的人。\n" NOR);
	   write( HIY "现在烈炎少爷要我一同闯荡江湖，正是我小白龙梦寐以求的事情啊！\n" NOR);
	   command("nod");	
	   set_leader(me);
       new_name = me->query("name")+"的宠物小云龙";
       new_id=me->query("id")+"'s dragon";
       set("name",new_name);
       set("id",new_id);
	   write( "可用指令:\nattack sb 攻击某人.\nmurder sb 杀死某人.\nstop 停止战斗.\ngift sb.--把小云龙送给sb.\n");
	   set("long","这是"+new_name+"。\n"+
		"一只威武的小白龙，平时负责守卫火云殿，现在受烈炎之命出殿维持人间的秩序。;\n"+
		"深蓝色的双眼犹如两束闪电直看进你心里。\n");
          }
         else if(present("batian",this_player())) 
	   {
	   write( HIY "小云龙道:烈炎少爷待我情同手足，您对火云殿又有大恩。\n" NOR);
	   write( HIY "烈炎少爷要我跟随主人闯荡江湖，我一定尽心尽力。\n" NOR);
	   command("nod");	
	   set_leader(me);
       new_name = me->query("name")+"的宠物小云龙";
       new_id=me->query("id")+"'s dragon";
       set("name",new_name);
       set("id",new_id);
	   write( "可用指令:\nattack sb 攻击某人.\nmurder sb 杀死某人.\nstop 停止战斗.\ngift sb.--把小云龙送给sb.\n");
	   set("long","这是"+new_name+"。\n"+
		"一只威武的小白龙，平时负责守卫火云殿。受烈炎所托为"+me->query("name")+"办事。;\n"+
		"深蓝色的双眼犹如两束闪电直看进你心里。\n");
       }
	   else say(query("name")+"睁大深蓝的大眼睛看着"+me->query("name")+"，说:不行的,烈炎少爷没有同意。\n");
return 1;
}

int do_attack(string arg)
{
  object ob; 
  string host_id;
  object me=this_player();
  if(query("id")=="dragon")
   {say("你无权使用此命令。\n");
    return 0;}
  sscanf(query("id"),"%s's dragon",host_id);
  if(me->query("id")!=host_id)
  return notify_fail("小云龙连理都不理你！\n");
  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("小云龙傻呼呼地望着你，不明白你的意思。\n");
  if(!living(ob)) 
	 return notify_fail("小云龙说:"
              +ob->query("name")+"报告主人: 此人已死。\n");
  message_vision( HIY "小云龙对主人$N点头道:遵命！这就去给$n一点小惩大戒。\n" NOR,me,ob);
  fight_ob(ob);
  return 1;
}

int do_kill(string arg)
{
	string host_id;
	object ob;
	object me=this_player();
  if(query("id")=="dragon")
   {say("你无权使用此命令。\n");
    return 0;}
  	sscanf(query("id"),"%s's dragon",host_id);
  	if(me->query("id")!=host_id)
  	 return notify_fail("小云龙连理都不理你！\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("你要小云龙杀谁？\n");
  if(!living(ob)) 
	 return notify_fail("小云龙说:"
              +ob->query("name")+"报告主人: 此人已死。\n");
	if(!environment(ob)->query("no_fight"))
	{
        message_vision( HIY "小云龙对$n歉然一笑，说道:并不是我跟你有什么过节，只是我受主人$N之命要取你颈上人头。\n" NOR,me,ob);
	remove_call_out("kill_ob");
  	call_out("kill_ob", 1, ob); 
	}
	return 1;
}  

int do_stop()
{
   string host_id;
  object me=this_player();
  if(query("id")=="dragon")
   return notify_fail("你无权使用此命令。\n");
  sscanf(query("id"),"%s's dragon",host_id);
  if(me->query("id")!=host_id)
   return notify_fail("小云龙连理都不理你！\n");
 if(!is_fighting())
	 return notify_fail("小云龙现在没和人打斗.\n");
 command("halt");
 message_vision( HIY "小云龙一招“龙飞九天”无影无形地跃回主人$N的身边。\n" NOR,me);
 return 1;
}

int do_send(string arg)
{
  object ob; string host_id,new_name,new_id;
  object me=this_player();
  if(query("id")=="dragon")
   return notify_fail("你无权使用此命令。\n");
  sscanf(query("id"),"%s's dragon",host_id);
  if(me->query("id")!=host_id)
   return notify_fail("小云龙连理都不理你！\n");

  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("你要把小云龙送给谁？\n");
  if(!living(ob)) 
	 return notify_fail("你只能把小云龙给活人!\n");
 message_vision( HIY "小云龙难过地望着主人$N，说:\n“主人的大恩大得来日再报...小云龙就此别过。”\n" NOR,me);
 set_leader(ob);
 new_name = ob->query("name")+"的侍卫小云龙";
	   set("long","这是"+new_name+"。\n"+
		"一只威武的小白龙，平时负责守卫火云殿。现在由烈炎派到凡间上来了。;\n"+
		"深蓝色的双眼犹如两束闪电直看进你心里，眼神中却流露出一丝无奈和悲哀。\n");
 new_id=ob->query("id")+"'s dragon";
 set("name",new_name);
 set("id",new_id);
 write( HIY "小云龙对新主人"+ob->query("name")+"潇洒地一拜。\n" NOR);
 message_vision("可用指令:\nattack sb 攻击某人.\nsha sb 杀死某人.\nstop 停止战斗.\ngift sb.--把小云龙送给sb.\n",me);
 return 1;
}     

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query("id")==("aeolus")){
	write(CYN"小云龙高兴的地说：烈炎少爷辛苦了！\n"NOR);
	return;
	} else {         
	write(CYN"小云龙礼貌地说："+ob->query("name")+""+RANK_D->query_respect(ob)+",你好.\n"NOR);
	}
}