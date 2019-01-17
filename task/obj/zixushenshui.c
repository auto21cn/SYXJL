#include <ansi.h>
inherit ITEM;
int do_xh (string arg);
void create()
{
  set_name(HIM"紫虚神水"NOR, ({"zixushenshui", "shenshui", "water"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "瓶");
  
  set("long", "一个古怪的瓶子装着一些看来很普通的水，不过据谣传，
这就是能显化（xh）武器的紫虚神水。\n");
    }
    setup();
}
void init()
{
   add_action("do_xh", "xh");
}
int do_xh (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;

  if ((! arg ||
     ! (ob = present(arg, who)))&&
   (! arg || ! (ob = present(arg, where))))
  {
    return notify_fail("你要将神水做什么用？\n");
  }
  if (ob == who)
  {
    message_vision ("$N拿起神水往自己脑门上一道，“轰”的一声变成一阵清烟走了。\n",who);
    message_vision ("顿时$N只觉得一股精气入髓七窍生烟，乾坤倒置！\n",who);
    who->unconcious();
  }
  else if ((string)ob->query("name") != HIC"真武剑"NOR) {

    message_vision ("$N拿起紫虚神水往$n上一倒，$n“轰”的一声笼罩在清烟之中。\n",who,ob);
  }
  else
  {
   message_vision("$N拿起紫虚神水往$n上一倒，$n“轰”的一声笼罩在清烟之中。\n
只见$n上渐渐显现出了文字，似乎是一套剑谱。\n",who,ob);
   ob->set("OK_to_STUDY", 1);
  }
  destruct (me);
  return 1;
}

