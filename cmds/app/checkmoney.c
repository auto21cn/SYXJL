// checkmoney.c
// writed by shadow

#include <net/dns.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        object *list,g_ob,s_ob,c_ob,t_ob, * inv;
        string str;
        int gc,sc,cc,tc,j;

        if (!wizardp(me)) return "什麽？";
        str = "◎ " + MUD_NAME + " 当前玩家资料金钱统计\n\n";
        str += "帐号             姓名           金子  银子  铜板  银票  存款(金子)  物品数量\n";
        str += "————————————————————————————————————————\n";
        list = users();
        j=sizeof(list);
        while( j-- )
        {
                reset_eval_cost();
                if( !environment(list[j]) || !me->visible(list[j]) ) continue;
                inv = all_inventory(list[j]);  
                if (g_ob = present("gold_money", list[j]))
                        gc = g_ob->query_amount();
                else
                        gc = 0;
                if (s_ob = present("silver_money", list[j]))
                        sc = s_ob->query_amount();
                else
                        sc = 0;
                if (c_ob = present("coin_money", list[j]))
                        cc = c_ob->query_amount();
                else
                        cc = 0;    
                if (t_ob = present("thousand-cash_money", list[j]))
                        tc = t_ob->query_amount();
                else
                        tc = 0;    
                str = sprintf("%s%-15s %-14s%5d %5d %5d %5d  %5d   %5d\n",
                        str,
                        list[j]->query("id"),list[j]->name(1), gc,sc,cc,tc,list[j]->query("balance")/10000, sizeof(inv)
                        );
        }

        str += "————————————————————————————————————————\n";
        str = sprintf("%s共有 %d 位使用者连线中，系统负担：%s\n", str, sizeof(list),
                query_load_average() + "\n");

        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) return -1;

        if( wizardp(ob2) && !wizardp(ob1) ) return 1;

        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob2) 
                        - (int)SECURITY_D->get_wiz_level(ob1);

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help(object me)
{
write(@HELP
指令格式 : checkmoney

这个指令可以列出所有在线上的玩家的金钱以及身上物品的数量。

相关指令： finger, who
HELP
    );
    return 1;
}
