// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if( !arg ) return notify_fail("��Ҫ���Լ�ȡʲô�ºţ�\n");
    arg = explode(arg+"\n", "\n")[0];
        if( strlen(arg) > 30 )
                return notify_fail("��Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n");
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

        me->set("nickname", arg + NOR);
    if (arg == "cancel") {
      me->delete("nickname");
      write("���Ĵºű�ɾ���ˡ�\n");
    }
        write("Ok.\n");
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : nick <���>|cancel
 
���ָ���������Ϊ�Լ�ȡһ�����������Ż�ͷ�Σ������ϣ���ڴº���
ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ���

HELP
"$NOR$ - �ָ�������ɫ\n"
"$RED$ - "RED"��ɫ"NOR"         $HIR$ - "HIR"����ɫ\n"NOR
"$GRN$ - "GRN"��ɫ"NOR"         $HIG$ - "HIG"����ɫ\n"NOR
"$YEL$ - "YEL"����ɫ"NOR"       $HIY$ - "HIY"��ɫ\n"NOR
"$BLU$ - "BLU"����ɫ"NOR"       $HIB$ - "HIB"��ɫ\n"NOR
"$MAG$ - "MAG"ǳ��ɫ"NOR"       $HIM$ - "HIM"�ۺ�ɫ\n"NOR
"$CYN$ - "CYN"����ɫ"NOR"       $HIC$ - "HIC"����ɫ\n"NOR
"$WHT$ - "WHT"ǳ��ɫ"NOR"       $HIW$ - "HIW"��ɫ\n"NOR
@HELP 

����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��
HELP
);
        return 1;
}