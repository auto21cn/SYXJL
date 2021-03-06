// qingyunwu.c 青云舞

inherit SKILL;

mapping *action = ({
([      "action" : "$n足下轻轻回舞，乘势向左斜出半步，恰符合了青云舞中「忽焉纵体」的要旨，闪了开来。\n",
    "dodge"  : 10
]),
([      "action" : "$n使出「流风回雪」歪歪斜斜退了几步，似乎不成章法，却在间不容缓的空隙中躲过了$N的攻势。\n",
        "dodge"  : 20
]),
([      "action" : "$N的招式明明可以把$n围住，不知怎的，$n一式「轻云蔽月」，又如鬼魅般的跨出了圈外\n",
        "dodge"  : 30
]),
([      "action" : "$n一式「以遨以嬉」，瞻之在前，忽焉在后，$N招式的落点和$n身子间总有厘毫之差。\n",
        "dodge"  : 40
]),
([      "action" : "$n身形闪处，突然转向，使出了「神光离合」，$N加紧攻势，竟无法碰到$n一片衣角。\n",
        "dodge"  : 50
]),
([      "action" : "$n大喝一声，使出「乍阴还阳」，左足向右踏出，不料踏实之时，身子已在西北角上。\n",
        "dodge"  : 60
]),
([      "action" : "$n一式「飘忽若神」，侧身斜进，抢步“既济”，立闪“未济”，闪得几闪，已欺到$N的身后。\n",
        "dodge"  : 70
]),
([      "action" : "$n一式「体迅飞枭」，似乎自管自地踏步，毫不理会，每一步都踏在别人意想不到的所在。\n",
        "dodge"  : 80
])
});

mapping query_action(object me)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("qingyunwu");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(object me)
{
        mapping action;

        action = query_action(me);

        return action["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练青云舞。\n");
        me->receive_damage("qi", 30);
        return 1;
}

