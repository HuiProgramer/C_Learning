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
		puts("没有数据");
	else
	{
		puts("\t   \n\t\t\t\t学生信息查询\n\n");
		char se[4][21] = {"\t     1>根据学号查询",
		"\t     2>根据姓名查询", 
		"\t     3>根据成绩查询", 
		"\t     0>返回主菜单"};
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
			  		fputs("请输入该学生学号：",stdout);
							if(scanf("%d",&Id) != 1)
							{
								MessageBox(NULL,"学号输入错误！","提示",MB_OK);
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
			  		fputs("请输入该学生姓名：",stdout);
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
				MessageBox(NULL,"请使用上下键选择\nEnter键进入","提示",MB_ICONWARNING);
				break;
			}
			k = 0;
				system("cls");
				 puts("\n\t\t\t\t学生信息查询\n\n");
				while(k < 4)
				  printf("\t\t%s\n",se+k++);	
		}
	}
	system("pause");
}
void searchofid(const List * plist,int ID)//根据学号搜索学生信息 
{
	Node *pnode = *plist; /*设置链表的开始*/

	while(pnode != NULL)
	{
		if (pnode->item.id == ID)
		{
			puts("\n\t\t\t\t\t学生信息展示\n");
			printf("\t\t\t\t       当前查询学号：%d\n\n\n\n",ID);
			printf("\t\t\t \t      姓名：%s\n\n\n\n",pnode->item.name);
			printf("\t\t\t   数学成绩：%d",pnode->item.math);
			printf("\t\t\t   英语成绩：%d\n\n\n\n",pnode->item.english);
			printf("\t\t\t   政治成绩：%d",pnode->item.politics);
			printf("\t\t \t  计算机导论：%d\n\n\n\n",pnode->item.computer);
			printf("\t\t\t\t      C语言成绩：%d\n\n\n\n",pnode->item.c);
		}
		pnode = pnode->next; /*前进到下一项*/
	}
}
void searchofname(const List * plist,char*NAME,void(*pfun)(Item item))//根据姓名搜索学生信息 
{
	Node *pnode = *plist; /*设置链表的开始*/
	puts("\n\t\t\t\t\t  学生信息展示");
	printf("\t\t\t\t       当前查询姓名：%s\n\n",NAME);
	puts("\t\t    ____________________________________________________________");
	puts("\t\t   丨学号丨 姓名 丨数学丨英语丨政治丨计算机导论丨C 语言丨总成绩丨");
	puts("\t\t    ____________________________________________________________");
	while(pnode != NULL)
	{
		if (strncmp(pnode->item.name,NAME,TSIZE) == 0)
			(*pfun)(pnode->item); 
		pnode = pnode->next; /*前进到下一项*/
	}
}
void searchofach(const List * plist,void(*pfun)(Item item)) //根据各科成绩查询学生信息 
{
	int i = 0,j,k = 0;
	Node *head = *plist;
	Node *pnode = *plist; /*设置链表的开始*/
	int math,english,politics,computer,c;
	int ch;
	system("cls");
	  puts("\n\t\t\t\t\t    成绩查询\n");
	  char ach[6][30] = {"  \t     1>根据数学查询\n",
	                     "  \t     2>根据英语查询\n",
						 "  \t     3>根据政治查询\n",
						 "  \t     4>根据计算机导论查询\n",
						 "  \t     5>根据C语言查询\n",
						 "  \t     0>返回上一级\n"};
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
	  				fputs("请输入数学成绩：",stdout);
	  				if (scanf("%d",&math) != 1 || math < 0 || math > 100)
	  				{
	  					fprintf(stderr,"成绩输入错误\n");
	  					fflush(NULL);
	  					break;
	  				}
	  				fflush(NULL);
	  				system("cls");
	  				puts("\n\t\t\t\t\t  学生信息展示");
					printf("\t\t\t\t       当前查询数学成绩：%d\n\n",math);
					puts("\t\t    ____________________________________________________________");
					puts("\t\t   丨学号丨 姓名 丨数学丨英语丨政治丨计算机导论丨C 语言丨总成绩丨");
					puts("\t\t    ____________________________________________________________");
	  				while(pnode != NULL)
					{
						if (math == pnode->item.math)
							(*pfun)(pnode->item); 
						pnode = pnode->next; /*前进到下一项*/
					}
					pnode = head;
					system("pause");
					break;
	  			}
	  			if (ach[1][6] == 16)
	  			{
	  				fflush(NULL);
	  				fputs("请输入英语成绩：",stdout);
	  				if (scanf("%d",&english) != 1 || english < 0 || english > 100)
	  				{
	  					fprintf(stderr,"成绩输入错误\n");
	  					fflush(NULL);
	  					break;
	  				}
	  				fflush(NULL);
	  				system("cls");
	  				puts("\n\t\t\t\t\t\t    学生信息展示");
					printf("\t\t\t\t \t        当前查询英语成绩：%d\n\n",english);
					puts("\t\t    ____________________________________________________________");
					puts("\t\t   丨学号丨 姓名 丨数学丨英语丨政治丨计算机导论丨C 语言丨总成绩丨");
					puts("\t\t    ____________________________________________________________");
	  				while(pnode != NULL)
					{
						if (english == pnode->item.english)
							(*pfun)(pnode->item); 
						pnode = pnode->next; /*前进到下一项*/
					}
					pnode = head;
					system("pause");
					break;
	  			}
	  			if (ach[2][6] == 16)
	  			{
	  				fflush(NULL);
	  				fputs("请输入政治成绩：",stdout);
	  				if (scanf("%d",&politics) != 1 || politics < 0 || politics > 100)
	  				{
	  					fprintf(stderr,"成绩输入错误\n");
	  					fflush(NULL);
	  					break;
	  				}
	  				fflush(NULL);
	  				system("cls");
	  				puts("\n\t\t\t\t\t  学生信息展示");
					printf("\t\t\t\t       当前查询政治成绩：%d\n\n",politics);
					puts("\t \t  ____________________________________________________________");
					puts("\t\t  丨学号丨 姓名 丨数学丨英语丨政治丨计算机导论丨C 语言丨总成绩丨");
					puts("\t\t   ____________________________________________________________");
	  				while(pnode != NULL)
					{
						if (politics == pnode->item.politics)
							(*pfun)(pnode->item); 
						pnode = pnode->next; /*前进到下一项*/
					}
					pnode = head;
					system("pause");
					break;
	  			}
	  			if (ach[3][6] == 16)
	  			{
	  				fflush(NULL);
	  				fputs("请输入计算机导论成绩：",stdout);
	  				if (scanf("%d",&computer) != 1 || computer < 0 || computer > 100)
	  				{
	  					fprintf(stderr,"成绩输入错误\n");
	  					fflush(NULL);
	  					break;
	  				}
	  				fflush(NULL);
	  				system("cls");
	  				puts("\n\t\t\t\t\t  学生信息展示");
					printf("\t\t\t\t       当前查询计算机导论成绩：%d\n\n",computer);
					puts("\t\t   ____________________________________________________________");
					puts("\t\t  丨学号丨 姓名 丨数学丨英语丨政治丨计算机导论丨C 语言丨总成绩丨");
					puts("\t\t   ____________________________________________________________");
	  				while(pnode != NULL)
					{
						if (computer == pnode->item.computer)
							(*pfun)(pnode->item); 
						pnode = pnode->next; /*前进到下一项*/
					}
					pnode = head;
					system("pause");
					break;
	  			}
	  			if (ach[4][6] == 16)
	  			{
	  				fflush(NULL);
	  				fputs("请输入C语言成绩：",stdout);
	  				if (scanf("%d",&c) != 1 || c < 0 || c > 100)
	  				{
	  					fprintf(stderr,"成绩输入错误\n");
	  					fflush(NULL);
	  					break;
	  				}
	  				fflush(NULL);
	  				system("cls");
	  				puts("\n\t\t\t\t\t  学生信息展示");
					printf("\t\t\t \t      当前查询C语言成绩：%d\n\n",c);
					puts("\t\t   ____________________________________________________________");
					puts("\t\t  丨学号丨 姓名 丨数学丨英语丨政治丨计算机导论丨C 语言丨总成绩丨");
					puts("\t \t  ____________________________________________________________");
	  				while(pnode != NULL)
					{
						if (c == pnode->item.c)
							(*pfun)(pnode->item); 
						pnode = pnode->next; /*前进到下一项*/
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
  		puts("\n\t\t\t\t\t    成绩查询\n");
		while(k < 6)
		  printf("\t%s\n",ach + k ++);
	  }
}
