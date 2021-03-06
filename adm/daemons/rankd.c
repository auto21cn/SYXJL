// rankd.c
// 1996-02-15 dts ranking related to "shen"
// modified by aeolus, adding more titles 11/29/2000

#include <ansi.h>

string query_rank(object ob)
{
      mapping fam;

      int shen;
      int budd;
      int exp;
      int age;
     if( ob->is_ghost() ) 
            return HIB "【 孤魂野鬼 】" NOR;
      exp  = ob->query("combat_exp");
      shen = ob->query("shen");
      age = ob->query("age");
        //added by aeolus
        if ( (fam = ob->query("family")) && (fam["family_name"] == "少林派"
                || fam["family_name"] == "峨嵋派"
                || fam["family_name"] == "天龙寺"
                || fam["family_name"] == "雪山派"
                || fam["family_name"] == "恒山派"
                ))
                budd = ob->query_skill("buddhism",1);

      switch(ob->query("gender")) {
        case "女性":
              switch(wizhood(ob)) {
              case "(admin)": 
	       return HIW "【  女  神  】" NOR;
	         case "(sage)": 
	       return HIR "【 九天玄女 】" NOR;
              case "(arch)":   
           return HIY "【  圣  女  】" NOR;
	          case "(angel)": 
	       return HIM "【  天  使  】" NOR;
              case "(wizard)":        
           return HIG "【  仙  女  】" NOR;
              case "(apprentice)":    
           return HIC "【 小 仙 女 】" NOR;
               default:
                        if( ((int)ob->query("PKS") > 50) )
                              return HIR "【 血    奴 】" NOR;
                        else if (shen >= 1000000)
                                 return HIW "【 旷世女侠 】" NOR;
                        else if (shen >= 10000)
                                 return HIY "【 巾帼英雄 】" NOR;
                        else if (shen >= 1000)
                                 return HIC "【 武林新秀 】" NOR;      
                        else if (shen >= 100)
                                 return HIC "【 小有名声 】" NOR;  
                        else if (shen >= 10)
                                 return HIC "【 走上侠道 】" NOR;
                        else if (shen >= 5)
                                 return "【 初涉江湖 】";
                        else if (shen <= -1000000)
                                 return HIR "【 嗜血女魔 】" NOR;                   
                        else if (shen <= -100000)
                                 return WHT "【 饮血魔女 】" NOR;                  
                        else if (shen <= -10000)
                                 return BLU "【 地狱天使 】" NOR;
                        else if (shen <= -1000)
                                 return HIC "【 绝情怨女 】" NOR;
                        else if (shen <= -100)
                                 return HIC "【 刁蛮恶女 】" NOR;
                        else if (shen <= -10)
                                 return HIB "【 误入岐途 】" NOR;
                        else if( (int)ob->query("thief") > 15 ) 
                                 return HIW "【 女惯窃 】" NOR;
                        else
                        switch(ob->query("class")) {
                        case "bonze":
                             if (budd >= 150)
                                return HIY "【 神  尼 】" NOR;
                             else if (budd >= 120)
                                return HIY "【 圣  尼 】" NOR;
                             else if (budd >= 90)
                                return HIY "【 德  尼 】" NOR;
                             else if (budd >= 60)
                                return HIY "【 贤  尼 】" NOR;
                             else if (budd >= 30)
                                return HIY "【 师  太 】" NOR;
                             else if (age <= 16)
                                return "【 小尼姑 】";
                             else
                                return "【 尼  姑 】";
	          //added by aeolus
	          case "taoist":
                                        if (ob->query_skill("taoism",1)>100)
			return GRN"【 炼精化气 】"NOR;        
                                        else if (ob->query_skill("taoism",1)>150)
                                          return HIR"【 炼气化神 】"NOR;
                                        else if (ob->query_skill("taoism",1)>200)
                                          return HIW"【 炼神还虚 】"NOR;
                                        else if (ob->query_skill("taoism",1)>250)
                                           return HIY"【 玄  女 】"NOR;
		             if (age <= 16)
                                          return "【 小 道 姑 】";
        		             else if (age <= 30)
			return "【 道  姑 】";
 		             else
			return "【 老道姑 】";
                        case "yishi":   
                                return RED"【 女义士 】"NOR;
                        case "taoist":  
                       
                        case "bandit":  
                                return HIB"【 女飞贼 】"NOR;
                        case "dancer":  
                                return RED"【 绝色舞姬 】"NOR;          
                        case "officer": 
                                return RED"【 女捕快 】"NOR;
                        case "fighter": 
                                return MAG"【 风尘女子 】"NOR;                    
                        case "swordsman":       
                                return WHT"【 舞剑少女 】"NOR;                    
                        case "alchemist":       
                                return HIC"【 女方士 】"NOR;                   
                        case "shaman":  
                                return HIR"【 女巫医 】"NOR;
                        case "beggar":  
                                return BLU"【 女叫花子 】"NOR;      
                        case "shiny":
                                return HIY"【 光明女使 】"NOR;
	          //added by aeolus
	          case "scholar":
                                     if (ob->query_skill("literate",1)>100)
		            return HIG"【 遥遥佳人 】"NOR;         
                                     else if (ob->query_skill("literate",1)>150)
                                        return HIY"【 才华出众 】"NOR;
                                     else if (ob->query_skill("literate",1)>200)
                                        return HIW"【 女圣人 】"NOR;          
                                     else if (ob->query_skill("literate",1)>250&&ob->query("per",1)>25)
                                        return HIM"【 才貌双绝 】"NOR;   
                                     else if (age <= 16)
                                        return "【 女学童 】";
                                     else if (age <= 30)
                                        return "【 才  女 】";
                                     else
                                        return "【 女学士 】";
                        case "prostitute":
                                return "【 妓  女 】";
                        default:
                                if (age <= 16)
                                    return "【 纯真少女 】";
                                else if(age<=30)
                                    return "【 少  妇 】";
                                else if(age<=45)
                                    return "【 妇  人 】";
                                else
                                    return "【 老婆子 】";                  
                        }
                }
default:
                switch(wizhood(ob)) {
                case "(admin)": 
	              return HIW "【  天  帝  】" NOR;
	            case "(sage)": 
	              return HIR "【 八部天神 】" NOR;
                case "(arch)":  
                  return HIY "【  大  神  】" NOR;                
	            case "(angel)": 
	              return HIM "【 守 护 神 】" NOR;
                case "(wizard)":        
                  return HIG "【  巫  神  】" NOR;        
                case "(apprentice)":    
                  return HIC "【 小 仙 人 】" NOR;      
                default:
                        if( ((int)ob->query("PKS") > 60) )
                                 return HIR "【 杀人魔王 】" NOR;
                        else if (shen >= 1000000)
                                 return HIW "【 武林泰斗 】" NOR;
                        else if (shen >= 100000)
                                 return HIY "【 名满天下 】" NOR;
                        else if (shen >= 10000)
                                 return HIY "【 名动一时 】" NOR;
                        else if (shen >= 1000)
                                 return HIC "【 武林新秀 】" NOR;      
                        else if (shen >= 100)
                                 return HIC "【 小有名声 】" NOR;  
                        else if (shen >= 10)
                                 return HIC "【 走上侠道 】" NOR;
                        else if (shen >= 5)
                                 return "【 初入江湖 】";
                        else if (shen <= -1000000)
                                 return HIR "【 当世魔头 】" NOR;                   
                        else if (shen <= -100000)
                                 return RED "【 恶名昭著 】" NOR;                  
                        else if (shen <= -10000)
                                 return HIG "【 恶霸一方 】" NOR;
                        else if (shen <= -1000)
                                 return HIG "【 恶名远扬 】" NOR;
                        else if (shen <= -100)
                                 return HIC "【 小有恶名 】" NOR;
                        else if (shen <= -10)
                                 return HIB "【 误入岐途 】" NOR;
                        else if( (int)ob->query("thief") > 15 ) 
                                 return HIW "【 无赖惯窃 】" NOR;                              
                        else
                        switch(ob->query("class")) {
		    //modified by aeolus
                                case "bonze":
                                        if (budd >= 150)
                                                return HIY "【 长  老 】" NOR;
                                        else if (budd >= 120)
                                                return HIY "【 圣  僧 】" NOR;
                                        else if (budd >= 90)
                                                return HIY "【 罗  汉 】" NOR;
                                        else if (budd >= 60)
                                                return HIY "【 尊  者 】" NOR;
                                        else if (budd >= 40)
                                                return HIY "【 禅  师 】" NOR;
                                        else if (budd >= 30)
                                                return HIY "【 比  丘 】" NOR;
                                        else if (age <= 16)
                                                return "【 小和尚 】";
                                        else
                                                return "【 僧  人 】";
	          //added by aeolus
	          case "taoist":
                                        if (ob->query_skill("taoism",1)>100)
			return GRN"【 炼精化气 】"NOR;        
                                        else if (ob->query_skill("taoism",1)>150)
                                          return HIR"【 炼气化神 】"NOR;
                                        else if (ob->query_skill("taoism",1)>200)
                                          return HIW"【 炼神还虚 】"NOR;
                                        else if (ob->query_skill("taoism",1)>250)
                                           return HIY"【 真  人 】"NOR;
                                        else if (age <= 16)
                                          return "【 小 道 士 】";
                                        else if (age <= 30)
                                           return "【 道  士 】";
                                        else
                                           return "【 道  长 】";
	          //added by aeolus
	          case "scholar":
                                     if (ob->query_skill("literate",1)>100)
                                        return HIG"【 翩翩才子 】"NOR;        
                                     else if (ob->query_skill("literate",1)>150)
                                        return HIY"【 才高八斗 】"NOR;
                                     else if (ob->query_skill("literate",1)>200)
                                        return HIM"【 学富五车 】"NOR;
                                     else if (ob->query_skill("literate",1)>250)
                                        return HIW"【 圣  人 】"NOR;             
                                     else if (age <= 16)
                                        return "【 学  童 】";
                                     else if (age <= 45)
                                        return "【 书  生 】";
                                     else
                                        return "【 老秀才 】";
                        case "yishi":   
                                return RED"【 江湖义士 】"NOR;                           
                        case "bandit":  
                                return HIB"【 梁上君子 】"NOR;
                        case "officer": 
                                return HIG"【 衙  差 】"NOR;
                        case "swordsman":       
                                return WHT"【 多情剑客 】"NOR;                    
                        case "alchemist":       
                                return HIC"【 方  士 】"NOR;                   
                        case "shaman":  
                                return HIR"【 巫  医 】"NOR;
                        case "beggar":  
                                return MAG"【 穷叫花子 】"NOR;      
                        case "shiny":
                                return HIY"【 光明使者 】"NOR;
		//added by aeolus
                                case "eunach":
                                        budd = ob->query_skill("pixie-jian",1);
                                        if (budd >= 110)
                                                return HIM "【大内高手】" NOR;
                                        else if (budd >= 100)
                                                return HIM "【东厂万户】" NOR;
                                        else if (budd >= 90)
                                                return HIM "【东厂千户】" NOR;
                                        else if (budd >= 80)
                                                return HIM "【东厂百户】" NOR;
                                        else if (budd >= 70)
                                                return HIM "【东厂十户】" NOR;
                                        else if (budd >= 60)
                                                return HIM "【东厂公公】" NOR;
                                        else return "【 内  侍 】";
                                case "prostitute":
                                        return "【 龟  公 】";
                        default:
                                if (age <= 16)
                                  return "【 纯朴少年 】";
                                else if(age<=30)
                                    return "【 壮  丁  】";
                                else if(age<=45)
                                    return "【 汉  子 】";
                                else
                                    return "【 老爷子 】";           
                }
          }
    }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师太";
                                else return "师太";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小仙姑";
                                else return "仙姑";
                                break;
                        default:
                                if( age < 18 ) return "小姑娘";
                                else if( age < 30 ) return "姑娘";
                                else if( age < 40 ) return "大婶";
                                else return "婆婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师父";
                                else return "大师";
                                break;
                        case "taoist":
if( age < 18 ) return "道兄";
                                else return "道长";
                                break;
                        case "scholar":
                                if( age < 18 ) return "小相公";
                                else if( age < 50 ) return "相公";
                                else return "老先生";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "小老弟";
                                else if( age < 50 ) return "壮士";
                                else return "老前辈";
                                break;
                        default:
                                if( age < 20 ) return "小兄弟";
                                else if( age < 50 ) return "壮士";
                                else return "老爷子";
                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
         
               case "bonze":
                                if( age < 18 ) return "小贼尼";
                                if( age < 30 ) return "贼尼";
                                else return "老贼尼";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小妖女";
                                if( age < 30 ) return "妖女";
                                else return "老妖婆";
                        default:
                                if( age < 18 ) return "小娘皮";
                                if( age < 25 ) return "小贱人";
                                if( age < 40 ) return "贼婆娘";
                                else return "死老太婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小贼秃";
                                if( age < 50 ) return "死秃驴";
                                else return "老秃驴";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小杂毛";
                                if( age < 30 ) return "死牛鼻子";
                                else return "老杂毛";
                                break;
                        case "scholar":
                                if( age < 18 ) return "小书呆子";
                                else if( age < 50 ) return "臭书呆子";
                                else return "老童生";
                                break;
                        default:
                                if( age < 20 ) return "小王八蛋";
                                if( age < 30 ) return "狗贼";
                                if( age < 50 ) return "臭贼";
                                if( age < 80 ) return "老匹夫";
                                else return "老不死";
                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        case "taoist":
                                return "贫道";
                                break;
                        default:
                                if( age < 20 ) return "小女子";
                                if( age > 50 ) return "老身";
                                else return "妾身";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小和尚";
                                if( age < 40 ) return "贫僧";
                                else return "老衲";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小道";
                                if( age < 30 ) return "贫道";
                                else return "老道";
                                break;
                        case "scholar":
                                if( age < 30 ) return "晚生";
                                else return "不才";
                                break;
                        default:
                                if( age < 50 ) return "在下";
                                else return "老头子";
                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;
        
        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return 
"贫尼";
                                else return "老尼";
                                break;
                        case "taoist":
                                return "本仙姑";
                                break;
                        default:
                                if( age < 20 ) return "本姑娘";
                                if( age < 30 ) return "姑奶奶我";
                                else return "老娘";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "大和尚";
                                else return "老和尚";
                                break;
                                if( age < 30 ) return "本山人";
                                return "老道我";
                                break;
                        case "scholar":
                                if( age < 50 ) return "本相公";
                                else return "老夫子我";
                                break;
                        default:
                                if( age < 20 ) return "本少爷我";
                                if( age < 40 ) return "大爷我";
                                else return "老子";
                                break;
                        }
        }
}
string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (ob->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age")) {
                        a1 = this_player()->query("mud_age");
                } else
	  {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (this_player()->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "兄弟我";
                else
                        return "小弟我";
        }
}
