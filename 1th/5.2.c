#include"stdio.h" //����һ����������ȸ�����10����������
int main(void)
{
	int i=0,j=0;
	printf("please input a number:");
	scanf("%d",&j);
	while(i<=10)
	{
		printf("%d\t",j);
		j++;
			i++;
	}
	return 0;
}