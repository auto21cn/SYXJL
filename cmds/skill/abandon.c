// abandon.c

inherit F_CLEAN_UP;
mapping valid_types = ([
        "unarmed":      "拳脚",
        "sword":        "剑法",
        "blade":        "刀法",
        "stick":        "棒法",
        "staff":        "杖法",
        "club" :        "棍法",
        "throwing":     "暗器",
        "force":        "内功",
        "parry":        "招架",
        "dodge":        "轻功",
        "magic":        "法术",
        "whip":         "鞭法",
        "poison":       "毒功",
//      shaolin skills
        "finger":   "指法",
        "hand":     "手法",
        "cuff":     "拳法",
        "claw":     "爪法",
        "strike":   "掌法",
]);
int main(object me, string arg)
{
        mapping smap;
        string *skill;
        int level,old,i;
        if( !arg || arg=="" ) 
                return notify_fail("你要放弃哪一项技能？\n");
        if( sscanf(arg,"%s %d",arg,level)==2)
        {
                if((old=me->query_skill(arg,1))>level)
                {
                        me->set_skill(arg,old-level);
                        write("你放弃了"+level+"级"+to_chinese(arg)+"。\n");
                        return 1;
                }
        }
        //必须去除map_skill，不然战斗的时候还是要出错！
        //但是是否要去除skill_pre就不清楚了以后如果skill还出问题，可看看这个问题
        smap = me->query_skill_map();
        if( !(!mapp(smap) || sizeof(smap)==0 ))
        {
                skill = keys(valid_types);
                for (i=0; i<sizeof(skill); i++) 
                {
                        if( undefinedp(valid_types[skill[i]]) ) 
                        {
                                map_delete(smap, skill[i]);
                                continue;
                        }
                        if( !me->query_skill(skill[i]) ) continue;
                        if(smap[skill[i]]==arg)
                        {
                                write("去除激发："+skill[i]+" => "+smap[skill[i]]+"。\n");
                                me->map_skill(skill[i]);
                        }
                }
        }
        if( !me->delete_skill(arg) )
                return notify_fail("你并没有学过这项技能。\n");
        write("你决定放弃继续学习" + to_chinese(arg) + "。\n");
        return 1;
}

int help()
{
        write(@TEXT
指令格式：abandon|fangqi <技能名称>

放弃一项你所学过的技能，可以将这项技能从你的人物资料中删除，可以选择
需要放弃的级别数。

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由于每个
人有着不同的天赋，所修习的武功也不会相同。如果样样都学，到头来只会样
样不精。
TEXT
        );
        return 1;
}
