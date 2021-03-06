// qlist.c
// make by Luky

inherit F_CLEAN_UP;
varargs string get_all_quest(object me, string arg);
int del_quest(object me, int num);

int main(object me,string arg)
{
        string owner;
        string str;
        int lvl, num;

        me = this_player();
        if( !arg ) {
                return notify_fail("指令格式：qlist all | <任务名称> | set <任务文件名>\n");
                }

        if ( sscanf(arg, "set %s.%d", owner, lvl) == 2 ) {
                me->set_temp("add_quest/owner", owner);
                me->set_temp("add_quest/lvl",lvl);
                write( "现在您可以开始查询"+arg[4..strlen(arg)]+"的任务\n" );
                return 1;
                }

        if ( arg =="all" && me->query_temp("add_quest")) {
                str = get_all_quest(me);
                me->start_more(str);
                return 1;
                }

        if ( (sscanf(arg, "del %d", num) == 1) && me->query_temp("add_quest")) {
                del_quest(me, num);
                write("删除完成。\n");
                return 1;
                }

        if ( me->query_temp("add_quest")) {
                write( "查询任务名含有 " + arg+ " 的任务\n" );
                str = get_all_quest(me, arg);
                me->start_more(str);
                return 1;
                }

        return notify_fail("指令格式：qlist all | <任务名称> | set <任务文件名>\n");
}

varargs string get_all_quest(object me, string arg)
{
        object qlist;
        mapping *lists;
        int i;
        string str;

        qlist = new (QUEST_OB);
        if ( !qlist )
                return 0;
        qlist->set("quest_owner", me->query_temp("add_quest/owner"));
        qlist->set("quest_lvl", me->query_temp("add_quest/lvl"));
        qlist->restore();

        lists = qlist->query_all_quest();
        i = sizeof(lists);
        str = "该任务表共有 " + qlist->query("total_quest") + " 条任务。\n";
        str += "   任务名       类型 需要时间 奖励exp 奖励pot 涉及npc  物品描述         物品文件名\n";
        str += "   ────────────────────────────────────────\n";
        if ( !arg )
                while(i--){
                        str += sprintf("%-2d %-12s  %2s  %-8d %-8d%-8d%-8s %s %s\n   更新时间:%s\n",
                                       i+1, lists[i]["name"], lists[i]["quest_type"],
                                       lists[i]["quest_time"], lists[i]["exp"],
                                       lists[i]["pot"], lists[i]["quest_target"],
                                       lists[i]["quest_desc"], lists[i]["quest_object"],
                                       chinese_time(6,lists[i]["time"]) );
                        str += "   ────────────────────────────────────────\n";
                        }
        else while(i--){
                if ( strsrch(lists[i]["name"], arg) >=0 ) {
                        str += sprintf("%-2d %-12s  %2s  %-8d %-8d%-8d%-8s %s %s\n   更新时间:%s\n",
                                       i+1, lists[i]["name"], lists[i]["quest_type"],
                                       lists[i]["quest_time"], lists[i]["exp"],
                                       lists[i]["pot"], lists[i]["quest_target"],
                                       lists[i]["quest_desc"], lists[i]["quest_object"],
                                       chinese_time(6,lists[i]["time"]) );
                        str += "   ────────────────────────────────────────\n";
                        }
                }
        destruct(qlist);
        return str;
}

int del_quest(object me, int num)
{
        object qlist;
        mapping *lists;

        qlist = new (QUEST_OB);
        if ( !qlist )
                return 0;
        qlist->set("quest_owner", me->query_temp("add_quest/owner"));
        qlist->set("quest_lvl", me->query_temp("add_quest/lvl"));
        qlist->restore();

        lists = qlist->query_all_quest();
        lists -= ({ lists[num-1] });
        qlist->set("list", lists);
        qlist->add("total_quest", -1);
        qlist->save();
        destruct(qlist);
        return 1;
}