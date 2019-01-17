// skills.c by rhxlwd 99.02

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "��ѧէ��" NOR,
        BLU "��֪����" NOR,
        HIB "��ͨƤë" NOR,
        HIB "��������" NOR,
        YEL "��������" NOR,
        YEL "��������" NOR,
        HIY "ƽ������" NOR,
        HIY "������ͨ" NOR,
        HIG "�������" NOR,
        HIG "��������" NOR,
        HIC "�������" NOR,
        HIC "�������" NOR,
        CYN "����Ѿ�" NOR,
        CYN "����似" NOR,
        MAG "�����ɵ�" NOR,
        MAG "�����뻯" NOR,
        HIW "��Ȼ��ͨ" NOR,
        HIW "��Ⱥ����" NOR,
        RED "�Ƿ��켫" NOR,
        HIM "һ����ʦ" NOR,
        HIM "��������" NOR,
        HIR "��ǰ����" NOR,
        HIR "���ž���" NOR,
        WHT "��������" NOR,
        WHT "������ʥ" NOR,
        HIW "��豹���" NOR,
        HIW "��ɲ�" NOR
});

string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,
        BLU "��������" NOR,
        HIB "��֪����" NOR,
        HIB "ƽ������" NOR,
        YEL "˾�ռ���" NOR,
        YEL "�����ž�" NOR,
        HIY "��֪һ��" NOR,
        HIY "é���ٿ�" NOR,
        CYN "��ʶ֮��" NOR,
        CYN "��������" NOR,
        MAG "��������" NOR,
        MAG "�ᳵ��·" NOR,
        HIW "��������" NOR,
        HIW "������ͨ" NOR,
        HIM "����ǳ��" NOR,
        HIM "����С��" NOR,
        HIM "�������" NOR,
        RED "��Ȼ���" NOR,
        RED "����ʶ��" NOR,
        HIR "������ͨ" NOR,
        HIR "׿����Ⱥ" NOR,
        HIR "��������" NOR,
        WHT "��Ȼ��ͨ" NOR,
        WHT "����ͨ��" NOR,
        WHT "������" NOR,
        WHT "��Ⱥ����" NOR,
        WHT "������˫" NOR,
        WHT "��������" NOR,
        HIW "������" NOR,
        HIW "������ʥ" NOR,
        HIW "��ɲ�" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped, str;
        int i,j;
        str = "";

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
        }

        if (    ob!=me && !wizardp(me) // modify by ken fix last bug can check all unlimited, at 99-5-12
                && !ob->is_apprentice_of(me)
                && !me->is_apprentice_of(ob)
                && !(ob->query("id") == me->query("couple/couple_id")) )
                return notify_fail("ֻ����ʦ����ʦͽ��ϵ���з��޹�ϵ�����ܲ쿴���˵ļ��ܡ�\n");


        skl = ob->query_skills();
        j = (int)sizeof(skl);
        if(!sizeof(skl)) {
                write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        } 
 write(HIW"                        ��"HIG+ob->name()+HIW"��ѧ�似����\n");
        write( HIC"��"HIY"��������������������������������������������������������������"HIC"��\n"NOR);
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        for(i=0; i<sizeof(skl); i++) {
                printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
                        (lrn[sname[i]] >= (skl[sname[i]]) * (skl[sname[i]]) * (skl[sname[i]]) / 10) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": HIR"��"NOR),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
write( HIC"��"HIY"������������������������������������������ "HIG"SYXJL"HIY" ����������������"HIC"��\n"NOR);
            write(HIG"                                 "+ob->name(1)+HIW"��������"HIR+chinese_number(i)+HIW"���书/���ܡ�\n"NOR);
        write("\n");
        return 1;
}

string skill_level(string type, int level)
{
        int grade;

        grade = level / 10;

        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ : skills|cha [<ĳ��>]

���ָ���������(��)��ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ���������ż���� skills ���Բ�֪�Է���
����״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}

