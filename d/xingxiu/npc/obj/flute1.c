// flute1.c

// by QingP



#include <ansi.h>

#include <weapon.h>



inherit SWORD;



int do_play();



void init()

{

	add_action("do_play", "play");

}



void create()

{

	set_name("玉笛", ({"yu di", "di"}));

	set("unit", "支");

	set_weight(170);

	set("long", "这玉笛短得出奇，只不过七寸来长，通体洁白，晶莹可爱。\n"

	"你忍不住有一种想演奏(play)它的感觉。\n");

	set("value", 12000);

	set("material", "bamboo");

	set("wield_msg", "$N大袖一挥，手中已多了一支晶莹温润的玉笛。\n");

	set("unwield_msg", "$N手中玉萧一转，眨眼间玉笛已然不见影踪。\n");



//	setup();

}



int do_play(string arg)

{

	if (!id(arg))

		return notify_fail("你要演奏什么？\n");

	message_vision("$N将玉笛放到口边，轻轻一吹，一股尖锐的声音便远远传了出去。\n"

		+ "本来笛声轻扬激越，但这根白玉笛中发出的声音却十分凄厉，全非乐调。\n"

		+ "$N把笛子吹得高一阵，低一阵，如杀猪，似鬼哭，难听无比。")



	return 1;

}