/*************************************************************************
    > File Name: student.c
    > Author: HuiProgramer
    > Mail: 1712817197@qq.com 
    > Created Time: 2017��12��25�� ����һ 17ʱ29��18��
    > Revision Time: 2018��1��2�� ���ڶ� 14ʱ50��35�� 
 ************************************************************************/
/*��list.h,display.c,list.c,show.c,inputstudent.c,file.c,delete.c,revision.c,search.cһ�����*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h> 
#include"list.h"/*����List��Item */
char * s_gets(char *st,int n);
List pstudent;
Item temp;
char a[6][51] = {"            1>���ѧ����Ϣ                        ",
	"            2>ɾ��ѧ����Ϣ                        ",
	"            3>�޸�ѧ����Ϣ                        ",
	"            4>��ѯѧ����Ϣ                        ",
	"            5>��ʾ����ѧ����Ϣ�Լ�ͳ�����        ",
	"            0>�˳����                            "};
char data[45];
int decide; 
unsigned int  count = 0;
int main(void)
{
	system("mode con cols=100 lines=32");//���ô��ڴ�С 
	/* ��ʼ��*/
	MessageBox(NULL,"��ʼ��ʼ��","��ʾ",MB_OK);
	InitializeList(&pstudent);
	int i = 0,j;
	int ch;
	system("color 05");
	display();
	file();
	a[i][10] = 16;
	a[i][11] = 16;
	UI();
	decide = MessageBox(NULL,"����������ܣ�","��ʾ",MB_OKCANCEL);
	if (decide == IDOK)
	{
		MessageBox(NULL,"���ܽ��ܣ�\n�����·����ѡ��\nEnter��ȷ������","����",MB_ICONQUESTION);
	}
	while(ch = getch())
	{
		switch(ch)
		{
			case 0xE0:
				switch(ch = getch())
				{
					case 72:
						if (i <= 5 && i > 0)
							--i;
						if(i <= 5 && i >= 0)
						{
							for(j = 0;j <= 5;j ++)
							{
								a[j][10] = ' ';
								a[j][11] = ' ';
							}
							a[i][10] = 16;
							a[i][11] = 16;
						}
						
						break;
					case 80:
						if (i < 5 && i >= 0)
							++i;
						if(i <= 5 && i >= 0)
						{
							for(j = 0;j <= 5;j ++)
							{
								a[j][10] = ' ';
								a[j][11] = ' ';
							}
							a[i][10] = 16;
							a[i][11] = 16;
						}
						break;
					case 75:
						
						break;
					case 77:
						
					default :
						break;
				}
				break;
			case 13:
				if (a[0][10] == 16)
				{
				decide = MessageBox(NULL,"�Ƿ�������ѧ����Ϣ��","���ѧ����Ϣ",MB_YESNO);
						if (decide == IDYES)
						inputstudent();
				}
				else if (a[1][10] == 16)
				{
					decide = MessageBox(NULL,"�Ƿ����ѧ����Ϣɾ����","ɾ����Ϣ",MB_YESNO);
						if (decide == IDYES)
						delete();
				}
				else if (a[2][10] == 16)
				{
					decide = MessageBox(NULL,"�Ƿ����ѧ����Ϣ�޸ģ�","�޸���Ϣ",MB_YESNO);
						if (decide == IDYES)
						revision();
				}
				else if (a[3][10] == 16)
				{
					decide = MessageBox(NULL,"�Ƿ����ѧ����Ϣ��ѯ��","��ѯ��Ϣ",MB_YESNO);
						if (decide == IDYES)
						searchstudent();
				}
				else if (a[4][10] == 16)
				{
					decide = MessageBox(NULL,"�Ƿ��������ѧ����Ϣ��","����ѧ����Ϣ",MB_YESNO);
					if (decide == IDYES)
					loopshow();
				}
				else
				{
					decide = MessageBox(NULL,"�Ƿ��˳������","��ʾ",MB_YESNO);
					if (decide == IDYES)
					{
						EmptyTheList(&pstudent);
						MessageBox(NULL,"��л����ʹ�ã��ټ���","��ʾ",MB_OK);
						system("pause"); 
						return 0;
					}
				}
				break;
				
			default :
				MessageBox(NULL,"��ʹ�����¼�ѡ��\nEnter������","��ʾ",MB_ICONWARNING);
				break;
		}
		system("cls");
		UI(); 
	}
	return 0; 
}
char * s_gets(char *st,int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st,n,stdin);
	if(ret_val)
	{
		find = strchr(st,'\n');//���һ��з�
		if (find)		   //�����ַ����NULL
			*find = '\0';//�ڴ˴�����һ�����ַ�
		else
			while (getchar() != '\n')
				continue;   //���������е�ʣ������
	}
	return ret_val;
}

