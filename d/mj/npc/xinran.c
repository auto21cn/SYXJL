// xinran.c ��Ȼ

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

object ob = this_object();
void create()
{
        set_name("��Ȼ",({"xin ran","xin","ran"}));
        set("title","�һ���ʹ");
         set("title",HIR"�һ���ʹ"NOR);
        set("long", 
                "���������̵��һ���ʹ��\n"
                "����������ɷ��,ֻһ�Բ��;ͻ�����ƴ�������һ�.\n");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 24);
        set("int", 16);
        set("con", 16);
        set("dex", 24);
        
        set("max_qi",1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 40);
        set("combat_exp", 200000);
        
        set_skill("sword",100);
        set_skill("dodge",100);
        set_skill("unarmed",100); 
        set_skill("literate",100);
        set_skill("force",100);
        set_skill("shenghuo-shengong",100);
        set_skill("qingyunwu", 100);
        set_skill("liehuo-jian",100);
        set_skill("parry", 100);
        
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        
        create_family("����",35,"������ʹ");
        
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        
}



void init()
{
       object ob;

       ::init();

        ob = this_player();
        if((int)ob->query("score") < -10 && ob->query("family/master_id")=="xin ran")
        {
                    command("chat "+ob->query("name")+"����Ϊ�˲��Ҳ��壬�������������㣿\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","����" + RED + "��ͽ" NOR);   
        }

}


void attempt_apprentice(object ob)
{
       if ((string)ob->query("family/family_name")!="����" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "����������ɣ��������ȥ����");
                return;
        }        

        command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
        command("recruit " + ob->query("id"));
        ob->set("class", "shizhe");
        ob->set("title","�����һ����½���");
}
