//ROM yuanzi

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
             "������������µġ�����ɽׯ���Ĵ��š��������ϵ����̷��ۼ\n"
         "���أ���֪�����Ŷ����ܹ��ɽ�����Ѫ�����Գ�ׯ���ĸ������Թ���\n"
         "ǰ���Ҹ�����һֻ����ׯ�ϵ�ʯʨ�ӡ�\n"
        );
        set("outdoors", "baituo");
        set("exits", ([
		"north" : __DIR__"yuanzi",
                "southdown" : __DIR__"shijie",
        ]));
        set("objects",([
                __DIR__"npc/menwei" : 2,
	]));
	set("coor/x",-130);
	set("coor/y",-40);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",-40);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",-40);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",-40);
	set("coor/z",-10);
	setup();
}

int valid_leave(object me, string dir)
{

	if (  (dir == "north")
	   && ((int)me->query("shen") > 300)
	   && objectp(present("men wei", environment(me)))
	   && living(present("men wei", environment(me))))
	 return notify_fail
		("��������һ���������������������һ���Ͷ��ģ������\n");
	return ::valid_leave(me, dir);
}