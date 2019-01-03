/*编写一个程序，生成100个1~10范围内的随机数，并以降序排列*/
//与random1.c同时编译
#include<stdio.h>
#include<stdlib.h>//为srand(),rand()提供原型
#include<time.h>//为time()提供原型
#include"random.h"
int main(void)
{
	int i,loop,j;
	srand((unsigned int) time(0));
	fputs("Please enter the random number:",stdout);
	while (scanf("%d",&loop) != 1)
		fputs("Incorrect input, please retype: ",stdout);
	for(i = 0;i < loop; i ++)
		printf("%d times random number is:%d\n",i+1,random());
		puts("GOODBYE!");
		getchar();
	return 0;
}
