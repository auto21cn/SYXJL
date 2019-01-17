// call.c
// writed by shadow
// writed add ansi by Wind

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string objname, func, param, euid, wiz_status;
        object obj;
        mixed *args, result;
        int i;

        if( arg ) {
                if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
                        if( (string)SECURITY_D->get_status(me) != "(admin)" )
                                return notify_fail("�㲻���趨�Լ��� euid��\n");
                        seteuid(euid);
                }
                else
                        seteuid( geteuid(this_player(1)) );

                if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
                        return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");
        } else
                return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");

        obj = present(objname, environment(me));
        if(!obj) obj = present(objname, me);
        if(!obj) obj = find_player(objname);
        if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
        if(objname=="me") obj = me;
        if(!obj) return notify_fail("�Ҳ���ָ���������\n");

        wiz_status = SECURITY_D->get_status(me);
//      if( (wiz_status != "(admin)" && wiz_status != "(sage)" && wiz_status != "(arch)") && obj != me )
//              return notify_fail("ֻ�� (arch) ���ϵ���ʦ����ʹ���������ܡ�\n");

        param = replace_string(param, "$BLK$", BLK);
        param = replace_string(param, "$RED$", RED);
        param = replace_string(param, "$GRN$", GRN);
        param = replace_string(param, "$YEL$", YEL);
        param = replace_string(param, "$BLU$", BLU);
        param = replace_string(param, "$MAG$", MAG);
        param = replace_string(param, "$CYN$", CYN);
        param = replace_string(param, "$WHT$", WHT);
        param = replace_string(param, "$HIR$", HIR);
        param = replace_string(param, "$HIG$", HIG);
        param = replace_string(param, "$HIY$", HIY);
        param = replace_string(param, "$HIB$", HIB);
        param = replace_string(param, "$HIM$", HIM);
        param = replace_string(param, "$HIC$", HIC);
        param = replace_string(param, "$HIW$", HIW);
        param = replace_string(param, "$BLINK$", BLINK);
        param = replace_string(param, "$NOR$", NOR);

        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++) {
                // This removes preceeding blanks and trailing blanks.
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
                //args[i] = restore_variable(args[i]);
        }

        if( sizeof(args) ) {
                if ( (args[0] == "env/setverok" || args[0] == "env/setpath") )
                        return notify_fail("���ڰ�ȫ�ԵĿ��ǣ���������ѱ����á�\n");
        }

        if( userp(obj) ){
                log_file("static/CALL_PLAYER",
                        sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
                                me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
                                ctime(time()) ) );
        } else if( !master()->valid_write( base_name(obj), me, "set" ) )
                return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");

        args = ({ func }) + args;

        result = call_other(obj, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);
        printf("%O->%s(%s) = %O\n", obj, func, 
                implode(args[1..sizeof(args)-1], ", "), result);
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : call <���>-><����>(<����>, ...... )
 
����<���>���<����>���������<����>.
 
HELP
    );
    return 1;
}

