// yield.c
// Emperor@SDXL add this command in 99.2.8.

int main(object me, string arg)
{
                        if (arg=="yes") {
                     me->set("yield",1);
                     me->reset_action();
                     write("你决定只招架，不还手。\n");
                     return 1;
                }
                  else if (arg=="no") {
                 me->delete("yield");
                 me->reset_action();
                 write("你决定开始还手。\n");
                 return 1;
           }

                  else  write("命令格式：yield [ yes|no ].\n");
                 return 1;
      }
