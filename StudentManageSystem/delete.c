#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"
void delete(void)//��Ϣɾ�� 
{
	FILE * fp;
	int Id,i = 0,k =0;
	int ch,j;
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
		puts("\n\t\t\t\t\t   ѧ����Ϣɾ��\n\n");
		char de[3][23] =
	   {"  \t     1>����ѧ��ɾ��",
		"  \t     2>��������ɾ��", 
		"  \t     0>�������˵�"};
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
			  		fputs("�������ѧ��ѧ�ţ�",stdout);
							if(scanf("%d",&Id) != 1)
							{
								MessageBox(NULL,"ѧ���������","��ʾ",MB_OK);
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
			  		fputs("�������ѧ��������",stdout);
						   s_gets(NAME,TSIZE);
						   pstudent = deleteofname(&pstudent,NAME);
						   fflush(NULL);
						   break;
			  	}
			  	if (de[2][6] == 16)
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
		   puts("\n\t\t\t\t\t   ѧ����Ϣɾ��\n\n");
		   while(k < 3)
			printf("\t\t%s\n",de+k++);
    	}  
	}
	system("pause");
}
Node * deleteofid(List * plist,int ID)//����ѧ��ɾ����Ϣ 
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
	  	MessageBox(NULL,"ɾ���ɹ���","��ʾ",MB_OK);  	
      	count--; 
	  	return node1;
	  }
	  else
	  {
			while(node1->next != NULL)
			{
				node2 = node1->next;
				if (node2->item.id == ID) /*�Ѻ���Ӧ���������е��� */
				{
					    node1->next = node2->next;
				      	free(node2); 
						MessageBox(NULL,"ɾ���ɹ���","��ʾ",MB_OK);  	
				      	count--; 
				      	break;
				}
				node1 = node1->next; /*ǰ������һ��*/
			}
			if (index == count)
			MessageBox(NULL,"û�и�ѧ��","��ʾ",MB_OK);
			return head;
		}
} 

Node * deleteofname(List * plist,char *n)//��������ɾ����Ϣ 
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
	  	MessageBox(NULL,"ɾ���ɹ���","��ʾ",MB_OK);  	
      	count--; 
	  	return node1;
	  }
	  else
	  {
			while(node1->next != NULL)
			{
				node2 = node1->next;
				if (strncmp(node2->item.name,n,TSIZE) == 0) /*�Ѻ���Ӧ���������е��� */
				{
					    node1->next = node2->next;
				      	free(node2); 
						MessageBox(NULL,"ɾ���ɹ���","��ʾ",MB_OK);  	
				      	count--; 
				      	break;
				}
				node1 = node1->next; /*ǰ������һ��*/
			}
			if (index == count)
			MessageBox(NULL,"û�и�ѧ��","��ʾ",MB_OK);
			return head;
		}
} 
