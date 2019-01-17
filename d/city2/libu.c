//libu.c 礼部大堂

inherit ROOM;

void create()
{
        set("short", "礼部大堂");
        set("long", @LONG
这里就是礼部大堂，大堂正前方是一位仙风道骨的老人，他就是
礼部尚书，名扬“鹿鼎记”的大文豪--小鱼儿。小鱼儿历来以爱才闻
名海内，如果你的能得到他的赏识，就是万幸了。堂前醒目的大字是
“肃静”。
LONG
        );

        set("exits", ([ 
                      "north" : __DIR__"yamen",
                     ]));
        set("objects", ([
                __DIR__"npc/shutong": 2,
                __DIR__"npc/xiaoyu": 1,
        ]) );

        setup();
}

