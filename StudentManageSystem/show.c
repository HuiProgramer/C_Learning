#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"
void loopshow(void)
{
	system("cls");
	/* ��ʾ */
	if (ListIsEmpty(&pstudent))
		puts("û������");
	else
	{
		puts("\n\t\t\t\t\t    ѧ������");
		puts("\t\t    ____________________________________________________________");
		puts("\t\t   حѧ��ح ���� ح��ѧحӢ��ح����ح���������حC ����ح�ܳɼ�ح");
		puts("\t\t    ____________________________________________________________");
		Traverse(&pstudent,showstudent);
		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	system("pause");

}
void showstudent(Item item)
{
	printf("\t\t   ح %2d ح%6sح%3d ح%3d ح%3d ح   %3d    ح  %3d ح %4d ح\n",item.id,item.name,item.math,  \
		item.english,item.politics,item.computer,item.c,item.math+item.c+item.computer+item.english+item.politics);
	puts("\t\t    ____________________________________________________________");

}

void UI(void) 
{
	int i = 0;
    puts("\t\t\t ____________________________________________________");
	fputs("\t\t\tح                 ",stdout);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	fputs("ѧ����Ϣ����ϵͳ",stdout);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	puts("                 ح ");
	printf("\t\t\tح                     %s                    ح\n",data);
	printf("\t\t\tح                    ѧ������:%d                    ح\n",count);
	puts("\t\t\tح                                                  ح");
	puts("\t\t\tح                                                  ح");
	while(i<6)
        printf("\t\t\tح%sح\n",a+i++);
	fputs("\t\t\tح            ",stdout);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	fputs("Author:HuiProgramer",stdout);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	puts("                   ح"); 
	puts("\t\t\t ����������������������������������������������������");
}
