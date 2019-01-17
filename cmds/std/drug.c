// drug.c

inherit F_CLEAN_UP;

int do_effect(string type, mixed para);

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
	string item, target;
	object obj, dest;

	if (! arg)
                return notify_fail("��Ҫ��ʲô����\n");

        if (me->is_busy())
                return notify_fail("��æ���������е�����������ô���˰ɣ�\n");

        if (me->is_fighting())
                return notify_fail("���������ڴ�ܣ�ûʱ���¶���\n");

	if (sscanf(arg, "%s in %s", item, target) != 2)
		return notify_fail("��Ҫ�������¶���\n");

	dest = present(target, me);
	if (! dest)
                return notify_fail("����û������������\n");

	if (! objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");

	if (! stringp(obj->query("poison_type")))
                return notify_fail("�ⲻ�Ƕ�ҩ����\n");

        if (! obj->query("can_drug"))
                return notify_fail("���ֶ�ҩ��������ʳ���С�\n");

	if (dest->query("food_remaining") < 1)
	{
		tell_object(me, "�ⶫ������ȥû���˻�ȥ�ԡ�\n");
		return 1;
	}

	message("vision", sprintf("%s��һЩ����͵͵������%s���档\n",
		me->name(), dest->name()), environment(me), ({ me }));

	message("vision", sprintf("$s��һ%s%s͵͵������%s���档\n",
		obj->query("unit"), obj->name(), dest->name()), me);

        dest->set("eat_func", bind((: call_other, __FILE__, "do_effect",
                                   obj->query("poison_type"),
                                   obj->query("poison") :), dest));
	destruct(obj);
	return 1;
}

int do_effect(string type, mixed para)
{
        object me = this_player();
        mapping p;

        if (! objectp(me))
                return 1;

        if (mapp(para))
        {
                p = allocate_mapping(4);
                p["level"] = para["level"];
                p["id"]    = para["id"];
                p["name"]  = para["name"];
                p["duration"] = para["duration"] / 2 +
                                random(para["duration"] / 2);
                me->affect_by(type, p);
        } else
        {
                int old;
                if (intp(para) && intp(old = me->query_condition(type)))
                        me->apply_condition(type, para + old);
                else
                        me->apply_condition(type, para);
        }

        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : drug <��ҩ> in <ʳ��>
 
���ָ��������㽫ĳ����ҩ����ʳ���С�
HELP
    );
    return 1;
}