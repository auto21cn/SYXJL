// zhenyue.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������Ϊƽ̹���ϡ���ɽ���οͶ��ڴ�������Ϣ�ټ���ǰ�С���
���м����ª�����磬���Ƕ�����ճ��ߣ�����ͷ��ЪϢ�ڴˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"westup" : __DIR__"canglong",
		"southwest" : __DIR__"chaoyang",
		"eastup" : __DIR__"yunu",
		"northdown" : __DIR__"husun",
	]));

	set("objects", ([ 
		__DIR__"npc/gao" : 1,
	]));

	set("no_clean_up", 0);
        set("outdoors", "��ɽ");

	set("coor/x",70);
	set("coor/y",90);
	set("coor/z",60);
	set("coor/x",70);
	set("coor/y",90);
	set("coor/z",60);
	set("coor/x",70);
	set("coor/y",90);
	set("coor/z",60);
	set("coor/x",70);
	set("coor/y",90);
	set("coor/z",60);
	setup();
}
 
int valid_leave(object me, string dir)
{
	if (dir != "northdown" )
	{
		if(me->query("family/family_name") !="��ɽ��")
		{
               if(me->query("combat_exp") > 5500)
			{
				if(present("gao genming", environment(me)) && living(present("gao genming", environment(me))))
				{
					return notify_fail(
"�߸����ȵ��������Ǳ����صأ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
				}
				else
					return ::valid_leave(me, dir);
			}
			else
				return ::valid_leave(me, dir);
		}
		else
			return ::valid_leave(me, dir);
	}
	else
		return ::valid_leave(me, dir);

}