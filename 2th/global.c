/* global.c -- ʹ���ⲿ���� */
#include<stdio.h>
int units = 0;
void critic(void);
int main(void)
{
	extern int units;

	printf("How many pounds to a firkin og butter?\n");
	scanf("%d",&units);
	while (units != 56)
		critic();
	printf("You must have looked it up!\n");

	return 0;
}

void critic(void)
{
	/* ɾ���˿�ѡ���ظ�ģʽ*/
	printf("No luck, my friend . Try again.\n");
	scanf("%d",&units);
}