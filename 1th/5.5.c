#include"stdio.h"//ÐÞ¸Ä³ÌÐò
int main(void)
{
	int count=0 , sum=0,v=0;
	printf("please input a day:");
	scanf("%d",&v);
		while(count++<v)
			sum=sum+count;
		printf("sum = %d\n",sum);
return 0;
}