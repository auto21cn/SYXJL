// ding.c 丁春秋
// by QingP

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        seteuid(getuid());
        set_name("丁春秋", ({ "ding chunqiu", "ding" }));
        set("nickname", HIR "星宿老怪" NOR);
        set("long", 
                "他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。\n"
                "他脸色红润，满头白发，颏下三尺银髯，童颜鹤发，当真便如图画中的神仙人物一般。\n"
                "他看起来形貌清奇，仙风道骨，气度雍容，风采俨然。\n");
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 30);
        set("con", 29);
        set("dex", 29);
        
        set("max_qi", 4700);
        set("max_jing", 3700);
        set("neili", 4100);
        set("max_neili", 4100);
        set("jiali", 100);
        set("combat_exp", 1700000);
        set("score", 700000);

          set_skill("force", 200);
          set_skill("dodge", 200);
          set_skill("strike", 200);
          set_skill("claw", 200);
          set_skill("poison",200);
          set_skill("throwing",150);
          set_skill("staff", 170);
          set_skill("parry", 190);
          set_skill("literate", 130);
        set_skill("beiming-zhenqi", 200);
        set_skill("zhaixinggong", 170);
        set_skill("xingchen-zhang", 200);
        set_skill("wugong-zhao", 170);
        set_skill("huagong-dafa", 190);
        set_skill("tianshan-zhang", 170);

        map_skill("force", "beiming-zhenqi");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "xingchen-zhang");
        map_skill("claw", "wugong-zhao");
        map_skill("poison", "huagong-dafa");
        map_skill("parry", "xingchen-zhang");
        map_skill("staff", "tianshan-zhang");
        
        prepare_skill("strike", "xingchen-zhang");
        prepare_skill("claw", "wugong-zhao");

        create_family("星宿派", 1, "开山祖师");
        set("class", "taoist");

/*      set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "strike.du" :),
                (: perform_action, "strike.zhen" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.hua" :),
        }) );*/

        set("inquiry", 
        ([
                "星宿毒经" : (: ask_me :),
        ]));

        set("book_count", 1);
        set("no_get",1);

        setup();

        carry_object("/d/xingxiu/obj/xiaoyaosan");
        carry_object("/d/xingxiu/obj/bilinxing");
        carry_object("/d/xingxiu/obj/bilinxing");
        carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "星宿派") {
                command("say 你这旁门左道之徒，竟敢偷觎本派宝典！");
                for(int i=0; i<4; i++) {
                        if( objectp( ob = present("dizi " + (i+1), environment(this_object())) ) ){
                                message_vision("星宿派弟子群起对$N发动攻击！\n", this_player());
                                ob->kill_ob(this_player());
                        }
                        else command("throw xiaoyao san at " + (string)this_player()->query("id"));
                }
        return "哼！";
        }

        if (query("book_count") < 1)
                return "你来晚了，本派宝典已不在这儿了。";
        add("book_count", -1);
        ob = new("/d/xingxiu/obj/dujing_2");
        ob->move(this_player());
        return "这本『星宿毒经〖下册〗』你可要好好保管，莫落入旁门左道手中。";
}

void init()
{
        object ob;

        ::init();

        ob = this_player();
        if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="ding chunqiu") {
                command("chat "+ob->query("name")+"!装什么正道人士，给我滚出星宿派。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","星宿派" + RED + "弃徒" NOR);
        }

        add_action("do_flatter", "flatter");
        add_action("do_kill", "kill");
        add_action("do_hit", "hit");
}

void do_kill(string arg)
{
        object me = this_player();
        object obj;

        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "ding chunqiu" || arg == "ding") {
                command("grin");
                command("throw xiaoyao san at "+me->query("id"));
        }
}

void do_hit(string arg)
{
        object me = this_player();
        object obj;

        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "ding chunqiu" || arg == "ding") {
                remove_call_out("checking");
                call_out("checking", 1, obj, me);
        }
}

void attempt_apprentice(object me)
{
        if ((int)me->query("betrayer")) {
                command("say 我越看你越象是来卧底的。");
                return;
        }

        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                return;
        }
        else {
                command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
                message_vision("星宿老怪微闭双眼，手捻长须，一付等人拍马(flatter)的样子。\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        string name,new_name; 
        object me = this_player();      
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说老仙什么？\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0
        ||  strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今无比") >=0 )) {
                command("smile");
                command("say 天下武学，源出星宿，你可要好好修习呀！\n");
                command("recruit " + this_player()->query("id"));
                name = me->query("name");
                new_name = name[0..3] + "子";
                me->set("name", new_name);
                command("say 从现在开始，" + new_name + ",你就是我派第二代弟子了!");    
                command("recruit " + me->query("id"));        
        }
        else command("say 你如此不把老仙放在眼里，老仙怎会收你？");

        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

/*int prevent_learn(object me, string skill)
{
        object ob = this_object();

        if(skill == "huagong-dafa")
        {
                message_vision("$N神色间似乎对$n不是十分信任，也许是想起从前有人背叛他的事情 ...。\n", ob, me );
                message_vision("$N两眼一瞪，喝道：不行！\n", ob, me );
                tell_object(me, "化功大法乃丁春秋的不传之技，找他学，你想死呀？！\n");
                return 1;
        }
        return 0;
}*/
        
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

        if( me->is_fighting() ) {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 ) {
                        message_vision(HIG"\n星宿派门人忽然取出锣鼓铙郄、唢呐喇嘛，或敲或吹，好不热闹！\n" NOR, me);
                        switch( random(2) ) {
                                case 0:
                                        say(GRN "\n弟子说道：星宿派威震武林，我恩师当世无敌！\n" NOR);
                                        say(GRN "\n弟子说道：星宿老仙弘施大法，降伏尔等幺魔小丑！\n" NOR);
                                        say(GRN "\n弟子说道：星宿老仙举重若轻，神功盖世，今日叫你大开眼界！\n" NOR);
                                break;
                                case 1:
                                        say(HIY "\n弟子对你说道：尔等灯烛之火，居然也敢和日月争光，还不快快束手就擒！\n" NOR);
                                        say(HIY "\n第子对你说道：你螳臂挡车，自不量力，可笑啊可笑！\n" NOR);
                                        say(HIY "\n众弟子颂声大作：星宿老仙，歌德天地，威震寰宇，古今无比！\n" NOR);
                                break;
                                case 2:
                                        say(HIB "\n弟子说道：师父你老人家谈笑之间，便将一干幺魔小丑置于死地，\n"
                                        "如此催枯拉朽般大获全胜，徒儿不但见所未见，真是闻所未闻。\n" NOR);
                                        say(HIB "\n弟子说道：这是天下从所未有的丰功伟绩，若不是师父老人家露了这一手，\n"
                                        "他还不知世上有这等功夫。\n" NOR);
                                        say(HIB "\n弟子说道：古往今来，无人能及星宿老仙！有谁胆敢螳臂当车，不过自取灭亡而已。\n" NOR);
                                break;
                        }
                        message_vision(HIY "\n登时高帽与马屁齐飞，法螺共锣鼓同响。这些无耻歌颂之声，于星宿老怪的功力，\n竟然也大有推波助澜之功！\n" NOR, me);

                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                else if ( (int)ob->query("qi")*100 / his_max_qi < 50 ) {
                        say(GRN "\n 丁春秋说道：想跟老仙斗，小子，你还早着呢！\n"
                                        + "还不快快拜如星宿门下，待老仙教你几着上乘神功！\n");
                        return 1;
                }

                if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }

        return 1;  
}

