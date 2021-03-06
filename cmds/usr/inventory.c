// inventory.c
// by Find.
// Refernced by kittt@ Mudder2000.yeah.net


#include <ansi.h>

inherit F_CLEAN_UP;

string inventory_desc(object ob,object me);

int main(object me, string arg)
{
	object *inv, ob,*muti;
	int n;
	string output;

	mixed groups;

	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}

	if( !ob ) ob = me;

	inv = all_inventory(ob);
	if( !sizeof(inv) ) {
		write((ob==me)? "目前你身上没有任何东西。\n"
			: ob->name() + "身上没有携带任何东西。\n");
		return 1;
	}

	output = sprintf("%s身上带著下列这些东西(负重 %d%%)：\n",
		(ob==me)? "你": ob->name(),
		(int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance());
// 前面这些就不需要再说了吧。

	muti = filter_array(inv,(: !$1->is_character()&&!$1->query("equipped")&&!$1->query_amount() :));  
// muti里面不包括character，装备的和combine的物体。

	if(sizeof(muti))
	{
		inv -= muti;     // 从inv中把muti这个array有的除去啦，不然重复喽！
		groups = unique_array(muti,(: sprintf("%s%s",base_name($1),$1->name()) :));
	// 分组一下吧，相同name和base_name的东东分别组成一个array。 
	// 这里似乎再加上id 会更好，相同名字不同ID的东东也会有喔。
	// groups = unique_array(muti,(: sprintf("%s%s%s",base_name($1),$1->name(),$1->query("id")) :));
	// 更完善了吧 呵呵！
	}

	n = sizeof(inv);
	for(int i=0;i<n;i++)

	{

		if(inv[i]->is_character())

			output += sprintf("  %s\n",inv[i]->short());
		else if(inv[i]->query("equipped") || inv[i]->query_amount())
			output += inventory_desc(inv[i],ob);
	}
	// 先输出inv中的物体，再输出groups，次序无所谓。
	if(sizeof(groups))


	{
		foreach(object *group in groups)  // 每组都执行一下
		{			if( (n=sizeof(group)) == 1)  				output += sprintf("  %s\n",group[0]->short());  // 只有一个物体就不用数量了啦
			else   // 多个物品就多点嘛
				output += sprintf("  %s%s%s\n",chinese_number(n), // 物品数量
					group[0]->query("unit"), // 单位
					group[0]->query("base_cname")?  // base_cname没见过，反正是和name有关的
					sprintf("%s(%s)",group[0]->query("base_cname"),
					capitalize(group[0]->query("id"))):
					group[0]->short());  // 没有base_cname就用short()啦
		} 
	}

	write(output);
	return 1;
}

// 装备物品的MSG
string inventory_desc(object ob,object me)
{
	return sprintf("%s%s\n",
		ob->query("equipped")?
			((ob == me->query_temp("secondary_weapon"))? // 左右手判断
			HIC "○" NOR:
			HIC "□" NOR):
			"  ",
		ob->short()
	);

}

int help (object me)
{

        write(@HELP
指令格式: inventory
 
可列出你目前身上所携带的所有物品。

"□" 标记说明此物品为你已经装备
     的兵器或者已穿戴的护甲。
"○" 标记说明此兵器装备于你的左手。

注 : 此指令可以 " i " 代替。
 
HELP
);

        return 1;
}
