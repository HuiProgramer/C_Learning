#include"stdio.h"
int main(void)
{
    char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	char letter = 0;
	
	printf("please input a letter(for example : E):");
	
	scanf("%c",&letter);
	
	int  out_i =0, in_i_black= 0,in_i_up = 0, in_i_down = 0;
	
	for (out_i = 0; lets[out_i] <= letter; out_i++)
	{
		
		for ( in_i_black = 0; in_i_black < (letter - lets[out_i]); in_i_black++)
			putchar(' ');
		
		for (in_i_up = 0; in_i_up < out_i; in_i_up++)
			putchar(lets[in_i_up]);
		
		for(in_i_down = out_i; in_i_down >= 0; in_i_down--)
			putchar(lets[in_i_down]);
		putchar('\n');
	}									  
	return 0;
} 
