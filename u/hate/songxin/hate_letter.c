#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"信件"NOR, ({ "letter","xin","secret letter" }));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long",
                        "这是一封特快邮递，信封的很严实，封口盖着红漆印戳。\n");
                set("no_drop", 1);
                set("no_get", 1);
                set("no_give", 1);
                set("material", "paper");
         }
}
void init()
{        
        call_out("dest",random(100)+900);
        add_action("do_send", "songxin");
        add_action("do_send", "gei");
        add_action("do_drop", "diuxin"); 
        add_action("do_drop", "drop");        add_action("do_look", "kan");
        add_action("do_look", "chakan");
}
int do_look(string arg)
{
        object me;

        me = this_player();
        if(!arg) return 0;
        if( (arg=="letter"||arg=="xin")&&me->query_temp("hate_songxin")) {
                write(                      "\n这是一封由驿站发出的信件，上面写着"HIR"「"+me->query_temp("songxin_target_name")+"」 亲启。\n"NOR);                             write(HIW"你为驿站做了"+me->query("hate_job")+"次工作。\n"NOR);   
     write(HIY"你已经为驿站连续做了"+me->query("job_tp")+"次工作。加油！\n"NOR);                                                           
        }else{
        if( (arg=="letter"||arg=="xin")&&!me->query_temp("hate_songxin")) 
 write("这是一封特快邮递，信封的很严实，封口盖着红漆印戳。\n");
         }
                return 1;

}

int do_send(string arg)
{
        int exp,pot,sco;
//        object ob;
        object me,target;
        string t_name,t_id;
        me=this_player();
        if(!arg) return notify_fail("你要送给谁？\n");
        if(!objectp(target = present(arg, environment(me)))) return notify_fail("看清楚点，你要送信的人不在这里！\n");
        t_name = target->query("name");
        t_id = target->query("id");

        if(!target) return notify_fail("看清楚点，你要送信的人不在这里！\n");
        if(target->query("victim_user")) return notify_fail("嘿嘿，想作弊？！\n");
        if(me->query_temp("hate_songxin_late"))
                return notify_fail("你任务已经失败了，重新再领一个吧。\n");
        if (!present("secret letter", this_player()) )
           return notify_fail("你身上没有携带信件。\n"); 
 if (!me->query_temp("hate_songxin"))
            return notify_fail(t_name+"道：这是驿站交给你,要你送的？你是不是从别人那里抢来的？");
 if(me->query_temp("songxin_target_name") != t_name) 
            return notify_fail(t_name+"道：这封信不是给我的，你是不是送错了？");
message_vision("$N交给了$n一封信。\n",me, target);
            message_vision(HIC "$N接过信看了看，点了点头说道：这位"+RANK_D->query_respect(me)+"辛苦你了。\n"NOR, target, me);
            exp=10+random(50);
            pot=10+random(20);     
            sco=5+random(5);               me->add("potential",pot);
            me->add("combat_exp",exp);
            me->add("score",sco);
            me->add("hate_job",1);
            me->add("job_tp",1);
            if( me->query("job_tp") >= 100) 
               { 
               write(HIY"\n在你兢兢业业的为驿站工作下，博得了驿站老板的赏识\n"NOR);
               write(HIR"\n你被驿站老板奖励了 2000 点经验\n"NOR);
               write(HIR"\n你被驿站老板奖励了 1000 点潜能\n"NOR);
               write(HIR"\n你被驿站老板奖励了 500 点评价\n"NOR);

            me->add("combat_exp",2000);
            me->add("potential",1000); 
            me->delete("job_tp");            me->add("score",500);
            me->start_busy(2 + random(4));
            destruct(this_object());
                 return 1; 
                 } 
           
            tell_object(me,HIW"好！任务完成,你被奖励了：\n" + 
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                       chinese_number(sco) + "点评价\n"
                       NOR);
            me->delete_temp("hate_songxin");
            me->delete_temp("songxin_target_name"); 
            me->delete_temp("songxin_where");    
            me->set_temp("songxin_ok",1);
            destruct(this_object());
            return 1;
}
int do_drop(string arg)
{
        object me,target;

        me = this_player();

        if( !arg ) return 0;

        if( arg=="letter") 
        {
                tell_object(me,"你尝试着想放弃驿站给你的任务。\n");
{
message_vision(HIR"$N看着手里的急件，只得叹了口气，唉。。谁叫我找不人呢？\n"NOR, me, target);
message_vision(HIG"$N将本是紧握手中的急件丢弃了。\n"NOR,me, target);
            me->add("score",-(random(40)+5));
            me->add("hate_job",-1);
            me->delete_temp("hate_songxin");
            me->delete("job_tp");
            me->delete_temp("songxin_target_name"); 
            me->delete_temp("songxin_where");     
            me->set_temp("songxin_ok",1); 
            destruct(this_object());
}
            return 1;
    }
}
void dest()
{
       object me;
       me = this_player();
       write("书信忽然掉落在路上不见了。\n", me);  
       destruct(this_object());
}
