#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIC "������ɽ����ͼ��" NOR, ({ "luyou tu", "tu" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long",@LONG         
                        ��        ������
                         |            |
                        �ƺ�  ��ɽ  ɽ��
                          \     |    / \
          ���϶�-С��    ɽ�� ��ɽ ɽ�� ɽ��-ҩ����
                   \     /   \  | /   \
                  С��-С��   ɽ��   СϪ
                                |      |
�߿߾�ͷ                 ���� ����   СϪ
   |                      |     |       \
  �߿�              ����-��԰-��԰     �ٲ�
   |                      |     |        |
�߿��˿�                 ���� С��     ɽ��-ɽ��
   |                            |
 С��-С��-������-����--����--��Ƹ�--����--����-�ŷ�-�﷿
                    |           |            |
             ����-����-����    ���    ����-����-�᷿
                    |           |            |
        ƺ   ����-����-����   ������   ����-����-�᷿      �ؾ�¥
        |           |           |            |            /
      С��-������-����-����-ǧ���ִ��-����-����-������-���Ƹ�
       /            |           |            |
      ƺ     ����-����-����   ��¬��   ����-����-�᷿
                    |           |            |
             ����-����-����   �����   ����-����-�᷿
                                |
                            ǧ���ִ���-������-������
                                         |
                                       ��ˮ��
                                         | 
                                        ʯ��          
                                         |
                     �                ɽ�ŵ�        
                                         |         
                     �           ��Ů��-ɽ��                         
                                     |  
               �����´��  �޷�ɽ  ʯ��                                
                    |        |       |               
         ���̨-�����´���-������-������                
                    |
                  �㳡
                    |
                 �⽣ʯ                                  
                    |
                  ʯ��          
LONG );


		set("value", 50);
		set("material", "paper");
	}
	setup();
}