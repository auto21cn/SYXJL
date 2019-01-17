inherit ROOM;

void create()
{
        set("short", "����ƺ");
        set("long", @LONG
�����ǰ�ɽ��һƬС��ƺ�����¶�����һ��·;���ɵ����Ծ�û��·��
ȥ����ǰ���羳����ͱڣ���ͷ�����������¶���ϡ������¥������
�ɾ����¶�����һֻ����¨(lou)������Ҫ���¶�Ҫ�����������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"shimen",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zu" : 1,
  __DIR__"npc/shashou" : 2,
]));

        setup();
}
void init()
{
    add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"zhulou")) )
            room = load_object(__DIR__"zhulou");
        if( room = find_object(__DIR__"zhulou") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"zhulou");
                room->set("exits/out", __FILE__);
                message("vision", "һ������¨�����ؽ���������ͣ�������ǰ��\n", this_object() );
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ�����������������������"
                    "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else
        message("vision", "��¨��ͣ�������ǰ,�ֺαغ��أ�\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "�¶��Ľ��̿�ʼת������¨���������ˡ�\n",
        this_object() );

    if( room = find_object(__DIR__"zhulou") )
    {
        room->delete("exits/out");
        message("vision", "�¶��Ľ��̿�ʼת������¨���������ˡ�\n",room);
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"zhulou") )
    {
        room->set("exits/out", __DIR__"shiwu");
        message("vision", "��¨���˼��£���һ��ʯ��֮��ͣ��������\n",room);

    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"zhulou") ) {
        room->delete("exits/out");
        message("vision","��¨���˼��£��ִ�ʯ��ʻ�����¡�\n", room);
        room->delete("yell_trigger");
    }
}

int do_yell(string arg)
{

    if( !arg || arg=="" ) return 0;

    if( arg=="����" ) arg = "����";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("neili") > 500 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
        message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="����")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("����ԶԶ����һ���������" + arg +
            "��������\n", this_player());
    return 1;
}
