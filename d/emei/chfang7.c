#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
"�����Ǿ���ʦ̫���������򵥶�����İڷ���һ�Ŵ���һ��С��������\n"
"���ż����𾭣�����ʦ̫�������ڴ��ϣ�һ������ľ��һ�����\n"
        );

        set("exits", ([
		"east" : __DIR__"xilang4",
               ]));  
        set("objects", ([
          __DIR__"npc/jingxuan" : 1,
             ]));
        set("coor/x",-70);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",60);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}