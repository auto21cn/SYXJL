// banname.c

// writed by shadow



void create()

{

	seteuid(getuid());

}



int main(object me, string arg)

{

//         string banname, banname1, *banname2;
          string banname;
	int i;



	if (!arg)

	{

		if ( file_size(CONFIG_DIR + "banned_name") >=0 )

			me->start_more(read_file(CONFIG_DIR + "banned_name"));

		else

			write("没有禁止的中文名字。\n");

		return 1;

	}

	else if (sscanf(arg, "+ %s", banname) == 1)

	{

		i = strlen(banname);



		while(i--)

		{

			if ( (strlen(banname) < 2) || (strlen(banname) > 12 ) )

			{

				write("不能禁止 " + banname + "，中文名字必须是 1 到 6 个中文字。\n");

				return 1;

			}

			if ( banname[i]<=' ' )

			{

				write("不能禁止 " + banname + "，中文名字不能用控制字元。\n");

				return 1;

			}

			if ( i%2==0 && !is_chinese(banname[i..<0]) )

			{

				write("不能禁止 " + banname + "，请用「中文」取名字。\n");

				return 1;

			}

		}

		write_file(CONFIG_DIR + "banned_name", banname + "\n" );

		write("OK.\n");

	}

	else if (sscanf(arg, "- %s", banname) == 1)

	{

		write("请修改 " + CONFIG_DIR + "banned_name" + " 解禁。\n");

	}

	else write("指令格式：banname [+|- chinesename]\n");



	return 1;

}



int help(object me)

{

	write(@HELP

指令格式：banname [+|- chinesename]



这条命令是用来防止有人蓄意乱起中文名字。

HELP

	);

	return 1;

}

