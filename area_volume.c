#include<stdio.h>
int AreaAndVolume(float a) 
{ float Area = 4 (22/7.0)* (a * *a); 
float Volume = (4/3) (22/7)* (*a * *a * *a);
}
int main() 
{
float r;
printf("Enter radius: ");
 scanf("%f", &r);
float area = AreaAndVolume(&r); 
printf("Area: %f", area);
float volume =
return 0; 
}
