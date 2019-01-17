// create by five
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "五彩门");
  set ("long", @LONG

一座由雕花香檀木建立起来的大门高高立地而起，门柱上镶着
无数五彩透明的翡翠宝石。门里面是大会会场，瑞气笼罩气象
万千。这里在没有举行比武大会时，凡人不得擅自入内。

LONG);

  set("exits", ([
        "south"   : __DIR__"north",
        "east"   : "/d/city/wumiao",
      ]));

  setup();
     "/clone/board/biwu_b"->foo();
}
void init()
{ object me;
  me=this_player();
  if (wizardp(me))
   { add_action("do_open","break");
     add_action("do_close","feng");
   }
}
int do_open(string arg)
{
  object me;
  string name;
  me=this_player();
  name=(string)me->query("name");

  if (!wizardp(me)) return notify_fail("对不起结界需要巫师的神力才能开启.\n");
  
  if(!arg ||arg!="here")
    return notify_fail("你要打破那里的结界?\n");

  environment(me)->set("break",1);
  message_vision(HIW "$N大喝一声，“轰”结界被打破了!\n"NOR,me);
  return 1;
}

int do_close(string arg)
{
  object me;
  string name;
  me=this_player();
  name=(string)me->query("name");

  if (!wizardp(me)) return notify_fail("对不起结界需要巫师的神力才能设定.\n");
  
  if(!arg ||arg!="here")
    return notify_fail("你要在那里设结界?\n");
  if(!environment(me)->query("break"))
    return notify_fail("这里已经设了结界了!\n");

  environment(me)->delete("break");
  message_vision( HIW "$N口中念念有词一道白光过后结界形成了!\n"NOR,me);
  return 1;
}
int valid_leave (object who, string dir)
{
  if (wizardp(who))
    return ::valid_leave(who, dir);

  if ( dir == "south" && !environment(who)->query("break"))
    return notify_fail (HIY "你发现面前一道光壁挡住去路。\n" NOR);

  return ::valid_leave(who, dir);
}


