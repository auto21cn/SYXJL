// create by five

inherit ROOM;
inherit __DIR__"ground3";

#include <ground.h>

void create ()
{
  set ("short", "赛场");
  set ("long", @LONG

赛场四周是高高的贵宾观礼台，十丈见方的场地上整整齐齐地
铺着一圈彩色玛瑙石，架着香烟袅绕的四个巨大金银铜铁鼎，
场地中间是软松的皮绒织锦毯。左边是兵器架(weapon)，右边
是防具架(armor)，都放着各种武器和护具。比武前选手就从
两个架子上各取所需。

LONG);

  set("objects", ([
        __DIR__"npc/wei"  : 1,
        __DIR__"npc/siguan"  : 2,
      ]));

  set("item_desc", ([
       "weapon" : @LONG

一排绘金檀木架上放着各种各样的标准兵器，比武的
人来这里领取称手的兵器。可从檀木架子上拿(take)
武器,架子上放有：
  大板斧：    axe
  钢刀：      blade
  钢叉：      fork
  长枪：      spear
  禅杖：      staff
  镔铁棍：    club
  长剑：      sword
  飞璜石：    throwing
  皮鞭：      whip
  匕首：      dagger
  铁锤：      hammer

LONG,

      "armor" :@LONG

一排镶银檀木架上放着大大小小的标准盔甲护具，比
武的人来这里领取合适的盔甲护具。从檀木架子
上拿(pick)护具,架子上放有：
  铠甲：      armor
  盾牌：      shield
  靴子：      boots
  指套：      finger
  手套：      hands
  头盔：      head
  围脖：      neck
  披风：      surcoat
  腰带：      waist
  护腕：      wrists

LONG,

      ]));
  set("broadcast",1);
  set("alternative_die",1);
  setup();
}

void init ()
{
  object who = this_player();

  if (wizardp(who))
  {
    init0();
    init1();
    init2();
    init3();
    call_out ("hinting",1,who);
  }
  add_action ("do_hit","fight");
  add_action ("do_hit","kill");
  add_action ("do_hit","hit");
  add_action ("do_quit","quit");
  add_action ("do_take","take");
  add_action ("do_pick","pick");
}
int do_quit()
{ 
  say(" 这里不许退出。\n");
  return 1;
}
int do_pick (string arg)
{
  object who = this_player();
  object ob;

  if (who->query_temp("get/armor") && !wizardp(who))
    return notify_fail ("对不起，请让巫师替您来拿东西。\n");

  if (! arg)
    return notify_fail ("您要拿什么？\n");
  if (arg == "armor")
    ob = new (__DIR__"obj/armor/armor");    
  else if (arg == "shield")
    ob = new (__DIR__"obj/armor/shield");    
  else if (arg == "boots")
    ob = new (__DIR__"obj/armor/boots");    
  else if (arg == "finger")
    ob = new (__DIR__"obj/armor/finger");    
  else if (arg == "hands")
    ob = new (__DIR__"obj/armor/hands");    
  else if (arg == "head")
    ob = new (__DIR__"obj/armor/head");    
  else if (arg == "neck")
    ob = new (__DIR__"obj/armor/neck");    
  else if (arg == "surcoat")
    ob = new (__DIR__"obj/armor/surcoat");    
  else if (arg == "waist")
    ob = new (__DIR__"obj/armor/waist");    
  else if (arg == "wrists")
    ob = new (__DIR__"obj/armor/wrists");    
  else
    return notify_fail ("您要拿什么？\n");
 
  message_vision ("$N从架子上拿起$n。\n",who,ob);
  ob->move(who);
   who->set_temp("get/armor",1);
  return 1;
}
int do_take (string arg)
{
  object who = this_player();
  object ob;

  if (who->query_temp("get/weapon") && !wizardp(who))
    return notify_fail ("对不起，请让巫师替您来拿东西。\n");
  if (! arg)
    return notify_fail ("您要拿什么？\n");
  if (arg == "axe")
    ob = new (__DIR__"obj/weapon/axe");    
  else if (arg == "blade")
    ob = new (__DIR__"obj/weapon/blade");    
  else if (arg == "dagger")
    ob = new (__DIR__"obj/weapon/dagger");    
  else if (arg == "fork")
    ob = new (__DIR__"obj/weapon/fork");    
  else if (arg == "hammer")
    ob = new (__DIR__"obj/weapon/hammer");    
  else if (arg == "spear")
    ob = new (__DIR__"obj/weapon/spear");    
  else if (arg == "staff")
    ob = new (__DIR__"obj/weapon/staff");    
  else if (arg == "stick")
    ob = new (__DIR__"obj/weapon/stick");    
  else if (arg == "sword")
    ob = new (__DIR__"obj/weapon/sword");    
  else if (arg == "throwing")
    ob = new (__DIR__"obj/weapon/throwing");    
  else if (arg == "whip")
    ob = new (__DIR__"obj/weapon/whip");    
  else
    return notify_fail ("您要拿什么？\n");
  message_vision ("$N从架子上拿起$n。\n",who,ob);
  ob->move(who);
  who->set_temp("get/weapon",1);
  return 1;
}

int check_fighters (object who, object ob)
{
  object *inv = all_inventory (environment(who));
  object wei = present ("gong pingzi", environment(who));
  string names = "";
  int i = sizeof (inv);

  if (ob == wei)
    return 0;

  while (i--)
  {
    if (inv[i]==who || inv[i]==ob || inv[i]==wei)
      continue;
    if (inv[i]->is_fighting())
      names += inv[i]->name();
  }
  if (names != "")
  {
    message_vision ("$N对$n说道：这场上"+names+"等正在拚死厮杀，请稍候片刻！\n",wei,who);
    return 0;
  }
  if (! userp(who) || ! userp(ob))
    return 1;
  call_out ("wait_and_announce",1,who,ob);
  return 1;
}

void wait_and_announce (object who, object ob)
{
  mapping match = this_room()->query("match");
  int step;
  string name0, name1, names;

  if (! match)
    return;
  step = match["step"];
  if (step != STEP_FIGHT)
    return;
  if (! who || ! ob)
    return;
  name0 = who->query("name");
  name1 = ob->query("name");
  if (strcmp(name0,name1) > 0)
    names = name0 + name1;
  else
    names = name1 + name0;
  if (match["fighters"] == names)
    return;

  match["fighters"] = names;
announce (name0 + "与" + name1 + "比武大会生死相搏！\n");
}

int do_hit()
{
  say("请用等巫师下令。\n");
  return 1;
}
void hinting (object who)
{
  tell_object (who, "\n");
  tell_object (who, "◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
  tell_object (who, "◇大会分筹备、比赛、结束等阶段，不同阶段有不同命令。◇\n");
  tell_object (who, "◇使用命令时请注意是否有其他巫师也在此设置比赛数据。◇\n");
  tell_object (who, "◇　　　　　　　　　　　　　　　　　　　　　　　　　◇\n");
  tell_object (who, "◇请您随时使用 ? 或 what 来查询您可以使用的命令。 　◇\n");
  tell_object (who, "◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
  tell_object (who, "\n");
}


