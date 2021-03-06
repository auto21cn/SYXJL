// baohu.c by ljty at May, 3 1998



#include <ansi.h>



inherit F_CLEAN_UP;





int main(object me, string arg)

{

    object ob;



    if (me->is_busy())

        return notify_fail("你现在正忙着呢。\n");



    if( !arg )

        return notify_fail("指令格式：baohu [none]|<对象>|[cancel]\n");



    if( arg=="none" ) 

      {

        if(!me->query_temp("baohuman"))

          return notify_fail("你现在并没有保护谁。\n");

        message_vision("$N现在不想保护$n了\n",me,me->query_temp("baohuman"));

        me->query_temp("baohuman")->set_temp("baohu",0);

        me->set_leader(0);

        return 1;

      }

    

    if( arg=="cancel" )

      {

        if(!me->query_temp("baohu"))

          return notify_fail("现在并没有人保护你。\n");

        me->query_temp("baohu")->set_temp("baohuman",0);

        me->query_temp("baohu")->set_leader(0);

        message_vision("$N现在不想要$n保护了。\n",me,me->query_temp("baohu"));

         me->set_temp("baohu",0);

       me->set_temp("baohuman",0);
        return 1;

      }

    if( !objectp(ob = present(arg, environment(me)))

       ||        !ob->is_character() )

      return notify_fail("你想保护谁？\n");



    ob = present(arg, environment(me));



    if(ob == me)

      return notify_fail("自己保护自己，真是个好主意．．．\n");

    

    if(ob == me->query_temp("baohu"))

      return notify_fail("你正在保护着" + me->query_leader()->name() +"。\n");



    if(ob->query_temp("baohu"))

      return notify_fail("已经有人进行保护了，你就不用费心了。\n");



    

    message_vision("$N决定开始保护$n了。\n", me, ob);

    me->set_leader(ob);

    me->set_temp("baohuman",ob->query("id"));
    ob->set_temp("baohu",me);

    return 1;

}



int help(object me)

{

        write(@HELP

指令格式：baohu <对象>|[none]|[cancel]



这个指令使你开始保护一个人，如果有人想杀他，

你将会出手把招接过来，但如果有几个人都来杀

他，你将无能为力。



HELP

    );

    return 1;

}

