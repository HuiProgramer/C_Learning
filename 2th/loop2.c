#include"stdio.h"//��ȫϵ1000ѧ���У���������ļ�裬�������ﵽ10��Ԫʱ�ͽ�����ͳ�ƴ�ʱ�����������Լ�ƽ��ÿ�˾�����Ŀ��
int main(void)
{
	int  i = 1, sum = 0, money = 0,average=0;
	while (i <= 1000)
	{
		printf("please enter the donation amount of the %d student:",i);
		scanf("%d",&money);
		sum += money;
	if (sum >= 100000)
	break;
	i++;
	}
	average = sum / i;
	printf("there are %d donations\n",i);
	printf("the average amount of donations per person is:%d\n",average);
	return 0;
}