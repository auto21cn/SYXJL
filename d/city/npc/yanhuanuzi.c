inherit NPC;

void create()
{
  set_name("�̻�Ů��", ({"yanhua nuzi", "nuzi", "girl"}) );
  set("gender", "Ů��" );
  set("age", 20);
  set("long","һλ��ü���溬Ц����ȹ��¶���ص���Ů��\n");

  set("combat_exp", 2500);
  set("str", 15);
  set("attitude","heroism");

  setup();
  carry_object("/clone/misc/cloth")->wear();
}

void init()
{
  add_action ("do_makelove","makelove");
  remove_call_out ("says");
  call_out("says",random(3),this_object());
}

void says (object me)
{
  string *msgs = ({
    "$N�Գ�һЦ�����쿴���㡣\n",
    "$N���������ض���˵�����ҡ���\n",
    "����$N������㡭�������Ը�⣬Ҳ����һ�� makelove ���\n",
    "$N��������ĵ�һЦ�����˵�ͷ��\n",
    "$N������㡭��\n",
    "$N�������һЦ��\n",
  });
  message_vision (msgs[random(sizeof(msgs))],me);
  remove_call_out ("says");
  call_out("says",random(40),me);
}

int do_makelove ()
{
  object me = this_object();
  object who = this_player();
  message_vision ("$N§��$n���������壬���ɵ��������ԡ���\n\n",who,me);
  who->command_function("remove all");
  who->start_busy(3,3);
  remove_call_out ("get_fainted");
  call_out ("get_fainted",1,who,me);
  remove_call_out ("says");
  call_out("says",40,me);
  return 1;
}

void get_fainted (object who, object me)
{
  object *objs = all_inventory(who);
  int i = sizeof (objs);
  message_vision ("$N��$n���ص�һЦ��\n\n",me,who);
  who->unconcious();    
  while (i--)
  {
    object obj = objs[i];
    message_vision ("$N��$n�����ó�"+obj->query("name")+"��\n",me,who);
    obj->move(me);
    destruct(obj);
  }
}