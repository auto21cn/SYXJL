
// Room: /huoshan/hubian2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "湖边");
        set("long", @LONG
静静的湖水（hushui）就那样静静地展在你的身边，踩着柔柔
的草地，你早无一丝长途跋涉的疲惫，清清的湖水，瓦蓝的天空，
生机盎然的胡杨树林，这一切在你眼里都是美丽的享受。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "southeast" : __DIR__"pubu",
                "west"  : __DIR__"hubian1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}