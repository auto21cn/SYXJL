//room1.c
inherit ROOM;
int do_da(string arg);
void create()
{
  set("short","练功室");
  set("long",
      "这里是白驼山弟子的练功室。有几个大大的木桩(mu zhuang)供你修炼杖法。\n"
    );
  set("exits",([
      "out" : __DIR__"liangong",
     ]));
  set("item_desc", ([
       "muren zhuang" : "一个木桩，做成木人的样子固定在地上，供人击打(da)练功。\n",
     ]));     

 setup();

}


void init()
{
        add_action("do_da", "da");
        
}
int do_da(string arg)
{
        object me;
        int costj, costq;
        object weapon;
        me = this_player();
        if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
        if (me->is_fighting()) return notify_fail("你正在战斗中，无法专心练功！\n");
        if ( !living(me)) return notify_fail("你发疯了？\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
         return notify_fail("空手是练不了杖法的。\n");
        if (!arg || arg != "mu zhuang") return notify_fail("你要打什么？打人吗？\n");
        costj = random((int)me->query("con"))+1;
        costq = random((int)me->query("str"))+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
              message_vision("$N马步一松，一不小心脑袋撞在了木桩上！\n",me);
              me->unconcious();
              return 1;
              }
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       
        message_vision("$N站好马步，提起钢杖，开始和木桩对打起来。\n", me);
        if ( (int)me->query_skill("cuff", 1) < 30 && random(10)>6 ){  
              me->improve_skill("staff", (int)(me->query("int") / 5));
              }
        if ( (int)me->query("combat_exp") < 30000) 
        {
             me->add("potential",random(2));
             me->add("combat_exp",random((int)(me->query("int") / 10)));
        }
        return 1;
}

