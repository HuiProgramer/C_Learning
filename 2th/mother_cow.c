/*��һͷĸţ����ÿ�������һͷСĸţ��ÿͷСĸţ�ӵ��ĸ���ͷ��ʼ��ÿ�����Ҳ��һͷСĸţ��
����ʵ���ڵ�n���ʱ�򣬹��ж���ͷĸţ��*/
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

        while(j<n)//ÿ��Сĸţ����Сţ
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
	/*��һ�꣬1��ţ0ͷ��2����0ͷ��3�꼰���ϵ�ţ1ͷ
 �ڶ��꣬1��ţ��Ϊ2��ţ��2��ţ��Ϊ3��ţ��3�꼰���ϵ�ţ���ڣ���3�꼰���ϵ�ţ����ͬ��������1��ţ
 
Ҳ���ǵ�n���У�1��ţaͷ��2����bͷ��3�꼰���ϵ�ţcͷ
 ��ô��n+1���У�1��ţcͷ��2����aͷ��3�꼰���ϵ�ţb+cͷ*/
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
 
