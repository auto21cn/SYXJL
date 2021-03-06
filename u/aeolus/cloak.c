// 龙鳞战甲 by Aeolus 5/30/99
// 1999-2000 (C)opyright Aeolus All Right Reserved

#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
inherit F_COMMAND;

void create()
{
	seteuid(getuid());
	set_name(HIY "龙鳞战甲" NOR, ({ "cloak" }));

	set("unit","件");
	set("no_drop",1);
	set("no_get",1);
	set("material", "cloth");
	set("armor_prop/armor", 1000);
	set("armor_prop/dodge", 1000);
	set("light",1);
	setup();
}

void init()
{

       seteuid(geteuid());
       if (geteuid(this_player()) != "aeolus"){
	add_action ("do_give","give");
	add_action ("do_present","gift");
	set("long",@LONG
[1;35m法宝已被封引，只能用以下法力：
[1;32m--------------------------------------------------
| [1;33m咒语名 [1;32m|     [1;33m用  法       [1;32m|      [1;33m效   果       [1;32m|
|------------------------------------------------|
|  gift  [1;32m| gift <file name> [1;32m|给玩家发礼物。      [1;32m|
|--------|------------------|--------------------|
|  give  [1;32m| give<cloak>to<id>[1;32m|给某人龙鳞战甲。    [1;32m|
[1;32m--------------------------------------------------[2;37;0m
LONG );
	return;
       } else {
	set("long",@LONG
    [1;33m这是一件龙鳞战甲，烈炎的终极法宝。[2;37;0m
[37m～～～～～～～～－[1;32m〖[1;31m咒语口诀[1;32m〗[2;37;0m[37m～～～～～～～～～～
       ---[1;32m临 [1;37m冰 [1;33m斗 [2;37;0m[31m者 [1;34m皆 [1;35m阵 [1;31m列 [1;36m在 [2;37;0m[33m前[2;37;0m[37m---      
拥有法宝之人有三大禁忌：【1】心术不正者。
                        【2】不会编程者。
                        【3】非天界之神者。

注：标有*号的可以随时随地的对某人使用，只要知道其
英文名，而且其在线上，任何地方都有效果（NPC也一样
有用，但要在NPC面前使用。）
[1;32m--------------------------------------------------
| [1;33m咒语名 [1;32m|     [1;33m用  法       [1;32m|      [1;33m效   果       [1;32m|
|------------------------------------------------|
|*full   [1;32m|full <id>         [1;32m|用来恢复某人的精气  [1;32m|
|*suck   [1;32m|suck <id>         [1;32m|吸收某人的精气      [1;32m|
| take   [1;32m|take<genre><value>[1;32m|变钱，一张变数张    [1;32m|   
|--------|------------------|--------------------|
|*whereis[1;32m| whereis <id>     [1;32m|列出所有线上人的位置[1;32m|
|provoke [1;32m|provoke<ob>and<id>[1;32m|挑拨某人和某人打架。[1;32m|
|  nk    [1;32m| nk <ob> with <id>[1;32m|让某人杀某人。      [1;32m|
|  pk    [1;32m| pk <id> with <id>[1;32m|让玩家对杀。        [1;32m| 
|*cease  [1;32m| cease <id>       [1;32m|让某人不再打架。    [1;32m|
|*dizzy  [1;32m| faint <id>       [1;32m|让某人晕倒。        [1;32m|
|*wake   [1;32m| wake <id>        [1;32m|让某人苏醒。        [1;32m|
|*chuqiao[1;32m| chuqiao <id>     [1;32m|放剑杀某人。        [1;32m|
|*revive [1;32m| revive <id>      [1;32m|起死回生(恢复武功)  [1;32m|
|  act   [1;32m| act <id> <msg>   [1;32m|装扮某人说话。      [1;32m|
|overhear[1;32m| overhear <id>    [1;32m|监听某人所做的一切  [1;32m|
|  fly   [1;32m| fly <id>or<place>[1;32m|去某人所在的地方    [1;32m|
|*freeze [1;32m| freeze <id>      [1;32m|冻结某人。          [1;32m|
|*defrost[1;32m| defrost <id>     [1;32m|解封某人。          [1;32m|
|*offline[1;32m| offline <id>     [1;32m|赶某人下线！        [1;32m|
|  gift  [1;32m| gift <file name> [1;32m|给玩家发礼物。      [1;32m|
|  give  [1;32m| give<cloak>to<id>[1;32m|给某人龙鳞战甲。    [1;32m|
|待续......                                      |[2;37;0m
LONG);
       add_action("do_full","full");
       add_action("do_suck","suck");
       add_action("do_take","take");
       add_action ("do_whereis", "whereis");
       add_action ("do_provoke", "provoke");
       add_action ("do_mob", "nk");
       add_action ("do_killer","pk");
       add_action ("do_halt","cease");
       add_action ("do_faint","dizzy"); 
       add_action ("do_wakeup", "wake");
       add_action ("do_die","chuqiao");
       add_action ("do_reincarnate","revive");
       add_action ("do_act","act");
       add_action ("do_snoop","overhear");
       add_action ("do_goto","fly");
       add_action ("do_closecommand","freeze");
       add_action ("do_opencommand","defrost");
       add_action ("do_offline","offline");
       add_action ("do_command","order");
       add_action ("do_give","give");
       add_action ("do_present","gift");
       this_player()->set_temp("heat",1);
       }
}

int do_present(string str)
{
        int i;
        object ob,*inv;
        object me;
        inv=users();
        me=this_player();
        if(!str) return notify_fail(YEL"战甲之魂说：你想发什么东西给所有在线玩家？\n"NOR);
 	if(file_size(str) == -1) return notify_fail(YEL"战甲之魂说：没有这个东西\n"NOR);
	for(i=0;i<sizeof(inv);i++)
	{
//		if(!wizardp(inv[i]) ) continue;
		ob=new(str);
		ob->move(inv[i]);
		tell_object(inv[i],HIR""+me->name()+"高声宣布：当当当。。。发礼物啦！！！\n
		忽然亮光一闪，你觉得身上好象多了点什么东西！仔细一看：原来是"+ob->name()+"\n"NOR);

	}
	if (me->query("id")!="aeolus") log_file("GIFT", sprintf("%s 给玩家们发 %s\n", me->name(), ob->name() ));
	return 1;
}

int do_full(string str, object ob)
{
  int max;
  object me;
  if (!geteuid()) seteuid (getuid());
  if(!str){
	me=this_player();
	message_vision(HIY"$N脸上泛起神光，手缓缓地结着「不动明皇印」，口中轻轻地念着「灵血咒」。疲惫的$N渐渐地变得神采奕奕 ...\n"NOR, me);
  } else {
	ob=this_player();
	me = LOGIN_D->find_body(str);
	message_vision(HIY"$N脸上泛起神光，手缓缓地结着「不动明皇印」，口中轻轻地念着「灵血咒」。疲惫的$n渐渐地变得神采奕奕 ...\n"NOR, ob, me);
	if (!me) return notify_fail (YEL"战甲之魂说：对象错误: 找不到"+str+"\n"NOR);
  }
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("eff_kee",max);
  me->set("kee",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);

// modified by aeolus
  max = me->query("max_jing");
  me->set("eff_jing",max);
  me->set("jing",max);
  max = me->query("max_qi");
  me->set("eff_qi",max);
  me->set("qi",max);
  max = me->query("max_jingli");
  me->set("eff_jingli",max);
  max = me->query("max_neili");
  me->set("eff_neili",max);

  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  me->clear_condition();
  return 1;
}

int do_suck(string str, object ob)
{
  int min;
  object me;
  if (!geteuid()) seteuid (getuid());
  if(!str)
	return notify_fail (YEL"战甲之魂说：你想吸自己的元气？有用吗？\n"NOR);
  else {
	ob=this_player();  
	me = LOGIN_D->find_body(str);
	message_vision(HIY"$N脸上露出和蔼的笑容，手结「慈悲印」，口中念着「静心咒」。野蛮的$n突然全身脱力，差点昏倒 ...\n"NOR, ob, me);
	if (!me) return notify_fail (YEL"战甲之魂说: 摧毁对象错误: 找不到"+str+"\n"NOR);
  }
  min = me->query("min_gin");
  me->set("eff_gin",min);
  me->set("gin",min);
  min = me->query("min_kee");
  me->set("eff_kee",min);
  me->set("kee",min);
  min = me->query("min_sen");
  me->set("eff_sen",min);
  me->set("sen",min);

// modified by aeolus
  min = me->query("min_jing");
  me->set("eff_jing",min);
  me->set("jing",min);
  min = me->query("min_qi");
  me->set("eff_qi",min);
  me->set("qi",min);
  min = me->query("min_jingli");
  me->set("eff_jingli",min);
  min = me->query("min_neili");
  me->set("eff_neili",min);

  min = me->min_food_capacity();
  me->set("food",min);
  min = me->min_water_capacity();  
  me->set("water",min);

  return 1;

}

int do_take(string str)
{
        string kind;
        int amount;
        object n_money;

        if( !str || sscanf(str, "%d %s", amount, kind)!=2 )
          return notify_fail(HIM"Syntax: take <多少钱> <钱币种类>\n注：你首先必须有这种钱！"NOR);

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail(YEL"战甲之魂说：你分文没有，摇个屁呀！\n"NOR);
        if( amount < 1 )
                return notify_fail(YEL"你要多少？\n"NOR);

        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

		message_vision( sprintf(HIY"$N从龙鳞战甲的口袋中掏出%s%s%s"+HIY+"。\n"NOR,
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                       this_player());
               return 1;
}

int do_whereis(string str)
{
  object where, me, fd;
  object *ob;
  string msg;
  int i;
  if (str!=NULL_VALUE){
    fd = LOGIN_D->find_body(str);
    if (!fd) return notify_fail(YEL"战甲之魂对你大嚷：“在网上好象没这个人呀！”\n"NOR);
    }
  me = this_player();
  if (str) {
    where = environment(find_player(str));
    if (!where) return notify_fail (YEL"战甲之魂向你报告：他在异次元空间。\n"NOR);
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
    msg += where->query("long");
  }
  else {
    
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;

}

//added by aeolus 5/30/99 
int do_provoke(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail (YEL"战甲之魂说：你想让谁 fight 谁啊\n"NOR);
        if (sscanf( str,"%s and %s",st1,st2)!=2 )
           return notify_fail (YEL"Syntax: provoke <ob1> and <ob2>\n"NOR);

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail(YEL"战甲之魂说：找不到 "+st1+" 这个生物.\n"NOR);

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail(YEL"战甲之魂说：找不到 "+st2+" 这个生物.\n"NOR);

       message_vision(HIR ""+ob1->name()+"对着"+ob2->name()+"叫阵：「出手吧！」。\n" NOR,
       this_player());
               ob1->fight_ob(ob2);
               return 1;
}

int do_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail (YEL"战甲之魂说：你想让谁 nk 谁啊\n"NOR);
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail (YEL"Syntax: nk <ob1> with <ob2>\n"NOR);

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail(YEL"战甲之魂说：找不到 "+st1+" 这个生物.\n"NOR);

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail(YEL"战甲之魂说：找不到 "+st2+" 这个生物.\n"NOR);

       message_vision(HIR ""+ob1->name()+"对着"+ob2->name()+"大喝一声：「拿命来」。\n" NOR,
       this_player());
               ob1->kill_ob(ob2);
               return 1;
}

int do_killer(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail (YEL"战甲之魂说：你想让谁和谁结仇啊?\n"NOR);
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail (YEL"Syntax: pk <ob1> with <ob2>\n"NOR);
       if (!ob1 = LOGIN_D->find_body(st1))
          return notify_fail(YEL"找不到 "+st1+" 这个生物.\n"NOR);

        if (!ob2 = LOGIN_D->find_body(st2))
          return notify_fail(YEL"找不到 "+st2+" 这个生物.\n"NOR);
       ob1->set_temp("looking_for_trouble", 0);
       ob2->set_temp("looking_for_trouble", 0);
       ob1->kill_ob(ob2);
       write(YEL "战甲之魂说：“挑拨成功！”\n" NOR);
       return 1;
}

int do_halt (string str)
{
  object ob;
  if (!str) return notify_fail(HIM"Syntax: cease <id>\n"NOR);
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail(YEL"战甲之魂说：线上无此人！\n"NOR);       
  if( !ob->is_fighting() )
       return notify_fail(YEL"战甲之魂说：那人现在并没有打斗中。\n"NOR);

  tell_room(environment(ob),HIW "天空中忽然出现了"+(string)this_player()->query("name")+"神俊的身影。\n他和蔼的对"+(string)ob->query("name")+"说道：“得饶人处且饶人，我看这位"+RANK_D->query_respect(ob)+"还是算了吧！”\n" NOR, ob);
  tell_object(ob,HIW "天空中忽然出现了"+(string)this_player()->query("name")+"神俊的身影。\n他和蔼的对你说到：“得饶人处且饶人，我看这位"+RANK_D->query_respect(ob)+"还是算了吧！”\n"NOR, ob);
  ob->remove_all_killer();
  tell_room(environment(ob),CYN "嗯！"+(string)ob->query("name")+"说到：“您说的对，我不想再打了。”\n" NOR, ob);
  tell_object(ob,CYN "嗯！你说到：“您说的对，我不想再打了。”\n" NOR, ob);
  tell_room(environment(ob), HIG"..."+(string)ob->query("name")+"终于受到感召，决定不斗了！\n"NOR, ob);
  tell_object(ob, HIG"...你终于受到感召，决定不斗了！\n"NOR, ob);
  return 1;    
}

int do_faint (string str)
{
  object who;
  object me=this_player();
  if (!str) return notify_fail (YEL"战甲之魂说：你不能把你自己弄晕！\n"NOR);
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail (YEL"战甲之魂说：“ 没有"+str+"”\n"NOR);
  }
  message_vision( HIR "$N突然瞪着$n。四目相交，$n顿时昏昏欲睡，最后“叭”地一声昏倒在地上。\n" NOR,me,who);
  who->delete("env/immortal");
  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  return 1;
}

int do_wakeup (string str)
{
  object who;
  object me=this_player();
  if (!str) return notify_fail (HIM"Syntax: wake <id>\n"NOR);
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail (YEL"战甲之魂说：“ 没有"+str+"”\n"NOR);
  }
  message_vision( HIG "$N喃喃自语，念着一些没有人懂的咒语。不一会儿，$n从地上爬了起来。\n" NOR,me,who);
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}

int do_die (string str, object me)
{
       object ob;
  if (!str) return notify_fail(HIM"Syntax: chuqiao <id>\n"NOR);
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail(YEL"战甲之魂说：没法出鞘，没这个人。\n"NOR);
       me=this_player();
  message_vision(HIY"只见$N用手对着天空一指，大叫：“霸天云龙剑出鞘”。\n一把巨剑从$N身后的剑鞘里飞到了空中，发出一声惊天动地的破空之声，绝尘而去...\n" NOR, me);
  message_vision(HIR "一把巨剑从天而降，声如惊雷，势如闪电。只见巨剑从$N的天灵盖插入，然后巨剑抽身飞回空中，绝尘而去。\n"NOR, ob);
  ob->delete("env/immortal");
  ob->die();
  ob->set_temp("last_damage_from", "被霸天云龙剑插");
  message_vision(HIY "只见$N用手对着天空一指，大叫：“霸天云龙剑回鞘”，\n一把巨剑从天空中回到了$N身后的剑鞘里。\n"NOR, me);
  return 1;
}

int do_reincarnate(string str)
{
  object ob;
  if (!str) return notify_fail(HIM"Syntax: revive <id>\n"NOR);
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail(YEL"战甲之魂说：有这个人吗？\n"NOR);
  if (ob->is_ghost()){
	   write(HIW"战甲之魂说：起死回生程序启动中 ... Revival Program Initializing ...\n"NOR);
           tell_object(ob,HIG"3... 2... 1... 对你进行全身检查中 ...\n"NOR);
     } else { 
           return notify_fail(YEL"战甲之魂说：咦...这个人好象是活的！\n"NOR);
  }
  write(HIW"战甲之魂说：扫描中 ... Scanning Object ...\n"NOR);
  tell_object(ob,HIB"扫描中 ... ... 你是鬼!需要让你复活！并恢复你死前的一切数据。\n"NOR);
  tell_room(environment(ob),HIY"一束金光突然从云上射下来，笼罩在"+(string)ob->query("name")+"的周围。\n"NOR, ob);
  tell_object(ob,HIG"突然一个声音在你儿边响起，“上天怜悯你。可怜的人，复活吧　...”，\n你突然感到一阵昏厥...\n"NOR);
  ob->reincarnate();

  ob->add("kill/killer_die",-1);
  if(ob->query("normal_die")>=1)
	ob->add("normal_die",-1);
   else 
	ob->delete("normal_die",0);

  if(ob->query("dietimes")>=1)
	ob->add("dietimes",-1);
   else 
	ob->delete("dietimes",0);

  if(ob->query("death_count")>=1)
	ob->add("death_count",-1);
   else 
	ob->delete("death_count",0);

  ob->move("/d/city/guangchang");
  ob->save();
  tell_object(ob,CYN"你看了看头上的烈日，满街的人群，觉得恍如隔世，怀疑自己刚刚做了一个恶梦！\n"NOR);
  write(HIW"战甲之魂说：复活成功! Revived Successfully!\n"NOR);
  return 1;    
}

int do_act(string str)
{
        object ob1;
        string st1,st2;

        if (!str || str=="") return notify_fail (YEL"战甲之魂说：你要装扮谁来说话？\n"NOR);
        if (sscanf( str,"%s say %s",st1,st2)!=2 )
               return notify_fail (YEL"act <id> say <message>\n"NOR);
       if (!ob1=present(st1,environment(this_player())))
               return notify_fail(YEL"战甲之魂说：这里好象没有"+st1+"吧。\n"NOR);
       message("sound", CYN + ob1->name() + "说道：" + CYN +  st2 + "\n" NOR, environment(ob1), ob1);
       return 1;
}

int do_snoop(string str)
{
        object me=this_player();
        object ob;
        object obj;
        if( !str ) {
                if( objectp(ob = query_snooping(me)) )
                        write(YEL"【战甲之魂】：你现在正在监听" + ob->query("name") + ""YEL"所收到的讯息！！\n"NOR);
                return 1;

        } else if( str=="none" ) {
              if( objectp(ob = query_snooping(me))
              &&      wiz_level(ob) >= wiz_level(me) )
                snoop(me);
                write(HIG "你现在停止监听别人的讯息。\n" NOR);
                return 1;
	}

        ob = find_player(str);
        if(!ob) ob = find_living(str);
        if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");
        if( wiz_level(me) < wiz_level(ob) )
                return notify_fail(YEL"【战甲之魂】：你没有监听" + ob->name() + "所收听讯息的权利。\n"NOR);

        if( me==ob ) return notify_fail(YEL"【战甲之魂】：请用 snoop none 解除监听。\n"NOR);
                
        snoop(me, ob);
        write(YEL"【战甲之魂】：你现在开始窃听" + ob->name(1) + "所收到的讯息。\n"NOR);
/*
        if (me->query("id")!="aeolus") {
        if( userp(ob) ) log_file("SNOOP_PLAYER",
                sprintf("%s(%s) 监听 %s 于 %s.\n", me->name(1), geteuid(me), ob->name(1),
                        ctime(time()) ) );
        }
*/
        if( find_player("aeolus")) {
                obj = find_player("aeolus");
                tell_object(obj,YEL+"【战甲之魂】："+HIG+""+me->query("name")+""+YEL+"开始监听"+HIM+""+ ob->query("name")+""+YEL+"所收到的讯息。\n"NOR);
        }
        return 1;
}

int do_goto(string str)
{
        object me=this_player();
        int goto_inventory = 0;
        object obj;

        if( !str ) return notify_fail(YEL"战甲之魂说：你要去哪里？\n"NOR);

        if( sscanf(str, "-i %s", str) ) goto_inventory = 1;

        obj = find_player(str);
        if(!obj) obj = find_living(str);
        if(!obj || !me->visible(obj)) {
                str = resolve_path(me->query("cwd"), str);
                if( !sscanf(str, "%*s.c") ) str += ".c";
                if( !(obj = find_object(str)) ) {
                        if( file_size(str)>=0 )
                                return me->move(str);
                        return notify_fail(YEL"战甲之魂说：没有这个玩家、生物、或地方。\n"NOR);
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail(YEL"战甲之魂说：这个物件没有环境可以 goto。\n"NOR);

        me->move(obj);

        return 1;
}

int do_closecommand(string arg)
{
        object me=this_player(),victim;
        if( me != this_player(1) ) return 0;

        if( !wizardp(me) ) return 0;

        if( !arg )
                return notify_fail(YEL"战甲之魂说：封印谁？\n"NOR);
        victim = LOGIN_D->find_body(arg);
        if (!victim) victim = present(arg, environment(me));
        if( !victim || !victim->is_character())
                return notify_fail(YEL"战甲之魂说：没有此人。\n"NOR);

        if( victim->name() == "aeolus") {
                tell_object(me, "你拿起<封魔咒>吞了下去，一命呜呼~\n");
                me->delete("env/immortal");
                me->die();
        }
	message_vision(HIB"$N手一扬，一张印有<封魔咒>三字的符纸向$n飞了过来。$n还没有反应过来，符纸已经沾上了$n的头...\n"NOR, me, victim);
	victim->set_temp("block_msg/all",1);
	victim->disable_player();
	victim->set("disable_type",HIB"<封魔咒>"NOR);
	victim->save();

        return 1;
}

int do_opencommand(string arg)
{
        object me=this_player(),victim;
        if( me != this_player(1) ) return 0;

        if( !wizardp(me) ) return 0;

        if( !arg )
                return notify_fail(YEL"战甲之魂说：给谁解封？\n"NOR);
        victim = LOGIN_D->find_body(arg);
        if (!victim) victim = present(arg, environment(me));
        if( !victim || !victim->is_character())
                return notify_fail(YEL"战甲之魂说：没有此人！\n"NOR);

	message_vision(HIB"$N一扬手，<封魔咒>从$n的头上飞起，落$N的手中。$n立刻觉得全身舒泰，又恢复自由了 ...\n"NOR, me, victim);
	victim->set_temp("block_msg/all",0);
	victim->enable_player();
	victim->delete("disable_type");
	victim->save();

        return 1;
}

int do_offline (string str)
{
  object ob;
  seteuid(ROOT_UID);
  if (!str) return notify_fail(HIM"Syntax: offline <id>\n"NOR);
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail(YEL"战甲之魂说：没找到这个人。\n"NOR);     
  if (ob->query("name")=="烈炎") {
       tell_object(ob,""+this_player()->query("name")+"（"+this_player()->query("id")+"）这个痴呆要把你赶走！\n");
       return notify_fail(HIR"战甲之魂愤怒地说道：你连烈炎都想赶走？没门儿！\n"NOR);
       }  
  tell_object(ob,HIR"「龙鳞战甲」告诉你：你违反了天条，请你下线去吧...\n"NOR);
  destruct(ob);
  if(ob) write(YEL"战甲之魂说：你无法将这个人赶走。\n"NOR);
        else write(YEL"战甲之魂说："+ob->query("name")+"（"+ob->query("id")+"）已经被赶下线了！\n"NOR);
  return 1;    
}

int do_command(string str)
{
        int res;
        object ob;
        string who, cmd, verb, path;
        object me=this_player();

        if( me != this_player(1) ) return 0;

        if( !wizardp(me) ) return 0;

        if( !str || str=="" || sscanf(str, "%s to %s", who, cmd)!=2 )
                return notify_fail(YEL"战甲之魂说：你要命令谁做什么？\n"NOR);
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
        if( !ob || !ob->is_character())
                return notify_fail(YEL"战甲之魂说：没有此人！\n"NOR);

        if( sscanf(cmd, "%s %*s", verb) != 2 ) verb = cmd;

        stringp(path = ob->find_command(verb));

        if( wizardp(ob) && wiz_level(me) < wiz_level(ob) )
                return notify_fail(YEL"战甲之魂说：你不能命令他，小心他把你杀档！\n"NOR);
        write(HIW"你命令" + ob->name() + "去" + cmd + "\n"NOR);
        seteuid(export_uid(ob));
        seteuid(getuid());
        res = ob->force_me(cmd);
        if (!res) return notify_fail(YEL"战甲之魂说：找不到这个命令！\n"NOR);
	return 1;
}

int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;
  if (!str) return notify_fail(HIM"Syntax: give <cloak> to <id>\n"NOR);
  if (sscanf (str, "%s to %s", obs, whos)!= 2 || sscanf (str, "%s %s", whos, obs)!= 2 )
     return notify_fail(HIM"Syntax: give <cloak> to <id>\n"NOR);
  me = this_player();
  who = find_player(whos);
  wiz = wizhood (who);
  if (obs != "cloak")
     return notify_fail(HIM"Syntax: give <cloak> to <id>\n"NOR);
  write (HIG"对方的巫师等级 : "+wiz_level(who)+"\n"NOR);
  if (wiz_level(who) > 1)
  if(wiz_level(who)<wiz_level("(wizard)")) {
    write (YEL"战甲之魂说：“他没有驾驭我的法力！”\n"NOR);
    return 1;
  }

  ob = present ("cloak", me);
  if (!ob) write (YEL"战甲之魂说：你没有这样东西。\n"NOR);
  if (!who) write (YEL"战甲之魂说：没有这个人。\n"NOR);
  if (ob && who) {
    ob->move (who);
    message_vision (HIY"$N给$n一件烈炎的终极法宝－「龙鳞战甲」。\n"NOR, me, who);
  }
  return 1;
}

int query_autoload()
{
  if (wizardp(this_player()))
    return 1;
  else return 0;
}
