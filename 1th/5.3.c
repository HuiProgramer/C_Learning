#include"stdio.h"//天数转换周数和天数
int main(void)
{
   int i=0,d=1,w=0;
   while(d>0)
   { 
   printf("please input a day:");
   scanf("%d",&d);
   i=d%7;
   w=d/7;
   printf("%d day are %d week %d day\n",d,w,i);
}
return 0;
}
