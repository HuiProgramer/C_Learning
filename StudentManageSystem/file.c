#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"list.h"
void file(void)
{
	unsigned int temp;
	FILE * fp;
	int file_size = 0;
	fputs("\n\n��������Ҫ�����İ༶�����磺java-1708����",stdout);
	if (s_gets(data,45) == NULL)
	{
		fprintf(stderr,"���ļ�%s�ж�ȡʧ�ܣ��ټ�!\n",__FILE__);
		exit(EXIT_FAILURE);
	}
	if((fp = fopen(data,"ab+")) == NULL)
	{
		printf("���ܴ��ļ�%s\n",data);
		exit(EXIT_FAILURE);
	}
	system("cls");
	/* ���ж��ļ��Ƿ�Ϊ�� */ 
	fseek(fp, 0L, SEEK_END);
	file_size = ftell(fp);
	
	/* ���ļ�ָ��ָ����ļ���ͷ */
	rewind(fp);
	fread(&count,sizeof(unsigned int),1,fp);
	decide = MessageBox(NULL,"�Ƿ����鿴��ȡ��Ϣ��","��ʾ",MB_YESNO); 
	if (decide == IDYES)
		printf("�ļ�����%s\n�ļ���С��%d\n",data,file_size); 
	temp = count;
	if (0 == file_size)
	printf("û�����ݣ�");
	else 
	while(temp--)
    {
    	Item tmp;

        fread(&tmp, sizeof(Item), 1, fp);
        if (decide == IDYES)
        printf("tmp.name:%s ,tmp.id:%d ,tmp.politics:%d, tmp.english:%d, tmp.computer:%d, tmp.c:%d  fp:%p\n", 
				tmp.name, tmp.id, tmp.politics, tmp.english, tmp.computer, tmp.c, fp);
	
		AddItem(tmp, &pstudent);

    }
	if (fclose(fp) != 0)
	{
		fprintf(stderr,"�ļ�%s�ر�ʧ�ܣ�\n",data);
		exit(EXIT_FAILURE); 
	}	
	system("pause");
	system("cls");
}
