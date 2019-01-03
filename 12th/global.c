//不使用全局变量
#include<stdio.h>
int main(void)
{
	int units = 0;

	printf("How many pounds to a firkin of butter?\n");
	scanf("%d",&units);
	while (units != 56)
	{
		printf("No luck,my friend . Try again.\n");
		scanf("%d",&units);
	}
	printf("You most have looked it up!\n");

	return 0;
}
