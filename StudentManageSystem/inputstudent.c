#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"list.h" 
void inputstudent(void)
{
	FILE *fp;
	if((fp = fopen(data,"wb+")) == NULL)
	{
		printf("���ܴ��ļ�%s\n",data);
		exit(EXIT_FAILURE);
	}
	if (ListIsFull(&pstudent))
	{
		fprintf(stderr,"������������л����ʹ�ã��ټ�!\n");
		exit(EXIT_FAILURE);
	}
     /*��ȡ�û����벢����*/
	fputs("����:",stdout);
	while (s_gets(temp.name,TSIZE) != NULL && temp.name[0] != '\0')
	{
		fflush(NULL);
		fputs("ѧ��:",stdout);
		if (scanf("%d",&temp.id) != 1 || idcompare(&pstudent,temp.id) )
		{
			fputs("ѧ���������!",stdout);
			system("cls");
			fflush(NULL);
			break;
        }
        
		fputs("��ѧ:",stdout);
		if (scanf("%d",&temp.math) != 1 || temp.math > 100  || temp.math < 0 )
			{
		    	fputs("�ɼ��������!",stdout);
		    	system("cls");
		    	fflush(NULL);
		    	break;
            }
		
		fputs("����:",stdout);
		if (scanf("%d",&temp.politics) != 1 || temp.politics > 100 || temp.politics < 0)
				{
		        	fputs("�ɼ��������!",stdout);
		        	system("cls");
		        	fflush(NULL);
		        	break;
                }
		
		fputs("Ӣ��:",stdout);
		if (scanf("%d",&temp.english) != 1 || temp.english > 100 || temp.english < 0)
			{
		    	fputs("�ɼ��������!",stdout);
		    	system("cls");
		    	fflush(NULL);
				break;
            }
		
		fputs("���������:",stdout);
		if (scanf("%d",&temp.computer) != 1 || temp.computer > 100 || temp.computer < 0)
				{
					fputs("�ɼ��������!",stdout);
					system("cls");
					fflush(NULL);
					break;
       			 }
		
		fputs("C����:",stdout);
		if (scanf("%d",&temp.c) != 1 || temp.c > 100 || temp.c < 0)
				{
					fputs("�ɼ��������!",stdout);
					system("cls");
					fflush(NULL);
					break;
        		}
		fflush(NULL);
		if (AddItem(temp,&pstudent) == false)
		{
			fprintf(stderr,"�ڴ�����������\n");
			system("cls");
			break;
		}
		else
			count ++ ;
		if (ListIsFull(&pstudent))
		{
			puts("������������");
			system("cls");
			break;
		}
		system("pause");
		decide = MessageBox(NULL,"�Ƿ�������ѧ����Ϣ��","���ѧ����Ϣ",MB_YESNO);
			if (decide == IDYES)
			{
					system("cls");
					UI();
			}
			else
			break; 
				fputs("����:",stdout);	
				getchar();
				fflush(NULL);

	}
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
}
