#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        set_name("任盈盈", ({ "ren yingying","ren" }));
        set("long", "她长得极美，尤其是那对眼睛，媚得直可以勾人魂魄。\n");
       set("nickname", "令狐夫人");             
       set("title", "日月神教护教仙姑");
        set("gender", "女性");
        set("age", 20);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 40000);
        set("shen_type", 1);
       create_family("日月神教",3,"弟子");
       set("chat_chance",1);
        set("chat_msg",({
         "不知令狐冲他，怎恙了,是否又和那小贱人在一起......\n",
        "你若能把这封信捎给他，可太谢谢你了.............\n",
        "也不知蓝凤凰见没见到他，可真急死我了.......\n",
           }) );
       set("inquiry",([
        "令狐冲" : (: ask_me :),
           ]));
       set_temp("letter",1);
        
setup();
        carry_object("/d/city/npc/obj/necklace")->wear();
}
string ask_me()
{
 object me=this_player();
 object obn;

 message_vision("去年上华山一去就再无音信,他不会忘记我吧......\n"
         , me );
 if(query_temp("letter")==0)
 {  message_vision("任盈盈又说道：这位"+ RANK_D->query_respect(me)+"，我已经派蓝凤凰去寻找了,\n也不知道怎么样了。\n",me);
   return "";
 }
   message_vision("任盈盈又说道：这位"+ RANK_D->query_respect(me)+"，我这里有信, 你要是找到『阿冲』，\n就把信交给他，他会明白的。\n" , me);
   obn=new(__DIR__"obj/letter");
   obn->move(me);
   set_temp("letter",0);
   
   return ("这封信烦你交给令狐冲。\n");
}

void init()
{
        object me, ob;

        me = this_object();

      if(present("xo", this_player())     )
        {
         command("say 哇！既然如此！这本秘籍你拿去看吧！但是.....\n");
         ob = new(__DIR__"obj/du");
         ob->move(this_player());
         this_player()->set_temp("marks/笑傲江湖曲", 1);
         destruct(present("xo", this_player()));
         return;
        }

        return;
}
        
int accept_object(object me, object ob)
{
        object book;
        
        command("smile");
        command("say 我正想买一条新项链，谢谢" + RANK_D->query_respect(me) + " ！");

        if( ob->query("money_id") && ob->value() >= 30000 && me->query("class") != "bonze")
        {
                book=new(__DIR__"obj/sword_book");
                book->move(me);
                message_vision("盈盈给$N一本剑谱。\n", me);

                command("say 我没什么报答你的,这本剑谱就送给你吧。"); 
                return 1;
        }

        return 1;
}
