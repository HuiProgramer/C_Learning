#include"stdio.h"//修改程序,使其能计算平方和
int main(void)
{
	int count=0 , sum=0,v=0;
	printf("please input a day:");
	scanf("%d",&v);
		while(count++<v)
			sum=sum+count;
		sum=sum*sum;
		printf("sum = %d\n",sum);
return 0;
}