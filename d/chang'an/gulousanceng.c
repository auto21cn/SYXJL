inherit ROOM;
int flag=0;
void create()
{
        set("short", "鼓楼三层");
        set("long", @LONG
你正站在鼓楼三楼。这里端立着十四根红色显柱、二十四根隐柱交叉
擎立。内挂三只大宫灯、十二只中宫灯、十六只小宫灯。天花板上油漆彩
绘云形图案。南、北面楼檐下悬挂有匾(bian)，南为“文武盛地”，乃清
乾隆皇帝御笔刻书。北为“声闻于天”，咸宁县李允宽书写。每匾重约三
吨，字迹刚劲有力。你可沿回廊凭栏眺望，全城景色尽收眼底。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "down"  : __DIR__"gulouerceng",                       
        ]));
        set("item_desc", ([
            "guan cai" : "一副黑漆金字的大匾。\n",
            
        ]));


        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_dakai", "tiao");                 
}
int do_dakai(string arg)
{
        object me=this_player();
        object ob;
        if(!arg || arg!="bian")
                return notify_fail("你跳个什么啊？\n");
        
        else if ( flag==0 )
                {
                        flag=1;
                        message_vision("你跳了起来，想把匾看得仔细些....哇，里面居然有一块古玉。.\n",me);
                        message_vision("$N四下看了看，赶忙把古玉揣进了兜里.\n",me);
                ob = new ( __DIR__"obj/wenyu" );
                ob->move( this_player() );

                }
             else message_vision("匾的后面空空的，什么都没有。\n",me);            

        return 1;
}

