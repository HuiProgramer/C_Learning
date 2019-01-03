#include"stdio.h"//在全系1000学生中，征集慈善募捐，当总数达到10万元时就结束，统计此时捐款的人数，以及平均每人捐款的数目。
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