// topten.c

#define TOPTEN DATA_DIR + "topten/topten"

inherit ITEM;
inherit F_SAVE;

mapping *exp_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});

mapping *richman_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});

mapping *oldman_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});

mapping *force_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});

mapping *pks_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});

mapping *literate_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});

mapping *unarmed_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});

mapping *dodge_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});

mapping *thief_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});

mapping *axe_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});

mapping *blade_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});

mapping *throwing_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});

mapping *fork_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});

mapping *hammer_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),
});

mapping *staff_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});

mapping *sword_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});

mapping *whip_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});

mapping *club_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});

int savetopten();
mapping *restore_exp_topten();

int simple_sort( mapping *,string,int,object );
int simple_sort_skill( mapping *,string,int,object );


int create()
{
        set_name("����", ({ "ldtx-board","board"}) );
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        set("long", "");
        set("unit", "��");
        set("value", 0);
        setup();

        if( restore() )
        {
                exp_topten=query("exp_topten");
                richman_topten=query("richman_topten");
                oldman_topten=query("oldman_topten");
                thief_topten=query("thief_topten");
                force_topten=query("force_topten");
                pks_topten=query("pks_topten");
                literate_topten=query("literate_topten");
                axe_topten=query("axe_topten");
                blade_topten=query("blade_topten");
                throwing_topten=query("throwing_topten");
                whip_topten=query("whip_topten");
                staff_topten=query("staff_topten");
                hammer_topten=query("hammer_topten");
                sword_topten=query("sword_topten");
                unarmed_topten=query("unarmed_topten");
                dodge_topten=query("dodge_topten");
                fork_topten=query("fork_topten");
                club_topten=query("club_topten");
        }
        return 1;
}

string query_save_file() { return TOPTEN; }

int savetopten()
{
        object me, *user;
        int i;
        user = users();
        for(i=0; i<sizeof(user); i++) {
                me = user[i];
                if ( wiz_level(me) > 0 ) continue;

                simple_sort( exp_topten,"combat_exp",10,me );
                simple_sort( richman_topten,"balance",10,me );
                simple_sort( oldman_topten,"mud_age",10,me );
                simple_sort( force_topten,"max_neili",5,me );
                simple_sort( pks_topten,"PKS",5,me );
                simple_sort_skill( thief_topten,"stealing",3,me );
                simple_sort_skill( literate_topten,"literate",5,me );
                simple_sort_skill( axe_topten,"axe",3,me );
                simple_sort_skill( blade_topten,"blade",3,me );
                simple_sort_skill( throwing_topten,"throwing",3,me );
                simple_sort_skill( whip_topten,"whip",3,me );
                simple_sort_skill( staff_topten,"staff",3,me );
                simple_sort_skill( hammer_topten,"hammer",3,me );
                simple_sort_skill( sword_topten,"sword",3,me );
                simple_sort_skill( unarmed_topten,"unarmed",5,me );
                simple_sort_skill( dodge_topten,"dodge",5,me );
                simple_sort_skill( club_topten,"club",3,me );

                set("exp_topten",exp_topten);
                set("richman_topten",richman_topten);
                set("oldman_topten",oldman_topten);
                set("thief_topten",thief_topten );
                set("force_topten",force_topten );
                set("pks_topten",pks_topten );
                set("literate_topten",literate_topten );
                set("axe_topten",axe_topten );
                set("blade_topten",blade_topten );
                set("throwing_topten",throwing_topten );
                set("whip_topten",whip_topten );
                set("staff_topten",staff_topten );
                set("hammer_topten",hammer_topten );
                set("sword_topten",sword_topten );
                set("unarmed_topten",unarmed_topten );
                set("dodge_topten",dodge_topten );
                set("fork_topten",fork_topten );
                set("club_topten",club_topten );
                save();
        }
        return 1;
}

int simple_sort( mapping *which_chart,string chart_type,int chart_size,object me )
{
        int i,exist;
        string *c_id=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});
        string *c_short=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});
        int *c_type=({11,10,9,8,7,6,5,4,3,2,1,0});
        string si;

        si="����";
        c_id[chart_size] = me->query("id");
        c_short[chart_size] = RANK_D->query_rank(me)+me->short(1);
        c_type[chart_size] = me->query(chart_type);
        exist = 0;
        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf("��%d��",i+1 );
                sscanf( which_chart[i][si],"%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
                if( c_id[i] == c_id[chart_size] )
                {
                        c_short[i] = c_short[chart_size];
                        c_type[i]  = c_type[chart_size] ;
                        exist = 1;
                        continue;
                }
//              if( !(FINGER_D->acquire_login_ob(c_id[i])) )
//                      c_type[i]= 0;
        }


        for( i = 0; i < chart_size - exist; i++ )
        {
                if( c_type[i] < c_type[i+1] )
                {
                        c_id[chart_size+1]    = c_id[i];
                        c_short[chart_size+1] = c_short[i];
                        c_type[chart_size+1]  = c_type[i];
                        c_id[i]    = c_id[i+1];
                        c_short[i] = c_short[i+1];
                        c_type[i]  = c_type[i+1];
                        c_id[i+1]    = c_id[chart_size+1];
                        c_short[i+1] = c_short[chart_size+1];
                        c_type[i+1]  = c_type[chart_size+1];
                }

        }

        for( i = chart_size - exist; i > 0; i-- )
                if( c_type[i] > c_type[i-1] )
                {
                        c_id[chart_size+1]    = c_id[i-1];
                        c_short[chart_size+1] = c_short[i-1];
                        c_type[chart_size+1]  = c_type[i-1];
                        c_id[i-1]    = c_id[i];
                        c_short[i-1] = c_short[i];
                        c_type[i-1]  = c_type[i];
                        c_id[i]    = c_id[chart_size+1];
                        c_short[i] = c_short[chart_size+1];
                        c_type[i]  = c_type[chart_size+1];
                }

        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf( "��%d��",i+1 );
                which_chart[i][si]=sprintf( "%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
        }

        return 1;
}

int simple_sort_skill( mapping *which_chart,string chart_type,int chart_size,object me )
{
        int i,exist;
        string *c_id=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});
        string *c_short=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});
        int *c_type=({11,10,9,8,7,6,5,4,3,2,1,0});
        string si;

        si="����";
        c_id[chart_size] = me->query("id");
        c_short[chart_size] = RANK_D->query_rank(me)+me->short(1);
        c_type[chart_size] = me->query_skill(chart_type);
        exist = 0;
        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf("��%d��",i+1 );
                sscanf( which_chart[i][si],"%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
                if( c_id[i] == c_id[chart_size] )
                {
                        c_short[i] = c_short[chart_size];
                        c_type[i]  = c_type[chart_size] ;
                        exist = 1;
                        continue;
                }
//              if( !(FINGER_D->acquire_login_ob(c_id[i])) )
//                      c_type[i]= 0;
        }


        for( i = 0; i < chart_size - exist; i++ )
        {
                if( c_type[i] < c_type[i+1] )
                {
                        c_id[chart_size+1]    = c_id[i];
                        c_short[chart_size+1] = c_short[i];
                        c_type[chart_size+1]  = c_type[i];
                        c_id[i]    = c_id[i+1];
                        c_short[i] = c_short[i+1];
                        c_type[i]  = c_type[i+1];
                        c_id[i+1]    = c_id[chart_size+1];
                        c_short[i+1] = c_short[chart_size+1];
                        c_type[i+1]  = c_type[chart_size+1];
                }

        }

        for( i = chart_size - exist; i > 0; i-- )
                if( c_type[i] > c_type[i-1] )
                {
                        c_id[chart_size+1]    = c_id[i-1];
                        c_short[chart_size+1] = c_short[i-1];
                        c_type[chart_size+1]  = c_type[i-1];
                        c_id[i-1]    = c_id[i];
                        c_short[i-1] = c_short[i];
                        c_type[i-1]  = c_type[i];
                        c_id[i]    = c_id[chart_size+1];
                        c_short[i] = c_short[chart_size+1];
                        c_type[i]  = c_type[chart_size+1];
                }

        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf( "��%d��",i+1 );
                which_chart[i][si]=sprintf( "%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
        }

        return 1;

}

int movein(object me)
{
        move_object(me);
        return 1;
}

