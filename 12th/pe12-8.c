//pe12-8.c
//pe12-8.1.c一起编译
/*提供make_array()和show_array()函数的定义，完成该程序
make_array()接收两个参数，第一个参数为int类型的数组元素个数，第2个参数是要赋给每个元素的值
该函数调用malloc()创建一个大小合适的数组，将其每个元素设置为指定的值，并返回一个指向该数组返回
该数组的指针。show_array()函数显示数组内容，一行8个数*/
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