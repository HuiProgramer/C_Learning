#include"stdio.h"//ÀåÃ××ª»»Ó¢´çºÍÓ¢³ß
int main(void)
{
	double c=1.0,  i=0;
	int f=0;
	while(c>0)
	{
		printf("enter a height centimeters :");
		scanf("%lf",&c);
		f=c/30.48;
		i=(c-f*30.48) / 2.54;
		printf("%lf cm = %d feet, %lf inches\n",c,f,i);
	}
	return 0;
}