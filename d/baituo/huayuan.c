//room: huayuan.c
inherit ROOM;

void create()
{
  set("short","��԰");
  set("long",
       "���Ǹ������Ĵ�԰��԰�������������޵ĺ�õ�塣\n"
   "������Ů����������Ϸ���������������Ļ���������ͨ��\n"
   "ɽׯ������ط��������ǳ����������ǰ���ɽ������ŷ��\n"
   "�ˡ������ң��������ţ���֪�����ڲ��ڡ�\n"
      );
  set("exits",([
      "west" : __DIR__"neishi",
      "north" : __DIR__"zhuyuan",
      "east" : __DIR__"chufang",
      "south" : __DIR__"menlang",
     ]));
  set("outdoors", "baituo");
  set("objects",([
    __DIR__"npc/whitelady" : 2,
    ]));
 set("coor/x",-130);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",10);
	set("coor/z",0);
	setup();
 replace_program(ROOM);
}





