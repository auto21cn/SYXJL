inherit ROOM;

void create()
{
        set("short", "兜率大士院");
        set("long",@LONG
这是一般参拜者所能到的最远的地方，再往南远远可以看见天龙寺历
代高僧静修之处——牟尼堂。那是常人不可轻易打搅的地方，你最好不要
擅自闯入。除非你确信能给高僧们带去好消息。
LONG
        );
        set("exits", ([
                "north" : __DIR__"shengdian",
                "southup" : __DIR__"banruotai",
                "southdown" : __DIR__"wuchang",
                ]));
//      set("objects",([
//                __DIR__"obj/xianglu" : 1,
//        ]));
        set("coor/x",-80);
	set("coor/y",-120);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-120);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-120);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-120);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}


void init()
{
    add_action("do_knock", "knock");
    add_action("do_push", "push");
}

int close_men()
{
    object room;

    if(!( room = find_object(__DIR__"munitang")) )
        room = load_object(__DIR__"munitang");
    if(objectp(room))
    {
        delete("exits/west");
        message("vision", "门吱吱呀呀地自己合上了。\n", this_object());
        room->delete("exits/east");
        message("vision", "门吱吱呀呀地自己合上了。\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/west"))
        return notify_fail("大门已经是开着了。\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("你要敲什么？\n");

    if(!( room = find_object(__DIR__"munitiang")) )
        room = load_object(__DIR__"munitang");
        
         
    return 1;
}

int do_push(string arg)
{
    object room;

    if (query("exits/west"))
        return notify_fail("门已经是开着了。\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("你要推什么？\n");

    if(!(room = find_object(__DIR__"munitang")))
        room = load_object(__DIR__"munitang");
        
    if(objectp(room))
    {
                if((int)room->query_temp("person_inside")<=0)
                {
                        room->delete_temp("person_inside");
                        set("exits/west", __DIR__"munitang");
                        message_vision("$N轻轻地把门推开。\n", this_player());
                        room->set("exits/east", __FILE__);
                        remove_call_out("close_men");
                        call_out("close_men", 10);
                }
                else 
                {
                        message_vision("$N想把门推开，却发觉门被人从里面闩上了。\n",this_player());
                }
        }

    return 1;
}

string look_men()
{
    object room;

    if (query("exits/east"))
                return ("门上挂了个牌子：牟尼堂。请勿喧哗。\n");

    if(!( room = find_object(__DIR__"munitang")) )
        room = load_object(__DIR__"munitang");

    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
                return ("门上挂了个牌子：打扰一次、罚跪三天!\n");
    } 
    
    return ("门上挂了个牌子：天龙寺长老进修之处。\n");
}

int valid_leave(object me, string dir)
{
        object room;
        
        if(!( room = find_object(__DIR__"munitang")) )
                room = load_object(__DIR__"munitang");

        if(objectp(room) && dir == "west")
        {
                room->add_temp("person_inside", 1);
                remove_call_out("force_open");
                call_out("force_open", 299, room);
        }               

        return ::valid_leave(me, dir);
}

int force_open(object room)
{
        if(!objectp(room))
                return 0;
    if((int)room->query_temp("person_inside") <= 0)
                return 0;
    
        room->delete_temp("person_inside");
    set("exits/west", __DIR__"munitang");
    room->set("exits/east", __FILE__);
    message("vision", "外面突然响起粗重的脚步声，由远而近，到门前停了下来．．．\n"
        "本  啪地把门打开，伸个头进来，一脸狐疑：呆大半天了还不出去，打扰长老练功了？\n", room);
    remove_call_out("close_men");
    call_out("close_men", 10);
}

