//pe12-8.c
//pe12-8.1.cһ�����
/*�ṩmake_array()��show_array()�����Ķ��壬��ɸó���
make_array()����������������һ������Ϊint���͵�����Ԫ�ظ�������2��������Ҫ����ÿ��Ԫ�ص�ֵ
�ú�������malloc()����һ����С���ʵ����飬����ÿ��Ԫ������Ϊָ����ֵ��������һ��ָ������鷵��
�������ָ�롣show_array()������ʾ�������ݣ�һ��8����*/
#include<stdio.h>
#include<stdlib.h>
int * make_array(int elem,int val);
void show_array(const int ar[] ,int n);
int main(void)
{
	int * pa;
	int size;
	int value;
	
	printf("Enter the number of elements: ");
	while (scanf("%d",&size) == 1 && size > 0)
	{
		printf("Enter the initialization value: ");
		scanf("%d",&value);
		pa = make_array(size,value);
		if(pa)
		{
			show_array(pa,size);
			free(pa);
		}
		printf("Enter  the number of elements (<1 to quit ): ");
	}
	printf("Done.\n");
	return 0;
}