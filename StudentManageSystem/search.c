#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include"list.h"
void searchstudent(void)
{
	int i = 0,j,k = 0,Id;
	int ch;
	char NAME[TSIZE];
	system("cls");
	if (ListIsEmpty(&pstudent))
		puts("û������");
	else
	{
		puts("\t   \n\t\t\t\tѧ����Ϣ��ѯ\n\n");
		char se[4][21] = {"\t     1>����ѧ�Ų�ѯ",
		"\t     2>����������ѯ", 
		"\t     3>���ݳɼ���ѯ", 
		"\t     0>�������˵�"};
		se[i][4] = 16;
		se[i][5] = 16;
		while (k < 4)
		printf("\t\t%s\n",se+k++);
		while (ch = getch())
		{
			switch(ch)
			{
				case 0xE0:
					switch(ch = getch())
					{
						case 72:
							if (i <= 3 && i > 0)
						   --i;
						   for(j = 0;j < 4;j++)
						   {
						   	se[j][4] = ' ';
						   	se[j][5] = ' ';
						   }
						   se[i][4] = 16;
						   se[i][5] = 16;
							break;
						case 80:
						   if (i < 3 && i >= 0)
						     ++i;
						   for(j = 0;j < 4;j++)
						   {
						   	se[j][4] = ' ';
						   	se[j][5] = ' ';
						   }
						   se[i][4] = 16;
						   se[i][5] = 16;
						   break;
						default:
							break;
				    }
				    break;
				case 13:
				if (se[0][4] == 16)
			  	{
			  		fflush(NULL);
			  		fputs("�������ѧ��ѧ�ţ�",stdout);
							if(scanf("%d",&Id) != 1)
							{
								MessageBox(NULL,"ѧ���������","��ʾ",MB_OK);
								fflush(NULL);
								break;
							}
							system("cls");
							searchofid(&pstudent,Id);
							fflush(NULL);
							system("pause");
							break;
			  	}
			  	if (se[1][4] == 16)
			  	{
			  		fflush(NULL);
			  		fputs("�������ѧ��������",stdout);
						   getchar();
						   s_gets(NAME,TSIZE);
						   system("cls");
						   searchofname(&pstudent,NAME,showstudent);
						   system("pause");
						   fflush(NULL);
						   break;
			  	}
			  	if (se[2][4] == 16)
			  	{
			  	  searchofach(&pstudent,showstudent);
					break;						  
				  } 
				if (se[3][4] == 16)
					return;
			default :
				MessageBox(NULL,"��ʹ�����¼�ѡ��\nEnter������","��ʾ",MB_ICONWARNING);
				break;
			}
			k = 0;
				system("cls");
				 puts("\n\t\t\t\tѧ����Ϣ��ѯ\n\n");
				while(k < 4)
				  printf("\t\t%s\n",se+k++);	
		}
	}
	system("pause");
}
void searchofid(const List * plist,int ID)//����ѧ������ѧ����Ϣ 
{
	Node *pnode = *plist; /*��������Ŀ�ʼ*/

	while(pnode != NULL)
	{
		if (pnode->item.id == ID)
		{
			puts("\n\t\t\t\t\tѧ����Ϣչʾ\n");
			printf("\t\t\t\t       ��ǰ��ѯѧ�ţ�%d\n\n\n\n",ID);
			printf("\t\t\t \t      ������%s\n\n\n\n",pnode->item.name);
			printf("\t\t\t   ��ѧ�ɼ���%d",pnode->item.math);
			printf("\t\t\t   Ӣ��ɼ���%d\n\n\n\n",pnode->item.english);
			printf("\t\t\t   ���γɼ���%d",pnode->item.politics);
			printf("\t\t \t  ��������ۣ�%d\n\n\n\n",pnode->item.computer);
			printf("\t\t\t\t      C���Գɼ���%d\n\n\n\n",pnode->item.c);
		}
		pnode = pnode->next; /*ǰ������һ��*/
	}
}
void searchofname(const List * plist,char*NAME,void(*pfun)(Item item))//������������ѧ����Ϣ 
{
	Node *pnode = *plist; /*��������Ŀ�ʼ*/
	puts("\n\t\t\t\t\t  ѧ����Ϣչʾ");
	printf("\t\t\t\t       ��ǰ��ѯ������%s\n\n",NAME);
	puts("\t\t    ____________________________________________________________");
	puts("\t\t   حѧ��ح ���� ح��ѧحӢ��ح����ح���������حC ����ح�ܳɼ�ح");
	puts("\t\t    ____________________________________________________________");
	while(pnode != NULL)
	{
		if (strncmp(pnode->item.name,NAME,TSIZE) == 0)
			(*pfun)(pnode->item); 
		pnode = pnode->next; /*ǰ������һ��*/
	}
}
void searchofach(const List * plist,void(*pfun)(Item item)) //���ݸ��Ƴɼ���ѯѧ����Ϣ 
{
	int i = 0,j,k = 0;
	Node *head = *plist;
	Node *pnode = *plist; /*��������Ŀ�ʼ*/
	int math,english,politics,computer,c;
	int ch;
	system("cls");
	  puts("\n\t\t\t\t\t    �ɼ���ѯ\n");
	  char ach[6][30] = {"  \t     1>������ѧ��ѯ\n",
	                     "  \t     2>����Ӣ���ѯ\n",
						 "  \t     3>�������β�ѯ\n",
						 "  \t     4>���ݼ�������۲�ѯ\n",
						 "  \t     5>����C���Բ�ѯ\n",
						 "  \t     0>������һ��\n"};
	ach[i][6] = 16;
	ach[i][7] = 16;
	while(k < 6)
	  printf("\t%s\n",ach + k++);
	  while(ch = getch())
	  {
	  	switch(ch)
	  	{
	  		case 0xE0:
	  			switch(ch = getch())
	  			{
	  				case 72:
	  					if (i <= 5 && i > 0 )
	  					   --i;
	  					for (j = 0;j < 6;j ++)
	  					{
	  						ach[j][6] = ' ';
	  						ach[j][7] = ' ';
	  					}
						ach[i][6] = 16;
						ach[i][7] = 16;
						break;
					case 80:
						if (i < 5 && i >= 0 )
	  					   ++i;
						for (j = 0;j < 6;j ++)
	  					{
	  						ach[j][6] = ' ';
	  						ach[j][7] = ' ';
	  					}
						ach[i][6] = 16;
						ach[i][7] = 16;
						break;
					default :
						break;
	  			}
				  break;
	  		case 13:
	  			if (ach[0][6] == 16)
	  			{
	  				fflush(NULL);
	  				fputs("��������ѧ�ɼ���",stdout);
	  				if (scanf("%d",&math) != 1 || math < 0 || math > 100)
	  				{
	  					fprintf(stderr,"�ɼ��������\n");
	  					fflush(NULL);
	  					break;
	  				}
	  				fflush(NULL);
	  				system("cls");
	  				puts("\n\t\t\t\t\t  ѧ����Ϣչʾ");
					printf("\t\t\t\t       ��ǰ��ѯ��ѧ�ɼ���%d\n\n",math);
					puts("\t\t    ____________________________________________________________");
					puts("\t\t   حѧ��ح ���� ح��ѧحӢ��ح����ح���������حC ����ح�ܳɼ�ح");
					puts("\t\t    ____________________________________________________________");
	  				while(pnode != NULL)
					{
						if (math == pnode->item.math)
							(*pfun)(pnode->item); 
						pnode = pnode->next; /*ǰ������һ��*/
					}
					pnode = head;
					system("pause");
					break;
	  			}
	  			if (ach[1][6] == 16)
	  			{
	  				fflush(NULL);
	  				fputs("������Ӣ��ɼ���",stdout);
	  				if (scanf("%d",&english) != 1 || english < 0 || english > 100)
	  				{
	  					fprintf(stderr,"�ɼ��������\n");
	  					fflush(NULL);
	  					break;
	  				}
	  				fflush(NULL);
	  				system("cls");
	  				puts("\n\t\t\t\t\t\t    ѧ����Ϣչʾ");
					printf("\t\t\t\t \t        ��ǰ��ѯӢ��ɼ���%d\n\n",english);
					puts("\t\t    ____________________________________________________________");
					puts("\t\t   حѧ��ح ���� ح��ѧحӢ��ح����ح���������حC ����ح�ܳɼ�ح");
					puts("\t\t    ____________________________________________________________");
	  				while(pnode != NULL)
					{
						if (english == pnode->item.english)
							(*pfun)(pnode->item); 
						pnode = pnode->next; /*ǰ������һ��*/
					}
					pnode = head;
					system("pause");
					break;
	  			}
	  			if (ach[2][6] == 16)
	  			{
	  				fflush(NULL);
	  				fputs("���������γɼ���",stdout);
	  				if (scanf("%d",&politics) != 1 || politics < 0 || politics > 100)
	  				{
	  					fprintf(stderr,"�ɼ��������\n");
	  					fflush(NULL);
	  					break;
	  				}
	  				fflush(NULL);
	  				system("cls");
	  				puts("\n\t\t\t\t\t  ѧ����Ϣչʾ");
					printf("\t\t\t\t       ��ǰ��ѯ���γɼ���%d\n\n",politics);
					puts("\t \t  ____________________________________________________________");
					puts("\t\t  حѧ��ح ���� ح��ѧحӢ��ح����ح���������حC ����ح�ܳɼ�ح");
					puts("\t\t   ____________________________________________________________");
	  				while(pnode != NULL)
					{
						if (politics == pnode->item.politics)
							(*pfun)(pnode->item); 
						pnode = pnode->next; /*ǰ������һ��*/
					}
					pnode = head;
					system("pause");
					break;
	  			}
	  			if (ach[3][6] == 16)
	  			{
	  				fflush(NULL);
	  				fputs("�������������۳ɼ���",stdout);
	  				if (scanf("%d",&computer) != 1 || computer < 0 || computer > 100)
	  				{
	  					fprintf(stderr,"�ɼ��������\n");
	  					fflush(NULL);
	  					break;
	  				}
	  				fflush(NULL);
	  				system("cls");
	  				puts("\n\t\t\t\t\t  ѧ����Ϣչʾ");
					printf("\t\t\t\t       ��ǰ��ѯ��������۳ɼ���%d\n\n",computer);
					puts("\t\t   ____________________________________________________________");
					puts("\t\t  حѧ��ح ���� ح��ѧحӢ��ح����ح���������حC ����ح�ܳɼ�ح");
					puts("\t\t   ____________________________________________________________");
	  				while(pnode != NULL)
					{
						if (computer == pnode->item.computer)
							(*pfun)(pnode->item); 
						pnode = pnode->next; /*ǰ������һ��*/
					}
					pnode = head;
					system("pause");
					break;
	  			}
	  			if (ach[4][6] == 16)
	  			{
	  				fflush(NULL);
	  				fputs("������C���Գɼ���",stdout);
	  				if (scanf("%d",&c) != 1 || c < 0 || c > 100)
	  				{
	  					fprintf(stderr,"�ɼ��������\n");
	  					fflush(NULL);
	  					break;
	  				}
	  				fflush(NULL);
	  				system("cls");
	  				puts("\n\t\t\t\t\t  ѧ����Ϣչʾ");
					printf("\t\t\t \t      ��ǰ��ѯC���Գɼ���%d\n\n",c);
					puts("\t\t   ____________________________________________________________");
					puts("\t\t  حѧ��ح ���� ح��ѧحӢ��ح����ح���������حC ����ح�ܳɼ�ح");
					puts("\t \t  ____________________________________________________________");
	  				while(pnode != NULL)
					{
						if (c == pnode->item.c)
							(*pfun)(pnode->item); 
						pnode = pnode->next; /*ǰ������һ��*/
					}
					pnode = head;
					system("pause");
					break;
	  			}
	  			if (ach[5][6] == 16)
	  			return;
	  		default :
	  			break;
	  	}
	  	k = 0;
	  	system("cls");
  		puts("\n\t\t\t\t\t    �ɼ���ѯ\n");
		while(k < 6)
		  printf("\t%s\n",ach + k ++);
	  }
}
