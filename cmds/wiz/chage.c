//change.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object ob,string arg)
{
	message("vision", BLINK HIY"鹿鼎记已作出部分更新，请大家help change查询具体情况。\n"NOR, users());
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: chage
 
通知玩家help change查询最新更新。
 
HELP
	);
	return 1;
}
