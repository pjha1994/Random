#include<stdio.h>

int main(){
       int i;
       for(i=2;i<10;i++)
        //int x = i%2==0?printf("%i",i):45;
        if(i%2==0)
           printf("%i\t\n",i);
        else
           printf("%i",i);
}



