// alias.c
// From ES2
// Modified for XKX by Xiang (12/15/95)
#include <ansi.h>
#define MAX_REPEAT 30
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10

mapping alias;

nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;

string process_input(string str)
{
        string *args, cmd, argstr;
        int i, j;
        object ob = this_player();
        if( ob->query_temp("disable_inputs") )   return "什麽？\n";

        if( str==last_input && str != "" && str != "read new") {
                repeat_cnt++;
                if( repeat_cnt > MAX_REPEAT ) {
                        tell_object( this_object(),
                                "\n本系统发现你滥用指令！\n\n"
                                HIG"\n\n你一次性输入的相同指令太多了。\n\n"NOR
                                "\n\n\n突然天空中乌云密布，一道白色的闪电象利剑般劈向你！\n\n");
                        command("quit");
                }
        } else {
                repeat_cnt = 0;
                last_input = str;
        }

        if(this_object()->query_temp("disable_inputs"))
                return "什麽？\n";

//      str = CONVERT_D->input(str,this_object());

        if( this_object()->query_encoding() )
                str = LANGUAGE_D->toGB(str);

        if( str[0]=='!' ) {
                if( pointerp(history) && sizeof(history) ) {
                        if( sscanf(str, "!%d", i) )
                                str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
                        else
                                str = history[last_cmd];
                } else
                        return "";
        } else {
                if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
                last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
                history[last_cmd] = str;
        }

        if( mapp(alias) ) {

                if( !undefinedp(alias[str]) )
                        return replace_string( alias[str], "$*", "" );

                if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
                        cmd = replace_string( alias[cmd], "$*", argstr );
                        args = explode(argstr, " ");
                        if( (j = sizeof(args)) )
                                for(i=0; i<j; i++)
                                        cmd = replace_string( cmd, "$" + (i+1), args[i] );
                        return cmd;
                }
        }

        return (string)ALIAS_D->process_global_alias(str);
}

int set_alias(string verb, string replace)
{
        if( !replace ) {
                if( mapp(alias) ) map_delete(alias, verb);
                return 1;
        } else {
                if( !mapp(alias) ) alias = ([ verb:replace ]);
                else if( sizeof(alias) > MAX_ALIASES )
                        return notify_fail("您设定的 alias 太多了，请先删掉一些不常用的。\n");
                else alias[verb] = replace;
                return 1;
        }
}

mapping query_all_alias()
{
        return alias;
}


