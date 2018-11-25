#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"list.h" 
void inputstudent(void)
{
	FILE *fp;
	if((fp = fopen(data,"wb+")) == NULL)
	{
		printf("不能打开文件%s\n",data);
		exit(EXIT_FAILURE);
	}
	if (ListIsFull(&pstudent))
	{
		fprintf(stderr,"链表已满，感谢您的使用，再见!\n");
		exit(EXIT_FAILURE);
	}
     /*获取用户输入并储存*/
	fputs("姓名:",stdout);
	while (s_gets(temp.name,TSIZE) != NULL && temp.name[0] != '\0')
	{
		fflush(NULL);
		fputs("学号:",stdout);
		if (scanf("%d",&temp.id) != 1 || idcompare(&pstudent,temp.id) )
		{
			fputs("学号输入错误!",stdout);
			system("cls");
			fflush(NULL);
			break;
        }
        
		fputs("数学:",stdout);
		if (scanf("%d",&temp.math) != 1 || temp.math > 100  || temp.math < 0 )
			{
		    	fputs("成绩输入错误!",stdout);
		    	system("cls");
		    	fflush(NULL);
		    	break;
            }
		
		fputs("政治:",stdout);
		if (scanf("%d",&temp.politics) != 1 || temp.politics > 100 || temp.politics < 0)
				{
		        	fputs("成绩输入错误!",stdout);
		        	system("cls");
		        	fflush(NULL);
		        	break;
                }
		
		fputs("英语:",stdout);
		if (scanf("%d",&temp.english) != 1 || temp.english > 100 || temp.english < 0)
			{
		    	fputs("成绩输入错误!",stdout);
		    	system("cls");
		    	fflush(NULL);
				break;
            }
		
		fputs("计算机导论:",stdout);
		if (scanf("%d",&temp.computer) != 1 || temp.computer > 100 || temp.computer < 0)
				{
					fputs("成绩输入错误!",stdout);
					system("cls");
					fflush(NULL);
					break;
       			 }
		
		fputs("C语言:",stdout);
		if (scanf("%d",&temp.c) != 1 || temp.c > 100 || temp.c < 0)
				{
					fputs("成绩输入错误!",stdout);
					system("cls");
					fflush(NULL);
					break;
        		}
		fflush(NULL);
		if (AddItem(temp,&pstudent) == false)
		{
			fprintf(stderr,"内存分配存在问题\n");
			system("cls");
			break;
		}
		else
			count ++ ;
		if (ListIsFull(&pstudent))
		{
			puts("现在链表已满");
			system("cls");
			break;
		}
		system("pause");
		decide = MessageBox(NULL,"是否继续添加学生信息？","添加学生信息",MB_YESNO);
			if (decide == IDYES)
			{
					system("cls");
					UI();
			}
			else
			break; 
				fputs("姓名:",stdout);	
				getchar();
				fflush(NULL);

	}
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
}
