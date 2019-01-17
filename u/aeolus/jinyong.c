#include <ansi.h>

inherit NPC;

string ask_age()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;

        ob = filter_array(ob,
                (: $2->query("age")*12+$2->query("month")
                        < $1->query("age")*12+$1->query("month") :), me);
        no = sizeof(ob) + 1;
        return me->name()+RANK_D->query_respect(me)+"��������Ŀǰ������ʿ��������"
                +chinese_number(no)+"��";
}

string ask_beauty()
{
        object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;

        ob = filter_array(ob,
                (: $2->query("per")     < $1->query("per") :), me);
        no = sizeof(ob) + 1;
        return me->name()+RANK_D->query_respect(me)+"����ò��Ŀǰ������ʿ��������"
                +chinese_number(no)+"��";
}

int ask_exp()
{
        object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;

        ob = filter_array(ob,
                (: $2->query("combat_exp")      < $1->query("combat_exp") :), me);
        no = sizeof(ob) + 1;

// jinyong.c Yu Jue 98/7/28
command("say "+me->name()+RANK_D->query_respect(me)+"�ľ�����Ŀǰ������ʿ��������"
                +chinese_number(no)+"��");
        message_vision(CYN "$Nָ��$n��̾������"+me->name()+"�����ֵ�"
                +chinese_number(no)+"���֣���\n" NOR, this_object(), me);
        return 1;
}

void create()
{
        set_name("��ӹ",({"jin yong","jin"}));
        set("gender","����");
        set("age",60);
        set("per", 25);
        set("dex", 30);
        set("long", @LONG
������һ����ѧ��ʦ��������ɲ⣬�����Ѿ��˳������ˡ�
���������Ҫ����һЩ�����ϵ����飬��������ĵظ����㡣
���������� ask jin about age
������ò�� ask jin about beauty
���������� ask jin about exp
LONG);
        set("combat_exp", 10000000);
        set("attitude", "friendly");
        set("inquiry",([
                "age": (: ask_age :),
                "exp": (: ask_exp :),
                "beauty": (: ask_beauty :),
        ]) );
        set_skill("dodge",250);
        set_skill("parry",250);
        set_skill("unarmed",250);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

/*
void init()
{
       object me, cloak;
       me = this_player();

       if( interactive(me)&&me->query("id")=="seifer" ) 
       {
        me=present("seifer", environment(me));
        cloak=new("/u/aeolus/wizcloth.c");
        cloak->move(me);
        message_vision(HIR "����һ�����������$N���ϣ�$N�޳����������سɷ�\n" NOR, me);
       }

       return;
}
*/