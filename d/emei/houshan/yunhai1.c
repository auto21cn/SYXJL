inherit ROOM;

void create()
{
        set("short", "云海");
        set("long", @LONG
这里就是峨嵋著名的云海了，放眼望去，漫山遍野都是云雾，根本就弄
不清自己身在何出，四周都是出路，什么都看不清楚。
LONG   );
  
        set("coor/x",-60);
        set("coor/y",130);
        set("coor/z",110);
        set("coor/x",-60);
        set("coor/y",130);
        set("coor/z",110);
        set("coor/x",-60);
        set("coor/y",130);
        set("coor/z",110);
        setup();
        
}

void init()
{
  object me = this_object();
  me->set("exits/east",__DIR__"yunhai1"+random(3));
  me->set("exits/west",__DIR__"yunhai"+random(3));
  me->set("exits/north",__DIR__"yunhai"+random(3));
  me->set("exits/south",__DIR__"yunhai"+random(3));
}
