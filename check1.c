#include<iostream.h>
#include<conio.h>
enum shape
{circle,
rectangle,
triangle};
void main()
{cout<<"Enter the shape code:";
int code;
cin>>code;
while(code>=circle&&code<=triangle)
{
switch(code)
   {case circle:cout<<"you r in circle";
	 break;
    case re
    ctangle:cout<<"you r in rectangle";
	 break;
    case triangle:cout<<"you r in triangle";
	 break;
   }
cout<<"enter shape code:";
cin>>code;
}
cout<<"BYE\n";
}










#include<iostream.h>
#include<conio.h>
void main()
{clrscr();
for(int i=0;i<10;i++)
cout<<"how r u?"<<" "<<"taken control"<<" "<<"MENDAX"<<"\n";
getch();
}








#include<iostream.h>
#include<conio.h>
void main()
{clrscr();
long float a,b;
cout<<"enter a and b"<<"\n";
cin>>a
>>b;
cout<<"sum="<<a+b;
getch();
}











#include<iostream.h>
#include<conio.h>
void main()
{clrscr();
long float a,r;
cout<<"enter radius r"<<"\n";
cin>>r;
a=22/7.0*r*r;
cout<<a;
getch();
}






#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{clrscr();
long l,b,s1,s2,s3,m,r;
int n;
cout<<"1 for rect,2 for tri,3 for circle perimeter"<<"\n";
cin>>n;

switch(n)
{case 1:cout<<"enter sides of rectangle"<<"\n";
	cin>>l>>b;
	cout<<l*b;
	break;
case 2:cout<<"enter the sides of the triangle"<<"\n";
       cin>>s1>>s2>>s3;
       m=(s1+s2+s3)/2.0;
       cout<<sqrt(m*(m-s1)*(m-s2)*(m-s3));
       break;
case 3:cout<<"enter the radius"<<"\n";
      cin>>r;
      cout<<2*r*22.0/7;
      break;
}

getch();
}







#include<iostream.h>
#include<conio.h>
void main()
{clrscr();
unsigned int n,f=1,N,i,x;
long float N1;
cout<<"1every 3rd integer from 2"<<"\n"
    <<"2odd nos ending with 3"<<"\n"
    <<"3factorial"<<"\n"
    <<"4xto the power n"<<"n";
cin>>n;
switch(n)
{case 1:for(i=2;i<500;i=i+3)
	cout<<i<<" ";
	break;
 case 2:for(i=0;i<=1000;i++)
	{if(i%3==0&&i%10==3)
	  cout<<i<<" ";
	}
	break;
 case 3:cout<<"enter a number"<<"\n";
	cin>>N;
	for(i=1;i<=N;i++)
	{f=f*i;
	}
	cout<<f<<" ";
	break;
 case 4:cout<<"enter x and n"<<"\n";
	cin>>x>>N1;
	f=1;
	for(i=1;i<=N1;i++)
	{
	f=f*x;
	}
	cout<<f;
	break;
}
getch();
}
