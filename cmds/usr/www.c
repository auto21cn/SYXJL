// wizlist.c
//Write by Byt@J.H.Y.J 11/2/99
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string *list,listed="(null)";
        object *ob;
        ob = filter_array(objects(), (: userp :));
        write("【"HIW + MUD_NAME + NOR"】" + "目前的巫师有：\n");
        write("────────────────────────────\n");
        list = sort_array(SECURITY_D->query_wizlist(), 1);
        write(HIW"〖   admin  〗："NOR);
		 for(int i=0; i<sizeof(list); i++)
        {
                if(wiz_level(list[i])==7)       
                {
                        for(int z=0; z<sizeof(ob); z++) 
                        {
                                if( ob[z]->query("id")==list[i] && listed!=ob[z]->query("id")&&ob[z]->query("env/invisibility")==0)
                                {       
                                        write("("+HIG+ob[z]->query("id")+NOR") " );
                                        listed=list[i];
                                }
                        }
                        if(listed!=list[i])
                                write("("CYN+list[i]+NOR") " );
                }
        }       
        write("\n"HIR"〖   sage   〗："NOR);
		 for(int i=0; i<sizeof(list); i++)
        {
                if(wiz_level(list[i])==6)       
                {
                        for(int z=0; z<sizeof(ob); z++) 
                        {
                                if( ob[z]->query("id")==list[i] && listed!=ob[z]->query("id")&&ob[z]->query("env/invisibility")==0)
                                {       
                                        write("("+HIG+ob[z]->query("id")+NOR") " );
                                        listed=list[i];
                                }
                        }
                        if(listed!=list[i])
                                write("("CYN+list[i]+NOR") " );
                }
        }       
        write("\n"HIM"〖   arch   〗："NOR);
        for(int i=0; i<sizeof(list); i++)
        {
                if(wiz_level(list[i])==5)       
                {
                        for(int z=0; z<sizeof(ob); z++) 
                        {
                                if( ob[z]->query("id")==list[i] && listed!=ob[z]->query("id")&&ob[z]->query("env/invisibility")==0)
                                {       
                                        write("("+HIG+ob[z]->query("id")+NOR") " );
                                        listed=list[i];
                                }
                        }
                        if(listed!=list[i])
                                write("("CYN+list[i]+NOR") " );
                }
        }       
        write("\n"HIY"〖   angel  〗："NOR);
        for(int j=0; j<sizeof(list); j++)
        {
                if(wiz_level(list[j])==4)
                {
                        for(int x=0; x<sizeof(ob); x++)
                        {
                                if( ob[x]->query("id")==list[j] && listed!=ob[x]->query("id"))
                                {
                                        write("("HIG+ob[x]->query("id")+NOR") " );
                                        listed=list[j];                         
                                }
                        }
                        if(listed!=list[j])                     
                                write("("CYN+list[j]+NOR") " );
                }
        }
        write("\n"HIG"〖  wizard  〗："NOR);
        for(int k=0; k<sizeof(list); k++)
        {
                if(wiz_level(list[k])==3)
                {
                        for(int c=0; c<sizeof(ob); c++)
                        {
                                if( ob[c]->query("id")==list[k] && listed!=ob[c]->query("id"))
                                {
                                        write("("HIG+ob[c]->query("id")+NOR") " );
                                        listed=list[k];                                                                 
                                }
                        }
                        if(listed!=list[k])                     
                                write("("CYN+list[k]+NOR") " );
                }
        }
        write("\n"HIC"〖apprentice〗："NOR);
        for(int l=0; l<sizeof(list); l++)
        {
                if(wiz_level(list[l])==2)
                {
                        for(int v=0; v<sizeof(ob); v++)
                        {
                                if( ob[v]->query("id")==list[l] && listed!=ob[v]->query("id"))
                                {
                                        write("("HIG+ob[v]->query("id")+NOR") " );
                                        listed=list[l];                                 
                                }
                        }
                        if(listed!=list[l])                     
                                write("("CYN+list[l]+NOR") " );
                }
        }               
        write("\n────────────────────────────\n");
        write("合共有： "HIR + sizeof(list) + NOR" 位。");
        write("其中亮绿色ID表示在线巫师。\n");  
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单。
HELP
     );
     return 1;
}

