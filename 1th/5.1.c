#include"stdio.h"//把分钟表示的时间用小时和分钟表示
#define TIME 60
int main(void)
{
	int i=1,m=0,h=0;
	while(i>0){
	printf("please input a time of minut:");
	scanf("%d",&i);
	m=i%TIME;
	h=i/TIME;
	printf("time of beijing %d:%d\n",h,m);
	}
return 0;
}
