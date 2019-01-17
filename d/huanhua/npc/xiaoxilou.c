// xiaoxilou.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int ask_me();
int potential_lv(int exp);

void create()
{
        set_name("����¥", ({ "xiao xilou", "xiao" }) );

        set("gender", "����");
        set("age", 60);
        set("long",
                "����¥��佻����ɵ����ţ����Ǹ������Ѯ�����ˣ�����Ӳ�ʵúܡ�\n");
                set("attitude", "peaceful");

        set("str", 50);
        set("cor", 30);
        set("int", 24);
        set("dex", 30);
        set("per",25);

        set_max_encumbrance(100000000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 150);
          set("max_jing", 1000);
          set("jing", 1000);

        set("combat_exp", 3000000);
        set("score", 200000);
        set("shen",15000);
        set("chat_chance_combat", 80);
        set("inquiry", ([
                "����" : (: ask_me :), 
                "��æ" : (: ask_me :),
        ]));
        
        set_skill("cuff", 200);
        set_skill("strike",120);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("literate",200);
        set_skill("unarmed",200);
        set_skill("huanhua-jian",200);
        set_skill("tiexian-quan",200);
        set_skill("guiyuan-dafa",200);
        set_skill("feihua-wuping",200);

        map_skill("force","guiyuan-dafa");
        map_skill("unarmed","tiexian-quan");
        map_skill("sword","huanhua-jian");
        map_skill("dodge","feihua-wuping");
        map_skill("parry","huanhua-jian");     
        create_family("佻�����", 1, "������"); 

        set("no_get",1);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/ccloth")->wear();
}

void init()
{
       object ob;

       ::init();

       if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
                ob = this_player();
                if((int)ob->query("score") < 0 &&ob->query("family/master_id")=="xiao xilou") {
                        command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                        command("expell "+ ob->query("id"));
                        this_player()->set("title","佻�����" + RED + "��ͽ" NOR);   
                }
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("����¥̾�˿���:���Ӳ������ߣ�����ͦ����ġ�\n");
}

int ask_me()
{
        object me,obj;
        mapping fam;
        me=this_player();
        obj=this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "佻�����") {
                say("�㲢�Ǳ��ɵ��ӣ���֪�˻��Ӻ�̸��");
                return 1;
        }

        command("sigh");
        command("say ��λ"+RANK_D->query_respect(me)+",���˳����Ѿ��ܳ�ʱ���ˡ�");
        command("say ���ܲ��ܰ��Ҵ���һ��������Ϣ��");
        me->set_temp("find_ren",1);
        return 1;
}

int accept_object(object who, object ob)
{
        object obj;
        int bonus;
        obj=this_object();
        if(! who->query_temp("find_ren") ) return 0;
        if ( ob->query("id") != "black sword" || userp(ob) )
                return 0;
        if(ob->query("gived"))
        {
                message_vision("����¥��$NЦ�����ף��ⲻ����ո��ҵ��Ǹ�����ô���ܵ�������ȥ�ˣ���\n",who);
                remove_call_out("destroy");
                call_out("destroy", 0, ob);             
                return 0;
        }
        tell_object(who,GRN"����¥�������Եر�ʾ��л����õ���50��Ǳ�ܺ�200�㾭�顣\n"NOR);
        who->add("combat_exp",200);
//      who->start_busy(2);
        bonus = (int)who->query("potential");
        bonus = bonus - (int)who->query("learned_points");
        bonus = bonus + 50;
        if ( bonus > potential_lv((int)who->query("combat_exp")) )
                bonus = potential_lv((int)who->query("combat_exp"));
        bonus += (int)who->query("learned_points");
        who->set("potential", bonus );
        who->delete_temp("find_ren");
        ob->set("gived",1);
        remove_call_out("destroy");
        call_out("destroy", 0, ob);

        return 1;
}

void destroy(object ob)
{
        destruct(ob);
}
void attempt_apprentice(object ob)
{
        if((int)ob->query("combat_exp")<300000) {
                message_vision("����¥��$NЦ������ľ���̫����,�һ��������㣡\n",ob);
                return ;
        }
        if ((int)ob->query("score") < 500 ) {
                command("say ��Ա��ŵĹ��׻�����,����Ŭ��ѽ!");
                return;
        }
        message_vision("����¥����$N��ͷ��΢΢���˵�ͷ��\n",ob);
        ob->set("class", "swordsman");
        ob->set("title","佻����ɶ�������");   
        command("recruit " + ob->query("id"));
        return;
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500 ;
        return grade;
}

void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "xiao xilou" || arg == "xiao")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}

       
int accept_fight(object ob)
{
        object me  = this_object();
                
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

        if ( me->is_fighting()) return 0;

        if ( !present(ob, environment()) ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        
        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;

        if ( !present(ob, environment()) ) return 1; 

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if( me->is_fighting() ) 
        {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 )
                {
                   
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                       if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }

        return 1;  
}
