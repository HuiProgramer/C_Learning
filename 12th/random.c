/*��дһ����������100��1~10��Χ�ڵ�����������Խ�������*/
//��random1.cͬʱ����
#include<stdio.h>
#include<stdlib.h>//Ϊsrand(),rand()�ṩԭ��
#include<time.h>//Ϊtime()�ṩԭ��
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
