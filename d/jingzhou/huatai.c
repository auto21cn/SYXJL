
// Room: /jingzhou/huatai.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "花台");
        set("long", @LONG
这里是荆州城的正中心，一个很宽阔的广场，铺着青石地面。中间有
个很大的花坛，周遍经常见到一些游手好闲的人在这里溜溜达达，也有些
艺人在这里表演。花坛中有棵大榕树，盘根错节，据传已有千年的树龄，
是这座城市的历史见证。你可以看到北边有来自各地的行人，南面可去繁
华的关庙，每年的庙会都在那里开展，所以一直是人声鼎沸，一派繁华景
象，东面不时地传来阵阵的喧闹，西边的街道旁的树长得比较茂盛，夏日
里很多人都搬出竹椅在树阴下下棋喝茶。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jingzhonglu",
                "south" : __DIR__"nanmendajie",
                "west"  : __DIR__"xidajie3",
                "north" : __DIR__"sanyijie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}