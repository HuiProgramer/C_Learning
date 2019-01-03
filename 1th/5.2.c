#include"stdio.h" //输入一个数，输出比该数大10的所以整数
int main(void)
{
	int i=0,j=0;
	printf("please input a number:");
	scanf("%d",&j);
	while(i<=10)
	{
		printf("%d\t",j);
		j++;
			i++;
	}
	return 0;
}