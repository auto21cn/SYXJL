#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "ben can","can"}) );
        set("long",
                "����һλ�뷢���׵���ɮ������һϮ��ߺڲ����ġ��������ݸߣ�\n"
                "̫��Ѩ�߸߹����ƺ����������书��\n"
            );
        set("gender", "����" );
        set("class", "bonze");
        set("age", 65);
        set("shen_type", 1);
        set("str", 32);
        set("int", 32);
        set("con", 32);
        set("dex", 35);

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("score", 300000);

        set_skill("force", 200);
        set_skill("kurong-changong", 200);
        set_skill("dodge", 180);
        set_skill("tiannan-bufa", 180);
        set_skill("parry", 180);
        set_skill("finger", 180);
        set_skill("sword", 180);
        set_skill("duanjia-jian", 180);
        set_skill("yiyang-zhi", 180);
        set_skill("buddhism", 200);
        set_skill("literate", 150);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "duanjia-shenfa");
        map_skill("parry", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        map_skill("sword", "duanjia-jian");

        prepare_skill("finger","yiyang-zhi");
        
        create_family("������", 6, "����");
        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.tun" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
            })      );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("score") < 0 && ob->query("family/master_id")=="ben can")
        {
                command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","������" + RED + "��ͽ" NOR);
        }
}

void attempt_apprentice(object ob)
{
        string name,new_name; 
        if ((string)ob->query("class") != "bonze") {
                command("say ���Ĳ����׼ҵ��ӣ�ʩ����ذɡ�");
                
                return 0;
        }
        if ((int)ob->query_skill("kurong-changong", 1) < 180) {
                command("say �������������ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ���ڿ��������϶��µ㹦��");
                return ;
        } 
        if ((int)ob->query_skill("buddhism", 1) < 180) {
                command("say ����֮�ˣ�����Ϊ�ȣ����������˷��ŵմ�������ѧ�÷�ҵľ���ɡ�");
                command("say �������ķ����棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }        if ((int)ob->query("shen") <70000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        } 
        if ((int)ob->query("score") <400) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }

        command("chat ����,����...����ɵö���ù�");
        command("party ��ɮ����һͽ��,����Ժ�ú��д衣");
        command("recruit " + ob->query("id"));
        name = ob->query("name");     
        new_name = "��" + name[2..3];
        ob->set("name", new_name);
        ob->set("family/generation", 7);
        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����¹��ֱ����� !");
                return ;
}