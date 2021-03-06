inherit ROOM;

void create()
{
	set("short", "武场中心");
	set("long", @LONG
这里是天龙寺的练武场。由无数块巨大的花岗岩石板铺就。
上千年的踩踏已使得这些石板如同镜子般平整光滑。西边角上还
有两个大沙坑，十来个僧人正在练习武艺。南北两面各有一练武
场。
LONG
	);

	set("exits", ([
		"south" : __DIR__"wuchang2",
		"east" : __DIR__"wuchang3",
		"westup" : __DIR__"doushuai",
		"north" : __DIR__"wuchang4",
	]));

	set("outdoors", "tianlongsi");
	set("objects",([
		__DIR__"npc/saodiseng" : 1,
                __DIR__"npc/gui-yuan" : 1,
	]));
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",20);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",20);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",20);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",20);
	setup();

}

void init()
{
	object me;
	mapping skill_status;
	string *sname;
	int i, level; 
	float exper;

	me = this_player();

	if (wizardp(me)) return;

	exper = to_float(me->query("combat_exp"));

	if ( !(skill_status = me->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper 
		&& exper > 100.0
		&& sname[i] != "buddhism"
		&& sname[i] != "literate"
		&& sname[i] != "taoism" ) 
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			me->set_skill(sname[i], level);
		}
	}
}



