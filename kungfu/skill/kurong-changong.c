// kurong-changong.c  枯荣禅功

inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yang";
}

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
        int nb, nf, nh, ns;
	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("kurong-changong", 1);
	ns = (int)me->query("guilty");

       	if ( me->query("couple/have_couple") )
        	return notify_fail("你已经破了色戒，无法再学习枯荣禅功！\n");

          if ( me->query("gender") == "女性" )
		return notify_fail("你非童男之体，不能练习枯荣禅功。\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("你的禅宗心法修为不够，无法领会更高深的枯荣禅功。\n");

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会枯荣禅功。\n");

	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的枯荣禅功。\n");

        if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调，难以领会高深的枯荣禅功。\n");

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
//      || me->query_skill("kurong-changong",1) 
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
        || me->query_skill("xixing-dafa",1)
        || me->query_skill("jiuyang-force",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学习枯荣禅功？！\n");

	return 1;
}


int practice_skill(object me)
{
     	return notify_fail("枯荣禅功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return "/kungfu/skill/kurong-changong/" + func;
}
