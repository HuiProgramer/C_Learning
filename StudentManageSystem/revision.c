#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include"list.h"
void revision(void)//��Ϣ�޸� 
{
	FILE *fp;
	int i = 0,j,k = 0,Id;
	int ch;
	char NAME[TSIZE];
	system("cls");
	if((fp = fopen(data,"wb+")) == NULL)
	{
		printf("���ܴ��ļ�%s\n",data);
		exit(EXIT_FAILURE);
	}
	if (ListIsEmpty(&pstudent))
		puts("û������");
	else
	{
		puts("\n\t\t\t\t\t   ѧ����Ϣ�޸�\n\n");
		char re[3][23] = {"  \t     1>����ѧ���޸�",
		"  \t     2>���������޸�", 
		"  \t     0>�������˵�"};
		re[i][6] = 16;
		re[i][7] = 16;
		while (k < 3)
		printf("\t\t%s\n",re+k++);
		while (ch = getch())
		{
			switch(ch)
			{
				case 0xE0:
					switch(ch = getch())
					{
						case 72:
							if (i <= 2 && i > 0)
						   --i;
						   for(j = 0;j <= 3;j++)
						   {
						   	re[j][6] = ' ';
						   	re[j][7] = ' ';
						   }
						   re[i][6] = 16;
						   re[i][7] = 16;
							break;
						case 80:
						   if (i < 2 && i >= 0)
						     ++i;
						   for(j = 0;j <= 3;j++)
						   {
						   	re[j][6] = ' ';
						   	re[j][7] = ' ';
						   }
						   re[i][6] = 16;
						   re[i][7] = 16;
						   break;
						default:
							break;
				    }
				    break;
				case 13:
					if (re[0][6] == 16)
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
								printf("%p",pstudent);
								pstudent = revisionofid(&pstudent,Id);
								printf("%p",pstudent);
								system("pause");
								fflush(NULL);
								break;
				  	}
				  	if (re[1][6] == 16)
				  	{
				  		fflush(NULL);
				  		fputs("�������ѧ��������",stdout);
							   s_gets(NAME,TSIZE);
							   system("cls");
							   printf("%p",pstudent);
							   pstudent = revisionofname(&pstudent,NAME);
							   printf("%p",pstudent);
							   system("pause");
							   fflush(NULL);
							   break;
				  	}
				  	if (re[2][6] == 16)
					{
						if (fwrite(&count,sizeof(unsigned int),1,fp) != 1)
						fprintf(stderr,"����д��ʧ��\n");
						Node *pnode = NULL;
						pnode = pstudent;
						while(pnode != NULL)
						{
							if (1 != fwrite(&(pnode->item),sizeof(Item),1,fp))
							fprintf(stderr,"����д��ʧ��\n");
							pnode =pnode->next;  /*�ҵ������ĩβ*/
						}	
						if (fclose(fp) != 0)
						{
							fprintf(stderr,"�ļ��ر�ʧ�ܣ�\n�ټ���\n");
							exit(EXIT_FAILURE);
						}
						return;
					}
			 	default :
			 		MessageBox(NULL,"��ʹ�����¼�ѡ��\nEnter������","��ʾ",MB_ICONWARNING);
					break;
				}
			k = 0;
				system("cls");
				 puts("\n\t\t\t\t\t   ѧ����Ϣ�޸�\n\n");
				while(k < 3)
				  printf("\t\t%s\n",re+k++);	
		}
	}
	system("pause");
}
Node * revisionofid(List * plist,int ID)//����ѧ���޸�ѧ����Ϣ 
{
	int i = 0,j,k = 0;
	int ch,id,math,english,politics,computer,c;
	char name[TSIZE];
	printf("fp = %p\n",*plist);
	Node *pnode = *plist;
	Node * pt = (*plist);
	while(pnode != NULL)
	{
		printf("fp = %p\n",pnode);
		printf("pnode->item.name = %s\n",pnode->item.name);
		if (pnode->item.id == ID) /*�Ѻ���Ӧ���������е��� */
		{
			puts("\n\t\t\t\t\t  ѧ����Ϣ�޸�");
			printf("\t\t\t\t\t  ��ǰѧ�ţ�%d\n\n",ID);
			char re[8][27] ={"  \t  1>�޸�����",
			"  \t  2>�޸�ѧ��", 
			"  \t  3>�޸���ѧ�ɼ�",
			"  \t  4>�޸�Ӣ��ɼ�",
			"  \t  5>�޸����γɼ�",
			"  \t  6>�޸ļ�������۳ɼ�",
			"  \t  7>�޸�C���Գɼ�",
			"  \t  0>������һ��"};
			re[i][3] = 16;
			re[i][4] = 16;
			while(k < 8)
			printf("\t%s\n",re+k++);
			while (ch = getch())
			{
				switch(ch)
				{
					case 0xE0:
						switch(ch = getch())
						{
							case 72:
								if (i <= 7 && i > 0)
								--i;
								for (j = 0;j < 8;j ++)
								{
									re[j][3] = ' ';
									re[j][4] = ' ';
								}
								re[i][3] = 16;
								re[i][4] = 16;
								break;
							case 80:
								if (i < 7 && i >= 0)
								++i;
								for (j = 0;j < 8; j ++)
								{
									re[j][3] = ' ';
									re[j][4] = ' ';
								}
								re[i][3] = 16;
								re[i][4] = 16;
								break;
						}
						break;
					case 13:
						if (re[0][3] == 16)
						{
							fputs("������Ҫ�޸ĵ�������",stdout);
							getchar();
							s_gets(name,TSIZE);
							strncpy(pnode->item.name,name,TSIZE);
							MessageBox(NULL,"�޸������ɹ���","��ʾ",MB_OK);
							break;
						}
						if (re[1][3] == 16)
						{
							fputs("������Ҫ�޸ĵ�ѧ�ţ�",stdout);
							if(scanf("%d",&id) != 1 || idcompare(&pt,id))
							{
								puts("ѧ���������");
								fflush(NULL);
								break;
							}
							fflush(NULL);
							pnode->item.id = id;
							MessageBox(NULL,"�޸�ѧ�ųɹ���","��ʾ",MB_OK);
							break;
						}
						if (re[2][3] == 16)
						{
							fputs("������Ҫ�޸ĵ���ѧ�ɼ���",stdout);
							if (scanf("%d",&math) != 1 || math > 100  || math < 0 )
							{
							   	fputs("�ɼ��������!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.math = math;
					        MessageBox(NULL,"�޸���ѧ�ɼ��ɹ���","��ʾ",MB_OK);
					        break;
					    }
					    if (re[3][3] == 16)
					    {
					    	fputs("��������Ҫ�޸ĵ�Ӣ��ɼ���",stdout);
					    	if (scanf("%d",&english) != 1 || english > 100  || english < 0 )
							{
							   	fputs("�ɼ��������!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.english = english;
					        MessageBox(NULL,"�޸�Ӣ��ɼ��ɹ���","��ʾ",MB_OK);
					        break;
					    }
					    if (re[4][3] == 16)
					    {
					    	fputs("��������Ҫ�޸ĵ����γɼ���",stdout);
					    	if (scanf("%d",&politics) != 1 || politics > 100  || politics < 0 )
							{
							   	fputs("�ɼ��������!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.politics = politics;
					        MessageBox(NULL,"�޸����γɼ��ɹ���","��ʾ",MB_OK);
					        break;
					    }
					    if (re[5][3] == 16)
					    {
					    	fputs("��������Ҫ�޸ĵļ�������۳ɼ���",stdout);
					    	if (scanf("%d",&computer) != 1 || computer > 100  || computer < 0 )
							{
							   	fputs("�ɼ��������!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.computer = computer;
					        MessageBox(NULL,"�޸ļ�������۳ɼ��ɹ���","��ʾ",MB_OK);
					        break;
						}
					    if (re[6][3] == 16)
					    {
					    	fputs("��������Ҫ�޸ĵ�C���Գɼ���",stdout);
					    	if (scanf("%d",&c) != 1 || c > 100  || c < 0 )
							{
							   	fputs("�ɼ��������!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.c = c;
					        MessageBox(NULL,"�޸�C���Գɼ��ɹ���","��ʾ",MB_OK);
							break;
						}
						if (re[7][3] == 16)
						return pt;
						default :
						MessageBox(NULL,"��ʹ�����¼�ѡ��\nEnter������","��ʾ",MB_ICONWARNING); 
						break;
				}
				k = 0;
				system("cls");
				puts("\n\t\t\t\t\t  ѧ����Ϣ�޸�");
			printf("\t\t\t\t\t  ��ǰѧ�ţ�%d\n\n",ID);
				while (k < 8)
				printf("\t%s\n",re+k++);
			}
		}
		pnode = pnode->next; /*ǰ������һ��*/
	}	
	MessageBox(NULL,"û�и�ѧ��","��ʾ",MB_OK);
	return pt;
}

Node * revisionofname(List * plist,char *NAME)//���������޸�ѧ����Ϣ 
{
	int i = 0,j,k = 0;
	int ch,id,math,english,politics,computer,c;
	char name[TSIZE];
	printf("fp = %p\n",*plist);
	Node *pnode = *plist;
	Node * pt = (*plist);
	while(pnode != NULL)
	{
			printf("fp = %p\n",pnode);
		printf("pnode->item.name = %s\n",pnode->item.name);
		printf("NAME=%s",NAME);
		if (strncmp(pnode->item.name,NAME,TSIZE) == 0)/*�Ѻ���Ӧ���������е��� */
		{
			puts("\n\t\t\t\t\t  ѧ����Ϣ�޸�");
			printf("\t\t\t\t         ��ǰѧ��������%s\n\n",NAME);
			char re[8][27] ={"  \t  1>�޸�����",
			"  \t  2>�޸�ѧ��", 
			"  \t  3>�޸���ѧ�ɼ�",
			"  \t  4>�޸�Ӣ��ɼ�",
			"  \t  5>�޸����γɼ�",
			"  \t  6>�޸ļ�������۳ɼ�",
			"  \t  7>�޸�C���Գɼ�",
			"  \t  0>������һ��"};
			re[i][4] = 16;
			re[i][3] = 16;
			while(k < 8)
			printf("\t%s\n",re+k++);
			while (ch = getch())
			{
				switch(ch)
				{
					case 0xE0:
						switch(ch = getch())
						{
							case 72:
								if (i <= 7 && i > 0)
								--i;
								for (j = 0;j < 8;j ++)
								{
									re[j][3] = ' ';
									re[j][4] = ' ';
								}
								re[i][3] = 16;
								re[i][4] = 16;
								break;
							case 80:
								if (i < 7 && i >= 0)
								++i;
								for (j = 0;j < 8; j ++)
								{
									re[j][3] = ' ';
									re[j][4] = ' ';
								}
								re[i][3] = 16;
								re[i][4] = 16;
								break;
						}
						break;
					case 13:
						if (re[0][3] == 16)
						{
							fputs("������Ҫ�޸ĵ�������",stdout);
							getchar();
							s_gets(name,TSIZE);
							fflush(NULL);
							strncpy(pnode->item.name,name,TSIZE);
							MessageBox(NULL,"�޸������ɹ���","��ʾ",MB_OK);
							break;
						}
						if (re[1][3] == 16)
						{
							fputs("������Ҫ�޸ĵ�ѧ�ţ�",stdout);
							if(scanf("%d",&id) != 1 || idcompare(&pt,id))
							{
								puts("ѧ���������");
								fflush(NULL);
								break;
							}
							fflush(NULL);
							pnode->item.id = id;
							MessageBox(NULL,"�޸�ѧ�ųɹ���","��ʾ",MB_OK);
							break;
						}
						if (re[2][3] == 16)
						{
							fputs("������Ҫ�޸ĵ���ѧ�ɼ���",stdout);
							if (scanf("%d",&math) != 1 || math > 100  || math < 0 )
							{
							   	fputs("�ɼ��������!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.math = math;
					        MessageBox(NULL,"�޸���ѧ�ɼ��ɹ���","��ʾ",MB_OK);
					        break;
					    }
					    if (re[3][3] == 16)
					    {
					    	fputs("��������Ҫ�޸ĵ�Ӣ��ɼ���",stdout);
					    	if (scanf("%d",&english) != 1 || english > 100  || english < 0 )
							{
							   	fputs("�ɼ��������!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.english = english;
					        MessageBox(NULL,"�޸�Ӣ��ɼ��ɹ���","��ʾ",MB_OK);
					        break;
					    }
					    if (re[4][3] == 16)
					    {
					    	fputs("��������Ҫ�޸ĵ����γɼ���",stdout);
					    	if (scanf("%d",&politics) != 1 || politics > 100  || politics < 0 )
							{
							   	fputs("�ɼ��������!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.politics = politics;
					        MessageBox(NULL,"�޸����γɼ��ɹ���","��ʾ",MB_OK);
					        break;
					    }
					    if (re[5][3] == 16)
					    {
					    	fputs("��������Ҫ�޸ĵļ�������۳ɼ���",stdout);
					    	if (scanf("%d",&computer) != 1 || computer > 100  || computer < 0 )
							{
							   	fputs("�ɼ��������!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.computer = computer;
					        MessageBox(NULL,"�޸ļ�������۳ɼ��ɹ���","��ʾ",MB_OK);
					        break;
						}
					    if (re[6][3] == 16)
					    {
					    	fputs("��������Ҫ�޸ĵ�C���Գɼ���",stdout);
					    	if (scanf("%d",&c) != 1 || c > 100  || c < 0 )
							{
							   	fputs("�ɼ��������!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.c = c;
					        MessageBox(NULL,"�޸�C���Գɼ��ɹ���","��ʾ",MB_OK);
							break;
						}
						if (re[7][3] == 16)
						return pt;
						default :
						MessageBox(NULL,"��ʹ�����¼�ѡ��\nEnter������","��ʾ",MB_ICONWARNING);
						break;
				}
				k = 0;
				system("cls");
				puts("\n\t\t\t\t\t  ѧ����Ϣ�޸�");
			printf("\t\t\t\t         ��ǰѧ��������%s\n\n",NAME);
				while (k < 8)
				printf("\t%s\n",re+k++);
			}
		}
		pnode = pnode->next; /*ǰ������һ��*/
	}	
	MessageBox(NULL,"û�и�ѧ��","��ʾ",MB_OK);
	return pt;
}
