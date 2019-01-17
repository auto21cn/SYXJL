// Room: /d/kunlun/tieqinju.c 

 

inherit ROOM; 

 

void create() 

{ 

        set("short", "铁琴居");

        set("long", @LONG
这里原是当今昆仑掌门何太冲的住处。但近来铁琴先生最宠爱第五夫人，从 
不独自在此，故此床铺已经撤去。墙上也空空荡荡，所珍爱的字画都移到五夫人 
的卧室去了，只剩下靠墙的一张几案，案上放着掌门人的铁琴(tieqin)，琴旁有 
一把拂尘 (fuchen)。 

LONG

        );

        set("no_clean_up", 0);

        set("exits", ([ /* sizeof() == 2 */

  "west" : __DIR__"sleeproom",

  "south" : __DIR__"zoul_5",

]));

        set("item_desc", ([ /* sizeof() == 2 */

  "fuchen" : "这是清理铁琴的拂尘, 用马尾制成

",

  "tieqin" : "一张黑黝黝的铁琴

",

]));

        set("objects", ([ /* sizeof() == 3 */

   "/d/kunlun/npc/kl-dizi4.c" : 1,

   "/d/kunlun/npc/kl-dizi2.c" : 1,

  __DIR__"npc/hetaichong.c" : 1,

]));



        setup();

        replace_program(ROOM);

}



