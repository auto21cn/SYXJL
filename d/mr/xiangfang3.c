#include <ansi.h>

#include <room.h>

inherit ROOM;

void create()

{

         set("short","�᷿");

         set ("long",@long

����һ���᷿, ��������, ֻ��һ�Ŵ�, һ��������һ�����ӡ�

long);

         set("no_fight", 1);

         set("sleep_room", 1);

         set("exits",([

             "east" : __DIR__"houting",

             "west" : __DIR__"c16-1",

             "north" : __DIR__"jushi",

]));

         setup();

         replace_program(ROOM);

}
