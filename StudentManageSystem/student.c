/*************************************************************************
    > File Name: student.c
    > Author: HuiProgramer
    > Mail: 1712817197@qq.com 
    > Created Time: 2017年12月25日 星期一 17时29分18秒
    > Revision Time: 2018年1月2日 星期二 14时50分35秒 
 ************************************************************************/
/*与list.h,display.c,list.c,show.c,inputstudent.c,file.c,delete.c,revision.c,search.c一起编译*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h> 
#include"list.h"/*定义List、Item */
char * s_gets(char *st,int n);
List pstudent;
Item temp;
char a[6][51] = {"            1>添加学生信息                        ",
	"            2>删除学生信息                        ",
	"            3>修改学生信息                        ",
	"            4>查询学生信息                        ",
	"            5>显示所以学生信息以及统计情况        ",
	"            0>退出软件                            "};
char data[45];
int decide; 
unsigned int  count = 0;
int main(void)
{
	system("mode con cols=100 lines=32");//设置窗口大小 
	/* 初始化*/
	MessageBox(NULL,"开始初始化","提示",MB_OK);
	InitializeList(&pstudent);
	int i = 0,j;
	int ch;
	system("color 05");
	display();
	file();
	a[i][10] = 16;
	a[i][11] = 16;
	UI();
	decide = MessageBox(NULL,"进入操作介绍？","提示",MB_OKCANCEL);
	if (decide == IDOK)
	{
		MessageBox(NULL,"功能介绍：\n按上下方向键选择\nEnter键确定进入","介绍",MB_ICONQUESTION);
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
				decide = MessageBox(NULL,"是否进入添加学生信息？","添加学生信息",MB_YESNO);
						if (decide == IDYES)
						inputstudent();
				}
				else if (a[1][10] == 16)
				{
					decide = MessageBox(NULL,"是否进入学生信息删除？","删除信息",MB_YESNO);
						if (decide == IDYES)
						delete();
				}
				else if (a[2][10] == 16)
				{
					decide = MessageBox(NULL,"是否进入学生信息修改？","修改信息",MB_YESNO);
						if (decide == IDYES)
						revision();
				}
				else if (a[3][10] == 16)
				{
					decide = MessageBox(NULL,"是否进入学生信息查询？","查询信息",MB_YESNO);
						if (decide == IDYES)
						searchstudent();
				}
				else if (a[4][10] == 16)
				{
					decide = MessageBox(NULL,"是否进入已有学生信息？","已有学生信息",MB_YESNO);
					if (decide == IDYES)
					loopshow();
				}
				else
				{
					decide = MessageBox(NULL,"是否退出软件？","提示",MB_YESNO);
					if (decide == IDYES)
					{
						EmptyTheList(&pstudent);
						MessageBox(NULL,"感谢您的使用，再见！","提示",MB_OK);
						system("pause"); 
						return 0;
					}
				}
				break;
				
			default :
				MessageBox(NULL,"请使用上下键选择\nEnter键进入","提示",MB_ICONWARNING);
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
		find = strchr(st,'\n');//查找换行符
		if (find)		   //如果地址不是NULL
			*find = '\0';//在此处放置一个空字符
		else
			while (getchar() != '\n')
				continue;   //处理输入行的剩余内容
	}
	return ret_val;
}

