#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"
void loopshow(void)
{
	system("cls");
	/* 显示 */
	if (ListIsEmpty(&pstudent))
		puts("没有数据");
	else
	{
		puts("\n\t\t\t\t\t    学生数据");
		puts("\t\t    ____________________________________________________________");
		puts("\t\t   丨学号丨 姓名 丨数学丨英语丨政治丨计算机导论丨C 语言丨总成绩丨");
		puts("\t\t    ____________________________________________________________");
		Traverse(&pstudent,showstudent);
		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	system("pause");

}
void showstudent(Item item)
{
	printf("\t\t   丨 %2d 丨%6s丨%3d 丨%3d 丨%3d 丨   %3d    丨  %3d 丨 %4d 丨\n",item.id,item.name,item.math,  \
		item.english,item.politics,item.computer,item.c,item.math+item.c+item.computer+item.english+item.politics);
	puts("\t\t    ____________________________________________________________");

}

void UI(void) 
{
	int i = 0;
    puts("\t\t\t ____________________________________________________");
	fputs("\t\t\t丨                 ",stdout);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	fputs("学生信息管理系统",stdout);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	puts("                 丨 ");
	printf("\t\t\t丨                     %s                    丨\n",data);
	printf("\t\t\t丨                    学生人数:%d                    丨\n",count);
	puts("\t\t\t丨                                                  丨");
	puts("\t\t\t丨                                                  丨");
	while(i<6)
        printf("\t\t\t丨%s丨\n",a+i++);
	fputs("\t\t\t丨            ",stdout);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	fputs("Author:HuiProgramer",stdout);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	puts("                   丨"); 
	puts("\t\t\t ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ");
}
