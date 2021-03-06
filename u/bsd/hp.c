// hp cmds (Mon  09-04-95)

#include <ansi.h>

inherit F_CLEAN_UP;

string *force_status_msg = ({
    	HIR"纯阳"NOR,
    	RED"偏阳"NOR,
    	HIW"阴阳兼修"NOR, 
        HIC"偏阴"NOR,
    	MAG"纯阴"NOR, 
    	MAG"纯阴"NOR    	
    });
string status_color(int current, int max);
int potential_lv(int exp);

int main(object me, string arg)
{
        object ob,weapon;
        mapping my;
        string line,skill_type,force_status;
	int i;
        seteuid(getuid(me));

        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看谁的状态？\n");
                if( !ob->is_character() || ob->is_corpse())
                        return notify_fail("连" + ob->query("name") + "的状态也要查看？？你真幽默。\n");
        } else
                return notify_fail("只有巫师能察看别人的状态。\n");

        my = ob->query_entire_dbase();

    if ( objectp(weapon = ob->query_temp("weapon")) )
    	skill_type = weapon->query("skill_type");
    else
    	skill_type = "unarmed";

    if ( my["yin"] || my["yang"] )
    {
        i = my["yin"] * 5 / ( my["yin"] + my["yang"] );    
        force_status = force_status_msg[i];
    }
    else 
        force_status = "未知";
        write(HIW" 〖"HIG+ob->name()+HIW"基本状态列表〗\n");
        
        printf( HIC"≡"NOR"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"HIC"≡\n\n"NOR);
        printf(CYN" 【 精神 】： "NOR"%s%4d / %4d %s(%3d%%)" NOR CYN"    【 精力 】：%s%4d / %4d (+%d)\n" NOR,
                status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),   my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["jingli"], my["max_jingli"]),   my["jingli"], my["max_jingli"],
                my["jiajing"] );
        printf(CYN" 【 气息 】： "NOR"%s%4d / %4d %s(%3d%%)" NOR CYN"    【 内力 】：%s%4d / %4d (+%d)\n" NOR,
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"],
                status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],
                my["jiali"] );
        printf(WHT" 【 食物 】："NOR" %s%4d / %4d      " NOR WHT"     【 潜能 】：%s%4d / %4d\n" NOR,
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),
        HIG,
        (int)ob->query("potential") - (int)ob->query("learned_points"), potential_lv(my["combat_exp"]) );
        printf(WHT" 【 饮水 】："NOR" %s%4d / %4d      " NOR WHT"     【 经验 】：  %s%d\n" NOR,
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),
        HIM,
        my["combat_exp"] );
        write(sprintf(HIR" 【 斗志 】："NOR" %s%4d / %4d" NOR,
                HIG,my["douzhi"], my["eff_douzhi"]));        
   line = sprintf(HIR"           【 属性 】："HIG" %s\n"NOR,force_status ); 
   write(line);       
printf( HIC"\n≡"NOR"━━━━━━━━━━━━━━━━━━━━━━━━━"HIG"SYXJL"NOR"━━━━━"HIC"≡\n\n"NOR);
        return 1;
}

string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500;
        return grade;
}

int help(object me)
{
        write(@HELP
指令格式 : hp
           hp <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。

see also : score
HELP
    );
    return 1;
}
