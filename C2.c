

#include<iostream.h>
struct student
{
	char name[20],gender[10];
    int age,sub1,sub2,sub3,total;	
};
int main()
{
	int i,n;
	struct student st[50];
	cout<<"enter the no of students";
	cin>>n;
	for(i=0;i<n;i++)
	{
	cout<<"   enter the NAME of student :  ";
	cin>>st[i].name;
	cout<<"   enter the GENDER          :  ";
	cin>>st[i].gender;
	cout<<"   enter your AGE            :  ";
	cin>>st[i].age;
	cout<<"enter mark of three SUBJECTS :  ";
	cin>>st[i].sub1>>st[i].sub2>>st[i].sub3;
	st[i].total=st[i].sub1+st[i].sub2+st[i].sub3;
	}
	//cout<<endl<<" TOTAL mark of "<<st[i].name <<"  is   " <<st[i].total<<endl;
	for(i=0;i<n;i++)
	{	
	cout<<endl<<" name\t age\tgender\tsub1\tsub2\tsub3\ttotal "<<endl;
	cout<<st[i].name <<"\t" << st[i].age<<"\t" <<st[i].gender<<"\t"<<st[i].sub1<<"\t" <<st[i].sub2<<"\t"<<st[i].sub3
	<<"\t"<<st[i].total<<endl;
	}
	}




//ANKIT RAJ//Program-2

#include<iostream>
using namespace std;

class student
{
	char name[20];
	int age;
	char sex;
	float m1,m2,m3,tot;
	
	public:
	
		void input();
		void calc();
		void disp();
		void output();
};

void student::input()
{
			cout<<"Enter the name of the student:";
			cin>>name;
	
			cout<<"Enter the age:";
			cin>>age;
	
			cout<<"Enter the sex:";
			cin>>sex;
		
			cout<<"Enter marks of 3 subjects\n"<<"m1=";
			cin>>m1;
		
			cout<<"m2=";
			cin>>m2;
		
			cout<<"m3=";
			cin>>m3;
}

	void student::calc()
	{
		tot=m1+m2+m3;
	}
	
	void student::disp()
	{
	
		cout<<"\nName:";
	
		cout<<"\tAge:";
	
		cout<<"\tSex:";
	
		cout<<"\tm1";
	
		cout<<"\tm2";
	
		cout<<"\tm3";
	
		cout<<"\tTotal";
	
		cout<<"\n";
	}
	
	void student::output()
	{
		
		cout<<name;
	
		cout<<"\t"<<age;
		
		cout<<"\t"<<sex;
	
		cout<<"\t"<<m1;
		
		cout<<"\t"<<m2;
	
		cout<<"\t"<<m3;
	
		cout<<"\t"<<tot<<"\n";
	
	}
	
	int main()
	{
		student s[10];
		int i,n;
		cout<<"Enter the total number of students:";
		cin>>n;
		
		
		for(i=1;i<=n;i++)
		{
			s[i].input();
			s[i].calc();
		}
		s[i].disp();
		
		for(i=1;i<=n;i++)
		s[i].output();
		
		 
	}




//ANKIT RAJ//Program-3

#include<iostream>
using namespace std;

class DATA
{
	int d[20];
	static int c;
	
	public:
	void input(int n);
	void disp();	
};

int DATA::c;

void DATA::input(int n)
{
	cout<<"Enter the array elements\n";
	
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
		
		if(d[i]>0)
		c++;
	}
}

void DATA::disp()
{
	cout<<"Number of positive terms="<<c<<"\n";
}

main()
{
	DATA d1,d2;
	int n;
	
	cout<<"Enter the size of the array:";
	cin>>n;
	
	d1.input(n);
	d2.input(n);
	d1.disp();
	
	return 0;
}




//ANKIT RAJ//Program-4

#include<iostream>
using namespace std;
class CLOCK
{
	int h,m,s;
	public:
	CLOCK();
	CLOCK(int a,int b,int c);
	void disp();
};
CLOCK::CLOCK()
{
	h=m=s=0;
}
CLOCK::CLOCK(int a,int b,int c)
{
	h=a;
	m=b;
	s=c;
}
void CLOCK::disp()
{
	cout<<"\n h="<<h<<"\n m="<<m<<"\n s=";
	cout<<s<<"\n";
}
int main()
{
	CLOCK C1=CLOCK();
	CLOCK C2=CLOCK(2,45,56);
	C1.disp();
	C2.disp();
	return 0;
}




//ANKIT RAJ//Program-5

#include<iostream>
using namespace std;

class CLOCK
{
	int h,m,s;
	
	public:
	CLOCK()
	{
		h=m=s=0;
	}
	void input();	
	friend void add(CLOCK,CLOCK);
};

void CLOCK::input()
{
	cout<<"Enter the time\n";
	cout<<"h=";
	cin>>h;
	cout<<"m=";
	cin>>m;
	cout<<"s=";
	cin>>s;
}

void add (CLOCK c1, CLOCK c2)
{
	CLOCK c3;
	c3.s=c1.s+c2.s;
	if(c3.s>=60)
	{
		c3.s=c3.s-60;
		c3.m++;
	}	
	c3.m=c3.m+c1.m+c2.m;
	
	if(c3.m>=60)
	{
		c3.m=c3.m-60;
		c3.h++;
	}
	c3.h=c3.h+c1.h+c2.h;
	cout<<"\nh="<<c3.h<<"\nm="<<c3.m<<"\ns="<<c3.s<<"\n";
	

}

main()
{
	CLOCK c1,c2,c3;
	c1.input();
	c2.input();
	add(c1,c2);
	return 0;
}




//ANKIT RAJ//Program-6

#include<iostream>
using namespace std;
class comp
{
	float x,y;
	public:
	comp ()
	{
	x=0;y=0;	
	}
	
		comp (float a,float b)
		{
			x=a;
			y=b;
		}
		friend void sum(float,comp);
		friend void sum(comp,comp);
};
	void sum(float s,comp c5)
	{
		comp c6;
		c6.x=s+c5.x;
		c6.y=c5.y;
		cout<<"sum="<< c6.x <<"+"<<c6.y<<"j\n";
	}
	void sum(comp c2,comp c4)
		{
		comp c3;
		c3.x=c2.x+c4.x;
		c3.y=c2.y+c4.y;
		cout <<"sum ="<< c3.x <<"+"<<c3.y<<"j\n";
	}
	
int main()
{
	comp a(-2.7,-3.5);
	comp b(-1.6,-1.6);
	sum (a,b);
	sum (10.1,a);
	return(0);
}




//ANKIT RAJ//Program-7

#include<iostream>
#include<math.h>
using namespace std;

void area(float,float,float);
void area(float,float);
void area(float);
void area(int);

void area(float a,float b,float c)
{
	double q=0,s=0;
	s=(a+b+c)/2;
	q=sqrt(s*(s-a)*(s-b)*(s-c));
	cout<<"Area of the Triangle="<<q;
}

void area(float a,float b)
{
	float q=0;
	q=a*b;
	cout<<"Area of the Rectangle="<<q;
}

void area(float a)
{
	float q=0;
	q=a*a;
	cout<<"Area of the Square="<<q;	
}

void area(int a)
{
	float q=0;
	q=3.14*a*a;
	cout<<"Area of the Circle="<<q;
}

main()
{
	char op='y';
	int opt,r;
	float a,b,c;
	do
	{
		cout<<"Select an option\n1.Triangle\n2.Rectangle\n3.Square\n4.Circle\n";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"Enter the sides of the Triangle\n";
				cout<<"a=";
				cin>>a;
				cout<<"b=";
				cin>>b;
				cout<<"c=";
				cin>>c;
				area(a,b,c);
				break;
				
			case 2:
				cout<<"Enter the sides of the Rectangle\n";
				cout<<"l=";
				cin>>a;
				cout<<"b=";
				cin>>b;
				area(a,b);
				break;
				
			case 3:
				cout<<"Enter the side of the Square\n";
				cout<<"a=";
				cin>>a;
				area(a);
				break;
				
			case 4:
				cout<<"Enter the radius of the circle\n";
				cout<<"r=";
				cin>>r;
				area(r);
				break;
				
			default:
				cout<<"Invalid option";
				break;
		}
		cout<<"\nDo you want to continue(y/n)";
		cin>>op;
	}while(op=='y');
return 0;
}




//ANKIT RAJ//Program-8

#include<iostream>
using namespace std;

class dist
{
	float ft,in;
	
	public:
	dist();
	void input();
	void disp();
	friend dist operator+(dist,dist);
	friend int operator<(dist,dist);
};

dist::dist()
{
	ft=in=0.0;
}

void dist::input()
{
	cout<<"Enter the distance\n";
	cout<<"feet:";
	cin>>ft;
	cout<<"inch:";
	cin>>in;
}

void dist::disp()
{
	cout<<"\nfeet:"<<ft;
	cout<<"\ninch:"<<in<<"\n";
}

dist operator+(dist d1,dist d2)
{
	dist d;
	d.ft=d1.ft+d2.ft;
	d.in=d1.in+d2.in;
	while(d.in>=12.0)
	{
		d.ft++;
		d.in=d.in-12.0;	
	}
	return d;	
}

int operator<(dist d1,dist d2)
{
	float a,b;
	a=d1.ft+((d1.in/12.0));
	b=d2.ft+((d2.in/12.0));
	
	if(a<b)
	return 1;
	
	else
	return 0;
}

main()
{
	dist d1,d2,d3;
	d1.input();
	d2.input();
	d3=d1+d2;
	cout<<"Sum:\n";
	d3.disp();
	cout<<"\nSmallest:\n";
	if(d1<d2)
	d1.disp();
	
	else 
	d2.disp();
	
	return 0;
}




//ANKIT RAJ//Program-9

#include<iostream>
using namespace std;
const float MTF=3.280833;
class dist
{
	private:
	int feet;
	float inches;
	public:
	dist()
	{
		feet=0;inches=0.0;
	}
	dist(float meters)
	{
		float ftfeet=MTF*meters;
		feet=int(ftfeet);
		inches=12*(ftfeet-feet);
	}
	dist(int ft,float in)
	{
		feet=ft;inches=in;
	}
	void getdist()
	{
		cout<<"\n Enter inches:";
		cin>>inches;
	}
	void showdist()
	{
		cout<<feet<<"ft"<<inches<<"inch";
	}
	operator float()
	{
		float fracfeet=inches/12;
		fracfeet+=float(feet);
		return fracfeet/MTF;
	}
};
main()
{
	dist d1(1.0);
	cout<<"\nd1=";
	d1.showdist();
	dist d2(3,3.37);
	float mtrs=float(d2);
	cout<<"\nd2="<<mtrs<<"meters";
}





//ANKIT RAJ//Program-10

#include<iostream>
#include<math.h>
using namespace std;
class Rec
{
	private:
	double xco;
	double yco;
	public:
	Rec()
	{
		xco=0.0;yco=0.0;
	}
	Rec(double x,double y)
	{
		xco=x;yco=y;
	}
	void display()
	{
		cout<<"("<<xco<<","<<yco<<")";
	}
};
class polar
{
	private:
	double radius;
	double angle;
	public:
	polar()
	{
		radius=0.0;angle=0.0;
	}
	polar(double r,double a)
	{
		radius=r;angle=a;
	}
	void display()
	{
		cout<<"("<<radius<<","<<angle<<")";
	}
	operator Rec()
	{
		double x=radius*cos(angle);
		double y=radius*sin(angle);
		return Rec(x,y);
	}
};
main()
{
	Rec rec;
	polar pol(10.0,0.785398);
	rec=Rec(pol);
	cout<<"\n polar=";pol.display();
	cout<<"\n rectangular=";rec.display();
}





