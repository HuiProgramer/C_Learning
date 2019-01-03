#include"stdio.h"//创建一个储存26个小写字母的数组并打印
int main(void)
{
	int i=0;  
	char  letter[26]={0};
	while(i<26)
	{
	letter[i]='a'+i;
	printf("letter[%d]=%-2c",i,letter[i]);
	if(i==5||i==10||i==15||i==20||i==25)
		printf("\n");
		i++;
	}
return 0;
}