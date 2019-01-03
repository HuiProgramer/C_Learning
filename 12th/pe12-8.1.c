#include<stdio.h>
#include<stdlib.h>
int * make_array(int elem, int val)
{
	int i;
	int * pa = (int *)malloc(elem * sizeof(int));
	for(i = 0 ;i < elem; i ++)
		pa[i] = val;
	return pa;
}
void show_array(const int ar[],int n)
{
	int i;
	for(i = 0; i < n; i ++)
	{
		printf("pa[%d]=%d",i,ar[i]);
		if((i + 1) % 8 == 0)
			putchar('\n');
	}
}