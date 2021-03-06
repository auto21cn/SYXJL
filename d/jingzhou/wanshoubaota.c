
// Room: /jingzhou/wanshoubaota.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "万寿宝塔");
        set("long", @LONG
本来修建此塔的原意是镇水之用。万寿塔依堤傍江，高耸如云，四周是
一大片清翠竹林，即使炎夏也是凉风习习，景致一片大好，一般外地游客都
要来此游览一下。听说塔尖的金顶内藏有前朝太后亲笔手书的《金刚经》。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "up"  : __DIR__"tading",
                "west"  : __DIR__"dukou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}