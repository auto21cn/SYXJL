//room: caifang.c
inherit ROOM;

void create()
{
  set("short","��");
  set("long","���Ǽ䲻���Ĳ񷿣�ľ���Ѿ����չ��ˣ�ǽ�Ƿ��ż��ѡ��񵶡���\n");
  set("exits",([
      "west" : __DIR__"chufang",
     ]));
  set("objects",([
    __DIR__"npc/laocai" : 1,
    ]));

 set("coor/x",-110);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",10);
	set("coor/z",0);
	setup();
 replace_program(ROOM);
}





