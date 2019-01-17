// 修改 by think

#include <ansi.h>
#include <room.h>


inherit ROOM;
string look_mupai();
void create ()
{
        set ("short", "比武场大门");
        set ("long", @LONG
这是「随缘洗剑录」的比武场的大门，一座高高的木制牌坊，上书『比武场』
三个镏金大字。这里经常举办各种类型的比武大会。所有的人都有机会参加。
旁边立着一个不高的木牌(mupai)，上面不知写着什么？
LONG);
        set("no_fight",1);
        set("no_clean_up",1);
        set("item_desc", ([
                "mupai" : (:look_mupai:),
        ]));

        set("exits", ([
                "north"   : __DIR__"zoulang",
                "south"   : "/d/city/chatroom",
        ]));
        set("objects", ([
                "/u/think/biwu/npc/gongping" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object ob, where;

        if (!where=find_object(__DIR__"gate"))
                where=load_object(__DIR__"gate");
        ob=present("gongping zi", where);
        if ( !wizardp(me) && dir=="north" )
            if( ob->query("fangshi")!="个人赛" && !ob->query("start/start"))
       return notify_fail("现在没有任何比武，你不能进去。\n");
        return ::valid_leave(me, dir);
}

string look_mupai()
{
        return "\n\n"HIG"请用list命令查看比武申请情况。\n\n请用family命令申请门派比武。\n\n
请用canjia命令参加比武。\n\n"+NOR"";

}

