//book_hong.c
#include <ansi.h>
inherit ITEM;
int do_tear(string arg);

void init()
{
        add_action("do_tear", "tear");
}

void create()
{
        set_name(HIR"『四十二章经』"NOR, ({"book_hong"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\n一本正红旗的经书,封皮(binding)很精致。\n");
                set("unit", "本");
                set("material", "paper");
        }
        setup();
}

int do_tear(string arg)
{
        int i,j;
        object me;
        string dir;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if(arg=="book_hong")
        {
        message_vision("$N一下把经书撕得粉碎。\n", this_player());
        destruct(this_object());
        return 1;
        }

        if( sscanf(arg, "book_hong %s", dir)==1 ) {
        if( dir=="binding" ) {
                if(this_object()->query("hasgot"))
                message_vision("$N将封皮撕开,发现羊皮已经被取走了。\n", this_player());
                
                else if(((int)this_player()->query("kar")) < random(30))
                 {
                this_player()->set_temp("marks/no_book_hong",1);
                message_vision("$N和宝藏无缘。\n", this_player());
                 }
                
                else if(this_player()->query_temp("marks/no_book_hong",1))
                message_vision("万事只看一个缘字。\n", this_player());
                
                else
                {
                i=random(300);  
                j=random(200);
                me->add("potential",j);
                me->add("combat_exp",i);
                message_vision("$N将封皮撕开，几块羊皮掉了下来。\n", this_player());
                message_vision("$N先将羊皮上的地图记了下来，然后把它们和书一起烧掉了。\n", this_player());
                message("shout", HIR "【江湖传闻】" + HIM + "某人: 据说"  +this_player()->query("name") + "于" + NATURE_D->game_time() + "得到正红旗
          "HIR"『四十二章经』"HIM"内的几块破羊皮。共得到"HIW"" + chinese_number(i) + ""HIM"点经验，"HIW"" + chinese_number(j) + ""HIM"点潜能。\n\n" NOR,users()); 

//              me->set("huanggong\haspi8", 1);
//              this_object()->set("hasgot",1);
                destruct(this_object());  
                }
        }
        else
        {
        message_vision("$N一下把经书撕得粉碎。\n", this_player());
        destruct(this_object());
        }
        return 1;
        }       
}

