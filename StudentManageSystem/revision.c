#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include"list.h"
void revision(void)//信息修改 
{
	FILE *fp;
	int i = 0,j,k = 0,Id;
	int ch;
	char NAME[TSIZE];
	system("cls");
	if((fp = fopen(data,"wb+")) == NULL)
	{
		printf("不能打开文件%s\n",data);
		exit(EXIT_FAILURE);
	}
	if (ListIsEmpty(&pstudent))
		puts("没有数据");
	else
	{
		puts("\n\t\t\t\t\t   学生信息修改\n\n");
		char re[3][23] = {"  \t     1>根据学号修改",
		"  \t     2>根据姓名修改", 
		"  \t     0>返回主菜单"};
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
				  		fputs("请输入该学生学号：",stdout);
								if(scanf("%d",&Id) != 1)
								{
									MessageBox(NULL,"学号输入错误！","提示",MB_OK);
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
				  		fputs("请输入该学生姓名：",stdout);
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
						fprintf(stderr,"本次写入失败\n");
						Node *pnode = NULL;
						pnode = pstudent;
						while(pnode != NULL)
						{
							if (1 != fwrite(&(pnode->item),sizeof(Item),1,fp))
							fprintf(stderr,"本次写入失败\n");
							pnode =pnode->next;  /*找到链表的末尾*/
						}	
						if (fclose(fp) != 0)
						{
							fprintf(stderr,"文件关闭失败！\n再见！\n");
							exit(EXIT_FAILURE);
						}
						return;
					}
			 	default :
			 		MessageBox(NULL,"请使用上下键选择\nEnter键进入","提示",MB_ICONWARNING);
					break;
				}
			k = 0;
				system("cls");
				 puts("\n\t\t\t\t\t   学生信息修改\n\n");
				while(k < 3)
				  printf("\t\t%s\n",re+k++);	
		}
	}
	system("pause");
}
Node * revisionofid(List * plist,int ID)//根据学号修改学生信息 
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
		if (pnode->item.id == ID) /*把函数应用于链表中的项 */
		{
			puts("\n\t\t\t\t\t  学生信息修改");
			printf("\t\t\t\t\t  当前学号：%d\n\n",ID);
			char re[8][27] ={"  \t  1>修改姓名",
			"  \t  2>修改学号", 
			"  \t  3>修改数学成绩",
			"  \t  4>修改英语成绩",
			"  \t  5>修改政治成绩",
			"  \t  6>修改计算机导论成绩",
			"  \t  7>修改C语言成绩",
			"  \t  0>返回上一级"};
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
							fputs("请输入要修改的姓名：",stdout);
							getchar();
							s_gets(name,TSIZE);
							strncpy(pnode->item.name,name,TSIZE);
							MessageBox(NULL,"修改姓名成功！","提示",MB_OK);
							break;
						}
						if (re[1][3] == 16)
						{
							fputs("请输入要修改的学号：",stdout);
							if(scanf("%d",&id) != 1 || idcompare(&pt,id))
							{
								puts("学号输入错误！");
								fflush(NULL);
								break;
							}
							fflush(NULL);
							pnode->item.id = id;
							MessageBox(NULL,"修改学号成功！","提示",MB_OK);
							break;
						}
						if (re[2][3] == 16)
						{
							fputs("请输入要修改的数学成绩：",stdout);
							if (scanf("%d",&math) != 1 || math > 100  || math < 0 )
							{
							   	fputs("成绩输入错误!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.math = math;
					        MessageBox(NULL,"修改数学成绩成功！","提示",MB_OK);
					        break;
					    }
					    if (re[3][3] == 16)
					    {
					    	fputs("请输入你要修改的英语成绩：",stdout);
					    	if (scanf("%d",&english) != 1 || english > 100  || english < 0 )
							{
							   	fputs("成绩输入错误!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.english = english;
					        MessageBox(NULL,"修改英语成绩成功！","提示",MB_OK);
					        break;
					    }
					    if (re[4][3] == 16)
					    {
					    	fputs("请输入你要修改的政治成绩：",stdout);
					    	if (scanf("%d",&politics) != 1 || politics > 100  || politics < 0 )
							{
							   	fputs("成绩输入错误!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.politics = politics;
					        MessageBox(NULL,"修改政治成绩成功！","提示",MB_OK);
					        break;
					    }
					    if (re[5][3] == 16)
					    {
					    	fputs("请输入你要修改的计算机导论成绩：",stdout);
					    	if (scanf("%d",&computer) != 1 || computer > 100  || computer < 0 )
							{
							   	fputs("成绩输入错误!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.computer = computer;
					        MessageBox(NULL,"修改计算机导论成绩成功！","提示",MB_OK);
					        break;
						}
					    if (re[6][3] == 16)
					    {
					    	fputs("请输入你要修改的C语言成绩：",stdout);
					    	if (scanf("%d",&c) != 1 || c > 100  || c < 0 )
							{
							   	fputs("成绩输入错误!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.c = c;
					        MessageBox(NULL,"修改C语言成绩成功！","提示",MB_OK);
							break;
						}
						if (re[7][3] == 16)
						return pt;
						default :
						MessageBox(NULL,"请使用上下键选择\nEnter键进入","提示",MB_ICONWARNING); 
						break;
				}
				k = 0;
				system("cls");
				puts("\n\t\t\t\t\t  学生信息修改");
			printf("\t\t\t\t\t  当前学号：%d\n\n",ID);
				while (k < 8)
				printf("\t%s\n",re+k++);
			}
		}
		pnode = pnode->next; /*前进到下一项*/
	}	
	MessageBox(NULL,"没有该学生","提示",MB_OK);
	return pt;
}

Node * revisionofname(List * plist,char *NAME)//根据姓名修改学生信息 
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
		if (strncmp(pnode->item.name,NAME,TSIZE) == 0)/*把函数应用于链表中的项 */
		{
			puts("\n\t\t\t\t\t  学生信息修改");
			printf("\t\t\t\t         当前学生姓名：%s\n\n",NAME);
			char re[8][27] ={"  \t  1>修改姓名",
			"  \t  2>修改学号", 
			"  \t  3>修改数学成绩",
			"  \t  4>修改英语成绩",
			"  \t  5>修改政治成绩",
			"  \t  6>修改计算机导论成绩",
			"  \t  7>修改C语言成绩",
			"  \t  0>返回上一级"};
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
							fputs("请输入要修改的姓名：",stdout);
							getchar();
							s_gets(name,TSIZE);
							fflush(NULL);
							strncpy(pnode->item.name,name,TSIZE);
							MessageBox(NULL,"修改姓名成功！","提示",MB_OK);
							break;
						}
						if (re[1][3] == 16)
						{
							fputs("请输入要修改的学号：",stdout);
							if(scanf("%d",&id) != 1 || idcompare(&pt,id))
							{
								puts("学号输入错误！");
								fflush(NULL);
								break;
							}
							fflush(NULL);
							pnode->item.id = id;
							MessageBox(NULL,"修改学号成功！","提示",MB_OK);
							break;
						}
						if (re[2][3] == 16)
						{
							fputs("请输入要修改的数学成绩：",stdout);
							if (scanf("%d",&math) != 1 || math > 100  || math < 0 )
							{
							   	fputs("成绩输入错误!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.math = math;
					        MessageBox(NULL,"修改数学成绩成功！","提示",MB_OK);
					        break;
					    }
					    if (re[3][3] == 16)
					    {
					    	fputs("请输入你要修改的英语成绩：",stdout);
					    	if (scanf("%d",&english) != 1 || english > 100  || english < 0 )
							{
							   	fputs("成绩输入错误!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.english = english;
					        MessageBox(NULL,"修改英语成绩成功！","提示",MB_OK);
					        break;
					    }
					    if (re[4][3] == 16)
					    {
					    	fputs("请输入你要修改的政治成绩：",stdout);
					    	if (scanf("%d",&politics) != 1 || politics > 100  || politics < 0 )
							{
							   	fputs("成绩输入错误!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.politics = politics;
					        MessageBox(NULL,"修改政治成绩成功！","提示",MB_OK);
					        break;
					    }
					    if (re[5][3] == 16)
					    {
					    	fputs("请输入你要修改的计算机导论成绩：",stdout);
					    	if (scanf("%d",&computer) != 1 || computer > 100  || computer < 0 )
							{
							   	fputs("成绩输入错误!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.computer = computer;
					        MessageBox(NULL,"修改计算机导论成绩成功！","提示",MB_OK);
					        break;
						}
					    if (re[6][3] == 16)
					    {
					    	fputs("请输入你要修改的C语言成绩：",stdout);
					    	if (scanf("%d",&c) != 1 || c > 100  || c < 0 )
							{
							   	fputs("成绩输入错误!",stdout);
							   	fflush(NULL);
							   	break;
					        }
					        fflush(NULL);
					        pnode->item.c = c;
					        MessageBox(NULL,"修改C语言成绩成功！","提示",MB_OK);
							break;
						}
						if (re[7][3] == 16)
						return pt;
						default :
						MessageBox(NULL,"请使用上下键选择\nEnter键进入","提示",MB_ICONWARNING);
						break;
				}
				k = 0;
				system("cls");
				puts("\n\t\t\t\t\t  学生信息修改");
			printf("\t\t\t\t         当前学生姓名：%s\n\n",NAME);
				while (k < 8)
				printf("\t%s\n",re+k++);
			}
		}
		pnode = pnode->next; /*前进到下一项*/
	}	
	MessageBox(NULL,"没有该学生","提示",MB_OK);
	return pt;
}
