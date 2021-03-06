// challenge.c

#include <ansi.h>
#include <command.h>

inherit NPC;

void competition_with(object ob)
{
        NPC_D->set_from_me(this_object(), ob);
        ::competition_with(ob);
}

int accept_fight(object ob)
{
        if (query_temp("competition") == ob)
                return 1;

        if (ob->is_fightint())
                return notify_fail("人家正在比武呢，你这么出手不太妥当吧！\n");

        if (query("finished"))
                return notify_fail("人家刚比完武，你上去打算干什么？\n");

        return ACCEPT_CMD->main(ob);
}

int accept_hit(object ob)
{
        return accept_fight(ob);
}

int accept_kill(object ob)
{
        return notify_fail("我看这种丢中原武林脸的事情你还是别作了。\n");
}

void lost()
{
        object ob;
        object story;
        int expi, poti, weiwangi, scorei;

        if (! objectp(ob = query_temp("competition")))
                return;

        if (! objectp(story = STORY_D->query_running_story()))
                return;

        story->stop_story();
        command("chat 岂有此理！怎么... 怎么可能会这样？");
/*
        CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
                "听说" + ob->name() + "打败了" + name() + "，捍卫了中原武林的尊严。");
*/
        scorei = random(query("combat_exp") / 500) + 500;
        weiwangi = random(query("combat_exp") / 800) + 200;
        expi = random(NPC_D->check_level(this_object()) * 1000) + 10;
        poti = random(200) + 50;
       ob->add("combat_exp", scorei);
       ob->add("potential", weiwangi);
        tell_object(ob, sprintf(HIG "你获得了%s点经验、%s点潜能。\n" NOR,
                     chinese_number(scorei),
                     chinese_number(weiwangi)));
        set("finished", 1);
        call_out("destruct", 0, this_object());
        ::lost();
}

void win()
{
        object ob;
        object story;

        if (! objectp(ob = query_temp("competition")))
                return;

        if (! objectp(story = STORY_D->query_running_story()))
                return;

        story->stop_story();
        command("chat* haha");
        command("chat 中原武林，不堪一击！");
/*
        CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
                "听说" + ob->name() + "输给了" + name() + "，丢尽了中原武林的脸面。");
*/
        set("finished", 1);
        call_out("destruct", 0, this_object());
        ::win();
}
