inherit ROOM;

void create()
{
        set("short", "山门");
        set("long", @LONG
这里是峨嵋山的山门，迎面一座高大的汉白玉山门。石阶从山门下穿
过，山门的后面是一座雄伟的大殿，那就是峨嵋的山门殿。山门旁有一群
峨嵋派的守山弟子在检查过往行人，不是峨嵋派的不让上山。还有一个慈
祥的中年尼姑在接待想加入峨嵋派的朋友。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shmdian",
  "westdown" : __DIR__"yunvchi",
]));
        set("no_clean_up", 0);
        set("objects",([
               __DIR__"npc/wenxu" : 1, 
               __DIR__"npc/shoushan" : 4,  
            ]));         
        set("coor/x",-30);
        set("coor/y",-30);
        set("coor/z",60);
        set("coor/x",-30);
        set("coor/y",-30);
        set("coor/z",60);
        set("coor/x",-30);
        set("coor/y",-30);
        set("coor/z",60);
        setup();
}

