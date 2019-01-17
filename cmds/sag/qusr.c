// command: qusr ( query player list & status)
#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string str, string arg)
{
        int i,j=0,n,idle;
        int z;
        object *user_list,user_location;
        object *ob;
        string status1, status2, status3, status4;
        string status5;
        user_list=users();
        n=sizeof(user_list);
        write(sprintf("目前线上共有 %d 名玩家，名单如下：\n",n));

        for(i=0;i<n;i++) {
                if(user_list[i]) {
                        ob = users();
                        j++;
                        user_location = environment(user_list[i]);

//                      if (!user_location) return notify_fail("他在虚无飘藐间。\n");

                        idle=query_idle(user_list[i]);
                        if (in_input(user_list[i])) status1=HIC"(输入文字中)"NOR;
                        else status1="";
                        if ((in_edit(user_list[i]))) status2=HIY"(编辑档案中)"NOR;
                        else status2="";
                        if (idle>180) status3=sprintf(HIR"(发呆了 %d 分钟)"NOR,idle/60);
                        else status3="";
                        if (idle>3600) status4=sprintf(HIB"(发呆了 %d 小时 %d 分钟)"NOR,idle/3600,(idle-3600)/60);
                        else status4="";
                        if (user_list[i]->query("env/invisibility") && wizardp(user_list[i]))
                        status5=HIY"(隐身"+chinese_number(user_list[i]->query("env/invisibility"))+"级中)"NOR;
                        else status5="";
                        if (!user_location) {
                                write(sprintf("%2d %12s %s(%s) 位於 %s(?????????)\n", j,
                                        SECURITY_D->get_status(user_list[i]),
                                        user_list[i]->query("name"),
                                        user_list[i]->query("id"),
//                                      (string)user_location->query("short"),
                                        "他在虚无飘藐间" ));
                                if ((status1!="")||(status2!="")||(status3!="")||(status4!="")||(status5!=""))
                                        write(sprintf("                状态  : %s%s%s%s%s\n",status1,status2,status3,status4,status5));
                                write(sprintf("                从 %s 来到此处。\n",query_ip_name(ob[i])));
                        }
                        else {
                                write(sprintf("%2d %12s %s(%s) 位於 %s(%s)\n",
                                        j,
                                        SECURITY_D->get_status(user_list[i]),
                                        user_list[i]->query("name"),
                                        user_list[i]->query("id"),
                                        (string)user_location->query("short"),
                                        (string)file_name(user_location) ));
                                        if((status1!="")||(status2!="")||(status3!="")||(status4!="")||(status5!=""))
                                                write(sprintf("                状态  : %s%s%s%s%s\n",status1,status2,status3,status4,status5));
                                        write(sprintf("                从 %s 来到此处。\n",query_ip_name(ob[i])));
                        }
                }
        }
        z = j ;
        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : qusr
此指令可让你(你)直接查询目前线上所有的玩家(包括玩家)、位置及状态。
HELP);
        return 1;
}

