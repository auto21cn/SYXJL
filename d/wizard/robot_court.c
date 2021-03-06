// Room: /d/wizard/robot_court.c
// By Jpei  Aug 1997

#include <ansi.h>

inherit ROOM;

void hour_pass();

void create()
{
	set("short", "机器人法庭");
	set("long", @LONG
这里是最令机器人害怕的机器人法庭，除了靠墙的一张桃木桌和桌后坐着
的机器人法官外，四周什么也没有。
在这里你可以要求审判：ask faguan about 审判
审判时回答错误，可以要求上诉：ask faguan about 上诉
LONG);

	set("objects", ([
		"/clone/npc/robot-judge" : 1,
	]) );
	set("no_clean_up", 1);
	set("no_fight", 1);
	setup();
//	hour_pass();
}

void init()
{
	add_action("do_action", "");
}

int do_action(string arg)
{
	string action = query_verb();

	switch (action) {
		case "dazuo":
		case "exercise":
		case "tuna":
		case "meditate":
		case "lian":
		case "practice":
			write("这不是你能练功的地方。\n");
			return 1;

		case "yun":
		case "exert":
		case "perform":
		case "yong":
		case "fight":
		case "hit":
		case "kill":
			write("这不是你能打架的地方。\n");
			return 1;

		case "save":
			write("这不是你能存盘的地方。\n");
			return 1;


	}
	return 0;
}

void test_robot()
{
	int i;
	object antirobot;
	object *ob = users();

	message("channel:chat", HIC "【闲聊】机器人侦缉总部：反呆组各探员请注意，扫呆行动正式开始！\n" NOR, users());
	for (i = 0; i < sizeof(ob); i++) {
		antirobot = new("/clone/npc/antirobot2");
		antirobot->test_robot(ob[i]);
	}
}

void hour_pass()
{
	mixed *local;

	local = localtime(time());
	if (local[2] == 1) test_robot();
	call_out("hour_pass", 3600);
}
