// edit.c

// writed by shadow



#include "/doc/help.h"



inherit F_CLEAN_UP;


inherit F_DBASE;
void create()
{
        seteuid(getuid());
        set("name", "编辑指令");
        set("id", "edit");
         set("channel_id","在线编辑");
}
int main(object me, string file)

{

	if( !file ) return notify_fail("指令格式：edit <档名>\n");



	if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");



	seteuid(geteuid(me));

	ed(resolve_path(me->query("cwd"), file));
    CHANNEL_D->do_channel(this_object(),"sys",me->query("name")+"("+me->query("id")+")"+"编写了"+resolve_path(me->query("cwd"),file)+"。");

	log_file("static/editfile", sprintf("%s%s edit %s (%s)\n",

		me->query("name"),

		"(" + me->query("id") + ")" ,

		resolve_path(me->query("cwd"), file),

		ctime(time())

		) );

	return 1;

}



int help(object me)

{

  write(@HELP

指令格式 : edit <档名>, edit here



利用此一指令可直接在线上编辑档案。

HELP

    );

    return 1;

}

