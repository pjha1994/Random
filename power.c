#include<stdio.h>
unsigned long int power(unsigned long int ,unsigned long int);
void call(unsigned long int (*power)(),unsigned long int x,unsigned long int y);
main(){
   printf("For x^y, enter x and y : "); 
   unsigned long int a,b;
   scanf("%ul%ul",&a,&b);
   call(power,a,b);

}
void call(unsigned long int (*f)(),unsigned long int x,unsigned long int y){
    printf("%ul^%ul = %d\n",x,y,(*f)(x,y));
}

unsigned long int power(unsigned long int x,unsigned long int y){
    unsigned long int p=1,c=1;
    
    for(;c<=y;c++)
      p=p*x;

    return p;

}
