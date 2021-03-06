// save.c by rhxlwd 99.02
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;

	seteuid(getuid());

	if( !objectp(link_ob = me->query_temp("link_ob")) )
                  return notify_fail(HIR"【存盘精灵】你不是经由正常连线进入，不能储存。\n"NOR);
/*
        if ( ((int)time() - (int)me->query("save_time")) < 120 )
                 return notify_fail("多存盘对服务器硬盘健康有害，请过一会儿再 save 吧。\n");
*/

	if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
                    write("当你下次连线进来时，会从这里开始。\n");
	}

	if( (int)link_ob->save() && (int)me->save() ) {
            write(HIR"【存盘精灵】 档案储存成功。\n"NOR);
                me->set("save_time", time());
		return 1;
	} else {
                  write(HIR"【存盘精灵】 储存失败。\n"NOR);
		return 0;
	}
}

int help(object me)
{
	write(@HELP
指令格式：save

把你辛苦奋斗的结果存起来。
HELP
	);
	return 1;
}
