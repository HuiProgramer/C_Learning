#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"
void delete(void)//信息删除 
{
	FILE * fp;
	int Id,i = 0,k =0;
	int ch,j;
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
		puts("\n\t\t\t\t\t   学生信息删除\n\n");
		char de[3][23] =
	   {"  \t     1>根据学号删除",
		"  \t     2>根据姓名删除", 
		"  \t     0>返回主菜单"};
		de[i][7] = 16;
		de[i][6] = 16;
		while(k < 3)
		printf("\t\t%s\n",de+k++);
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
						   	de[j][6] = ' ';
						   	de[j][7] = ' ';
						   }
						   de[i][6] = 16;
						   de[i][7] = 16;
							break;
						case 80:
						   if (i < 2 && i >= 0)
						   ++i;
						   for(j = 0;j <= 3;j++)
						   {
						   	de[j][6] = ' ';
						   	de[j][7] = ' ';
						   }
						   de[i][6] = 16;
						   de[i][7] = 16;
						   break;
						default:
							break;
				    } 
				    break;
			  case 13:
			  	if (de[0][6] == 16)
			  	{
			  		fflush(NULL);
			  		fputs("请输入该学生学号：",stdout);
							if(scanf("%d",&Id) != 1)
							{
								MessageBox(NULL,"学号输入错误！","提示",MB_OK);
								fflush(NULL);
								break;
							}
							fflush(NULL);
							pstudent = deleteofid(&pstudent,Id);
							break;
			  	}
			  	if (de[1][6] == 16)
			  	{
			  		fflush(NULL);
			  		fputs("请输入该学生姓名：",stdout);
						   s_gets(NAME,TSIZE);
						   pstudent = deleteofname(&pstudent,NAME);
						   fflush(NULL);
						   break;
			  	}
			  	if (de[2][6] == 16)
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
		   puts("\n\t\t\t\t\t   学生信息删除\n\n");
		   while(k < 3)
			printf("\t\t%s\n",de+k++);
    	}  
	}
	system("pause");
}
Node * deleteofid(List * plist,int ID)//根据学号删除信息 
{
	Node *head = *plist;
	Node *node1 = *plist;
	Node *node2 = NULL;
	int index = count;
	if (*plist == NULL)
		return NULL;
	else
	  if (node1->item.id == ID)
	  {
	  	node1 = node1->next;
	  	free(head);
	  	MessageBox(NULL,"删除成功！","提示",MB_OK);  	
      	count--; 
	  	return node1;
	  }
	  else
	  {
			while(node1->next != NULL)
			{
				node2 = node1->next;
				if (node2->item.id == ID) /*把函数应用于链表中的项 */
				{
					    node1->next = node2->next;
				      	free(node2); 
						MessageBox(NULL,"删除成功！","提示",MB_OK);  	
				      	count--; 
				      	break;
				}
				node1 = node1->next; /*前进到下一项*/
			}
			if (index == count)
			MessageBox(NULL,"没有该学生","提示",MB_OK);
			return head;
		}
} 

Node * deleteofname(List * plist,char *n)//根据姓名删除信息 
{
	Node *head = *plist;	
	Node *node1 = *plist;
	Node *node2 = NULL;
	int index = count;
	if (*plist == NULL)
		return NULL;
	else
	  if (strncmp(node1->item.name,n,TSIZE) == 0)
	  {
	  	node1 = node1->next;
	  	free(head);
	  	MessageBox(NULL,"删除成功！","提示",MB_OK);  	
      	count--; 
	  	return node1;
	  }
	  else
	  {
			while(node1->next != NULL)
			{
				node2 = node1->next;
				if (strncmp(node2->item.name,n,TSIZE) == 0) /*把函数应用于链表中的项 */
				{
					    node1->next = node2->next;
				      	free(node2); 
						MessageBox(NULL,"删除成功！","提示",MB_OK);  	
				      	count--; 
				      	break;
				}
				node1 = node1->next; /*前进到下一项*/
			}
			if (index == count)
			MessageBox(NULL,"没有该学生","提示",MB_OK);
			return head;
		}
} 
