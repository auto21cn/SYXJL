// room: /d/xingxiu/cave.c
// Jay 3/18/96

inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);

void create()
{
        set("short", "山洞");
        set("long", @LONG
这个山洞里伸手不见五指，只有出口处透进一丝光线。
LONG
        );
        set("exits", ([
            "out" : __DIR__"tianroad5",
]));
        set_temp("times" , 1);

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_use", "use");
        add_action("do_chu", "chu");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
        if ( random(100) > 50)
{
        message_vision("忽然，不知道从哪里吹来了一阵风！”\n",me);
        message_vision("接着，你手里得火折子给吹熄了！\n",me);
        return ;
}

             write(
             "你点燃了火折，发现石壁的角落里居然长着一株雪中莲。\n"
             );
             return 1;
       }
}

int do_chu(string arg)
{
 object me=this_player();
 object ob;
 if (!arg||arg!="雪中莲")
  return notify_fail("你要干什么？\n");
 if (!present("yaochu",me))
  return notify_fail("没有药锄怎么锄得出雪中莲？\n");
 if (query_temp("times")==0)
  return notify_fail("你仔细一看，却发现这只不过是你得一个幻觉！\n");
 ob=new("/d/honghua/xuelian");
 ob->move(environment(me));
 add_temp("times",-1);
 message_vision("$N小心地把这朵雪中莲从土中刨了出来。\n" , me);
 return 1;
}

