inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string arg)
{
        object ob;
        mapping family;
        family = me->query("family");
        if((me->query("guild_name"))!=0)
        return notify_fail("对不起，你已经加入了"+me->query("guild_name")+"的帮会。\n");
        if( !arg ) return notify_fail("你要加入谁的帮会？\n");
        if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"你提的人目前不在这世界吧？\n");
            return 1;
         }
      if(!present(arg,environment(me)))
        {
         tell_object(me,ob->query("name")+"现在不在这里。\n");
         return 1;
        }
      if( ob->query_temp("yaoqing") )
         {
          if( ob->query_temp("yaoqing") == me->query("id") )
            {
             if( ! stringp(ob->query("guild_leader")) )
               return notify_fail("对方没有参加帮派。\n");
             if( ! ob->query("guild_name"))
               return notify_fail("对方没有开帮立派。\n");
             if( ob->query("guild_name") == "              " )
               return notify_fail("对方没有加入帮派。\n");
            tell_object(me,"你决定加入"+ob->query("name")+"的帮会。\n");
            say(me->query("name")+"决定加入"+ob->query("name")+"的帮会。\n");
            me->set("guild_name",ob->query("guild_name"));
            if( me->query("family/family_name"))
            me->set("title", HIG"【" + ob->query("guild_name") + "－－帮众】"NOR + sprintf("%s第%s代弟子", family["family_name"],
                        chinese_number(family["generation"])));
                else
                me->set("title", HIY"【" +ob->query("guild_name")+ "－－帮众】"NOR + "普通百姓");
            return 1;
            }
         }
        tell_object(me,"对方没有邀请你加入帮会。\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：jiaru <对方id>
这个指令让你加入对方的帮会.
HELP
    );
    return 1;
}

