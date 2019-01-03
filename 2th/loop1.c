#include"stdio.h" //º∆À„S=1/2! +1/4! +1/6! +°≠+1/10!
int main(void)
{
	int i=5,j,fact,add=0;
	float sum=0;
	while (i <= 10)
	{
		fact = 1;
			add += 2;
		for (j = 1;j <= add;j ++)
			fact *= j;
		sum += 1.0 / fact;
		printf("sum=%f\n",sum);
		i++;
	}
	return 0;
}