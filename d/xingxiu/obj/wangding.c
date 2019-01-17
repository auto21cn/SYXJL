// wangding.c 神木王鼎
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL"神木王鼎"NOR, ({"shenmu wangding", "wangding", "ding"}));
	set("long","这是一尊六寸来高大小的木鼎，深黄颜色，雕琢甚是精细，木质坚润\n"
	"似玉，木理之中隐隐约约的泛出红丝。\n");
	set("unit", "尊");
	set("weight", 120);
        set("no_drop", "这样东西不能离开你。\n");
}

