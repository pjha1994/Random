#include<stdio.h>
#define BASE 10
main(){
	int i=0;
	char s[1000],c;
	while((c=getchar())!='\n')
	s[i++]=c;
	s[i]='\0';
	convert_to_integer(s,i)==-1?printf("ERROR IN INPUT\n"):printf("%d \t value in integer",convert_to_integer(s,i));
	return 0;
}
int convert_to_integer(char s[],int length){
	int i=0;
	unsigned long int p=1;
	unsigned long int k=0;
	int temp_num;
	for(i=length-1;i>=2;i--)
	{
	  if(BASE==16){
	        if(s[i]>='0'&&s[i]<='9')
			temp_num=s[i]-'0';
		else if(s[i]>='A'&&s[i]<='F')
			temp_num=s[i]-55;
		else if(s[i]>='a'&&s[i]<='f')
			temp_num=s[i]-87;
		else
			return -1;
		k=k+temp_num*p;
		p=p*BASE;
	  }
	  else if(BASE==8){
		  if(s[i]>='0'&&s[i]<='7')
			temp_num=s[i]-'0';
		  else
			return -1;
		k=k+temp_num*p;
		p=p*BASE;
	  }
	  else if(BASE==2){
		  if(s[i]>='0'&&s[i]<='2')
			temp_num=s[i]-'0';
		  else
			return -1;
		k=k+temp_num*p;
		p=p*BASE;
	  }
	  else if(BASE==10){
		  if(s[i]>='0'&&s[i]<='9')
			temp_num=s[i]-'0';
		  else
			return -1;
		k=k+temp_num*p;
		p=p*BASE;
	  }
	}
	return k;
}
