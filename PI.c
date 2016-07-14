#include<stdio.h>
#define PERIOD 10
#define PRINCIPAL 5000.00
main(){
       int n;
       scanf("%d",&n);

      if(n>0)
        printf("positive number\n");
      else if(n==0)
        printf("zero\n");
      else
        printf("negative number\n");

      printf("%i\n");

      getchar();
}
