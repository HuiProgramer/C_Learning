#include<stdio.h>
#include"pe12-2a.h"
int mode;
static float kilometers = 0;
static float liters = 0;
static float miles = 0;
static float gallons = 0;
static float consum_1 = 0;	
static float consum_2 = 0;
void set_mode(int m)
{
if (m == 0)
{
fputs("Enter distance traveled in kilometers:",stdout);
scanf("%f",&kilometers);
fputs("Enter fuel consumed in liters:",stdout);
scanf("%f",&liters);
mode = m;
}
else if (m == 1)
{
fputs("Enter distance traveled in miles :",stdout);
scanf("%f",&miles);
fputs("Enter fuel consumed in gallons:",stdout); 
scanf("%f",&gallons);
mode = m;
}
else
{
puts("Invalid mode specified. Mode 1(US) used.");
fputs("Enter distance traveled in miles :",stdout);
scanf("%f",&miles);
fputs("Enter fuel consumed in gallons:",stdout); 
scanf("%f",&gallons);
mode = 1;
}
}
void get_info(void)
{
consum_1 =  liters / (kilometers / 100);
consum_2 =  miles /gallons;
}
void show_info(void)
{
if (mode == 0)
printf("Fuel consumption is %f liters per 100 km.\n",consum_1);
else
printf("Fuel consumption is %f miles per gallon.\n",consum_2);
}
