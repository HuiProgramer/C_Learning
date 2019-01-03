#include"stdio.h"//º∆À„1+1/1!+.......1/n!
int main(void)
{
	int n = 0,i = 1,j,fact = 1;
	float sum = 1.0;
	printf("please input n:");
	while (scanf("%d",&n) != 0)
	{
		while ( i <= n)
		{
			fact = 1.0;
			for (j = 1; j <= i;j ++)
				fact *= j;
			sum += 1.0 / fact;
			printf("sum=%f\n",sum);
			i++;
		}
		printf("please input n:");
	}
	
	return 0;
}