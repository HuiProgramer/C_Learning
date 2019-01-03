/*有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。
请编程实现在第n年的时候，共有多少头母牛？*/
#include"stdio.h"
#include"iso646.h"
int main(void)
{
	 int n=0;//i=0,j=3;
	 unsigned years0 = 0;
     unsigned years1 = 1;
     unsigned years2 = 0;
 

   /* int mother_cow[55]={0},mother_cow2[55]={0};
    do
    {
        printf("please input cow of mother:");
        scanf("%d",&n);
        if(n>0 and n<55)
        break;
    }while(n != 0);
    for(i=0; i<n;  i++)
    {
        mother_cow[i] += i;

		j+=i;

        while(j<n)//每年小母牛生的小牛
		{
        mother_cow2[j] += j;

		printf("mother_cow[%d]=%d",j,mother_cow2);

		j++;
		}
        mother_cow[i] += mother_cow2[j];

        printf("mother_cow[%d]=%-2d",i,mother_cow[i]);

        if(i==4 or i==9 or i==14 or i==19 or i==24 or i==29 or i==34 or i==39 or i==44 or i==49)
        printf("\n");
    }*/
	/*第一年，1岁牛0头，2岁年0头，3岁及以上的牛1头
 第二年，1岁牛变为2岁牛，2岁牛变为3岁牛，3岁及以上的牛还在，且3岁及以上的牛生出同等数量的1岁牛
 
也就是第n年有：1岁牛a头，2岁年b头，3岁及以上的牛c头
 那么第n+1年有：1岁牛c头，2岁年a头，3岁及以上的牛b+c头*/
    for( n=1; n!=55; ++n )
     {
         unsigned tmp = years2;
         years2 += years1;
         years1 = years0;
         years0 = tmp;
 
        printf( "f(%u) = %u\n", n, years0+years1+years2 );       

    }
    return 0;
}
 
