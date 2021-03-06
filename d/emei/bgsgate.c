inherit ROOM;
#include <ansi.h>;

string look_gate();

void create()
{
        set("short", "报国寺大门");
        set("long", @LONG
这里是一座峨眉山下一座雄伟的寺院，为峨嵋之出入门户，山门(gate)上有一
块大匾。寺宇依山势，逐级升高，四重大殿结构自然，雄浑大方，掩映在苍楠翠柏
之中。寺内有花圃亭榭，玲珑精致，秀丽多姿。山门内外，香客不绝，颂佛之声直
传到山门外。寺院西面有一座山包，名唤“凤凰包”，东面是上山的道路，稍往前
走就到伏虎寺了。
LONG
        );
      set("item_desc", ([
            "gate" :    "　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n"
                        "　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
                        "　　　　　　　　≌≌　　　报　　国　　寺　　　≌≌\n"
                        "　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
                        "　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n",
         ]));
      set("objects", ([
               __DIR__+"npc/xiang-ke": 1,
      ]));
        set("exits", ([
  "south" : __DIR__"gchang",
  "west" : __DIR__"fhuang",
  "east" : __DIR__"fuhusi",
  "enter" : __DIR__"bgsddian",
]));
        set("no_clean_up", 0);

        set("coor/x",-60);
        set("coor/y",-50);
        set("coor/z",20);
        set("coor/x",-60);
        set("coor/y",-50);
        set("coor/z",20);
        set("coor/x",-60);
        set("coor/y",-50);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}
