inherit ROOM;
#include <ansi.h>

void create()
{
   set("short", HIC"天牢"NOR);
   set("long", @LONG

这里是关押违犯天条的神仙用的，你到了这里，
活下去的希望就很小了。四周黑黑的，你什么
也看不清，隐约听见远处传来阵阵哭喊声。
LONG
   );
   
   set("valid_startroom", 1);

   setup();
   
}

void init()
{   
   if (!wizardp(this_player())) {
          this_player()->set("startroom","/d/wizard/punish");
     this_player()->save();
     add_action("block_cmd","",1);      
   }
   call_out("hehe", 2, this_player());
}

int block_cmd()
{
        string verb = query_verb();
   
        if (verb=="say") return 0; 
   if (verb=="help") return 0;
   if (verb=="look") return 0;
   return 1;
}

void hehe()
{
        tell_room(environment(this_player()), "\n"+
     "你觉得有无数双恐怖的眼睛正在盯着你看！\n"+
     "你看了看四周墙上挂的刑具，不禁打了个冷战！\n"+
     "你隐隐约约听到远处传来一声凄惨的叫声！\n"+
     "一个声音喊道：“你站起来！轮到你了！”你吓了一跳，还好不是喊你。\n"+
     "你隐隐约约听到有人说话，可又听不大清楚！\n"+
     "你隐隐约约听到远处有个人在喊：“我有罪，我招供，别打我了！”\n");
        return;
}
