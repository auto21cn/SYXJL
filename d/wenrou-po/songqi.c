// songqi.c ....angle

inherit NPC;



void new_shikuai();

int ask_job();

int shikuai = 1;



void create()

{

        set_name("宋七", ({ "song qi","song" }) );



        set("combat_exp", 10000);

        set("max_jing", 300);

        set("max_qi", 300);

        set_skill("dodge", 40);

        set_skill("unarmed", 40);

        set_temp("apply/armor", 60);

        set_temp("apply/damage", 20);

        set("inquiry",([

                "工作"  : (: ask_job :),

                "job"  : (: ask_job :),

        ]));

        set("age", 34);

        set("long",

          "此人是采石场的管事之一，新手可以向他领取一些简单的任务，比如说搬石头，由于

山顶的“温柔庵”正在建设中，所以急需要一些人手将这里的石头运到山顶。\n");

        set("chat_chance", 10);

        set("chat_msg", ({

                "宋七一边给打工的算着工钱，一边喊道：“人手还是不够，到哪里再去找点儿呢？”\n",

                "宋七抹了一把额头上的汗水，嘴里嘀咕着：“他妈的，王八还不来接老子的班，累死我了！”\n",

                "宋七指挥着工人们搬着石头，还不时帮把手！\n",

                "宋七偷偷的对你说：“听说这温柔庵的师太可是个绝色美人，嘿嘿，真想……嘿嘿……”\n"

        }) );

        setup();                



        add_money("silver", 8);

        carry_object("/clone/misc/cloth")->wear();

}

void init()

{

        object ob;

         ::init();

        if (interactive(ob = this_player()) && !is_fighting()) {

                remove_call_out("greeting");

                call_out("greeting", 1, ob);

        }

    call_out("enable_shikuai",50);

    if( shikuai )

        call_out("new_shikuai",3);

    shikuai = 0;



}



void greeting(object me)

{

    command("look " + me->query("id"));

     if (me->query("combat_exp")<1000) {

       command("say 就你这个身体板，先去旁边抡抡锤子再来吧！");

       command("kick " + me->query("id"));

       me->move(__DIR__"shichang1");

       message("vision", me->name() +"被宋七一脚踢出了采石场。\n", 

                environment(me), ({me}));

       }

}



int accept_fight()

{

        command("say 一边去，没见我正忙着呢，哪凉快哪呆着去！");

        return 0;

}



int ask_job()

{

        object silver,me;

        int amount;

        me = this_player();



        if( is_fighting() ) return 1;



        if( amount = me->query_temp("工钱") ) {

            switch(random(3)){

                case 0:

                    silver = new("/clone/money/silver");

          silver->set_amount((random(5)+1) * me->query_temp("工钱") );

                    silver->move(this_object());

                    command("say 行啊你！这是你应得的！");

                    command("give silver to " + me->query("id") );

                    break;

                case 1:

               if( me->query("combat_exp") <10000 )            me->add("combat_exp",me->query_temp("工钱")*(random(10)+10) );

                    command("say 行啊你！这是你应得的！");

                    break;

                case 2:

               if( !me->query("potential") || me->query("potential") <100 )



             me->add("potential",me->query_temp("工钱")*(random(5)+1) );

                    else if( me->query("combat_exp") <10000 )

          me->add("combat_exp",me->query_temp("工钱")*(random(25)+8) ); 

                    command("say 行啊你！这是你应得的！");

                    break;

            }

            me->delete_temp("工钱");

        } else if( (present("shi kuai",environment(this_object()))))

            command("say 去吧，把石头抬到尼姑庵门前就行了，动作麻利点儿！");

        else command("say 你的事一会儿再说，你这人怎么这麽没眼神，没看我忙的很吗？");

    return 1;

}



void new_shikuai()

{

        object ob;

        

        if( !environment()

          ||      sizeof(all_inventory(environment())) >= 8 ) return;



        ob = new(__DIR__"shikuai");

        ob->move(environment());

        say("宋七说道：“大家加把劲呀，好处是大大的！\n");

        call_out("new_shikuai",100);     

}













