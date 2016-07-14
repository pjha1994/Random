#include<stdio.h>

void printMyArray(int a[],int n);

int main(){
    int a[] = {-1 , 2 , 0 , -3 , 5 , 1};
    int n = 6;
    for(;;){

       int swap = 0;
       int i = 0;

       for(; i < n-1; i++)
          if( a[i+1] < a[i]){
              int temp = a[i+1];
              a[i+1] = a[i];
              a[i] = temp;
              swap = 1;
           }
       if(swap == 0)
           break;
    }
    printMyArray(a,6);
   
}
void printMyArray(int a[],int n){
   int i;
   for(i = 0; i < n ; i++)
     printf("%d\t",a[i]);
   printf("\n");
}
