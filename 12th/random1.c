#include<stdio.h>
#include<stdlib.h>
#include"random.h"
int random(void)
{
	int r;
	r =	rand() % 10 + 1;
	return r;
}