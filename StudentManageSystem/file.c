#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"list.h"
void file(void)
{
	unsigned int temp;
	FILE * fp;
	int file_size = 0;
	fputs("\n\n请输入你要操作的班级（例如：java-1708）：",stdout);
	if (s_gets(data,45) == NULL)
	{
		fprintf(stderr,"在文件%s中读取失败，再见!\n",__FILE__);
		exit(EXIT_FAILURE);
	}
	if((fp = fopen(data,"ab+")) == NULL)
	{
		printf("不能打开文件%s\n",data);
		exit(EXIT_FAILURE);
	}
	system("cls");
	/* 先判断文件是否为空 */ 
	fseek(fp, 0L, SEEK_END);
	file_size = ftell(fp);
	
	/* 把文件指针恢复到文件开头 */
	rewind(fp);
	fread(&count,sizeof(unsigned int),1,fp);
	decide = MessageBox(NULL,"是否进入查看读取信息？","提示",MB_YESNO); 
	if (decide == IDYES)
		printf("文件名：%s\n文件大小：%d\n",data,file_size); 
	temp = count;
	if (0 == file_size)
	printf("没有数据！");
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
		fprintf(stderr,"文件%s关闭失败！\n",data);
		exit(EXIT_FAILURE); 
	}	
	system("pause");
	system("cls");
}
