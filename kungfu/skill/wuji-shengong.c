// wuji-shengong.c 无极神功

inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yin";
}

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
      int i = (int)me->query_skill("wuji-shengong", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t *= 2;

	if ((int)me->query_skill("force", 1) < 10)
              return notify_fail("你的基本内功火候还不够。\n");

	   if ( me->query_skill("bibo-shengong",1)     
          || me->query_skill("bahuang-gong",1)     
//		|| me->query_skill("beimin-shengong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong-dafa",1)
		|| me->query_skill("huntian-qigong",1)
		|| me->query_skill("hunyuan-yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("jiuyang-shengong",1)
		|| me->query_skill("taiji-shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong-shengong",1)
		|| me->query_skill("zixia-shengong",1) )
                return notify_fail("你不先散了别派内功，怎能学无极神功？！\n");
        return 1;
}

int practice_skill(object me)
{
       return notify_fail("无极神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
       return __DIR__"wuji-shengong/" + func;
}
