// tmdafa.c ��ħ��

inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yin";
}

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("tmdafa", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ�����㣬����ѧ��ħ�󷨡�\n");
        if (i > 10 && (int)me->query("shen") > t * 100)
                return notify_fail("ѧ��ħ�󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
        if ( me->query_skill("hunyuan-yiqi",1) 
        || me->query_skill("huntian-qigong",1) 
        || me->query_skill("taiji-shengong",1) )
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ħ�󷨣���\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��ħ��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"tmdafa/" + func;
}