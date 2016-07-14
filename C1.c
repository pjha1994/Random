
ankit raj

#include<iostream>
using namespace std;

template<class t>

void bubsort(t ar[], int s)
{
	int i,j;
	
	for(i=1;i<s;i++)
	{
		for(j=0;j<s-i;j++)
		{
			if(ar[j]>ar[j+1])
			{
				t temp;
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;	
			}
		}
	}
	cout<<"\n...Sorted array...\n";
		for(i=0;i<s;i++)
			cout<<ar[i]<<" ";	
}

main()
{
	int opt,a[10],i,size;
	double d[10];
	char loop='y';
	while(loop=='y'||loop=='Y')
	{
		cout<<"1.Integer datatype array\n2.Double datatype array\noption:";
		cin>>opt;
		
		switch(opt)
		{
			case 1:
				cout<<"Enter the size of the array\n";
				cin>>size;
				cout<<"Enter the array elements\n";
				for(i=0;i<size;i++)
					cin>>a[i];
				bubsort(a,size);
				break;
				
			case 2:
				cout<<"Enter the size of the array\n";
				cin>>size;
				cout<<"Enter the array elements\n";
				for(i=0;i<size;i++)
					cin>>d[i];
				bubsort(d,size);
				break;
				
			default:
				cout<<"Invalid Option...\n";
				break;
		}
		cout<<"\nDo you want to continue(y/n):";
		cin>>loop;
	}
return 0;
}


#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class student
{
	
	char name[50];
	float m1,m2,m3;
	
	public:
	int rno;
		student()
		{
			strcpy(name, " ");
			rno=0;
			m1=m2=m3=0.0;
		}
		void input()
		{
			cout<<"\nName:";
			cin>>name;
			
			cout<<"Roll Number:";
			cin>>rno;
			
			cout<<"Marks of 3 subjects\nm1="; cin>>m1;
			cout<<"m2="; cin>>m2;
			cout<<"m3="; cin>>m3;
		}
	
		void disp()
		{
			cout<<"\n"<<name;
			cout<<"\t"<<rno;
			cout<<"\t"<<m1<<"\t"<<m2<<"\t"<<m3<<"\n";
		}
		friend student coppy(student);
		
}s[10];

void tabb()
{
	cout<<"\nName\tNumber\tMark1\tMark2\tMark3";
	cout<<"\n....\t......\t.....\t.....\t.....";	
}
student coppy(student s1)
{
	student stud;
	strcpy(stud.name,s1.name);
	stud.rno=s1.rno;
	stud.m1=s1.m1;
	stud.m2=s1.m2;
	stud.m3=s1.m3;
	return stud;
}

main()
{
	student temp,ss;
	fstream f;
	int opt,n,i,r,pos=-1;
	char loop='y';
	f.open("stud.txt", ios::in|ios::out|ios::app);
	
	while(loop=='y'||loop=='Y')
	{
		cout<<"\n1.Enter details\n\n2.Display details\n\n3.Search a student\n\n4.Modify a record\n\n5.Delete a record\n\noption=";
		cin>>opt;
		
		switch(opt)
		{
			case 1:
				cout<<"Enter the number of students:";
				cin>>n;
					for(i=0;i<n;i++)
					{
						s[i].input();
						f.write((char*) &s[i], sizeof(s[i]));
					}
					
					break;
				
			case 2:	
				tabb();
				for(i=0;i<n;i++)
				{
					f.read((char*) &s[i], sizeof(s[i]));
					s[i].disp();
				}	
				break;
				
			case 3:
				
				pos=-1;
				cout<<"Enter the roll number to be searched:";
				cin>>r;
				for(i=0;i<n;i++)
				{
					if(s[i].rno==r)
					{
						cout<<"\n...Student present...\n";
						pos=i;
						break;
					}
				}
				if(pos!=-1)
				{
					tabb();
					s[pos].disp();	
				}
				else
					cout<<"\n...Student not present...\n";
					
				break;
								
			case 4:
				pos=-1;
				cout<<"Enter the roll number of the student:";
				cin>>r;
				for(i=0;i<n;i++)
				{
					if(s[i].rno==r)
					{
						cout<<"\n...Enter new details...\n";
						pos=i;
						break;
					}
				}
				if(pos!=-1)
				{
					s[pos].input();	
				}
				else
					cout<<"\n...Student not present...\n";
				
				break;
				
			case 5:
				pos=-1;
				cout<<"Enter the roll number of the student:";
				cin>>r;
				for(i=0;i<n;i++)
				{
					if(s[i].rno==r)
					{
						pos=i;
							while(pos!=n)
							{
								temp=coppy(s[pos]);
								s[pos]=(s[pos+1]);
								s[pos+1]=(temp);
								pos=pos+1;
							}
							n=n-1;
		
						break;
					}
				}
				if(pos==-1)
				{
					cout<<"\n...Student not present...\n";
				}
				else
					cout<<"\n...Successfully Deleted...\n";
			
				break;
			
			default:
				cout<<"\nInvalid selection\n";
						
		}
		cout<<"\nDo you want to continue(y/n):";
		cin>>loop;
	}
return 0;
}



#include<iostream>
using namespace std;

struct link
{
	int data;
	link *next;
};

class linklist
{
	link *first;
	
	public:
		linklist()
		{
			first=NULL;
		}
		
		void insertcontent (int d)
		{
			link *n=new link;
			n->data=d;
			n->next=first;
			first=n;
		}
		
		void deletecontent()
		{
			
			while(first!=NULL)
			{
				link *t;
				t=first;
				first=first->next;
				delete t;
			}
		}
		
		void display()
		{
			while(first!=NULL)
			{
				cout<<first->data;
				first=first->next;
				cout<<"\n";
			}
		}
};

main()
{
	linklist obj;
	obj.insertcontent(10);
	obj.insertcontent(20);
	obj.insertcontent(30);
	obj.insertcontent(40);
	obj.display();
	obj.deletecontent();
	return 0;
}



#include<iostream>
#include<math.h>
using namespace std;

class polygon
{
	public:
		virtual void input()=0;
		virtual void area()=0;
		virtual void perimeter()=0;
};

class triangle:public polygon
{
	float s1,s2,s3,s,a,pm;
	
	public:
		void input()
		{
			cout<<"Enter the sides of the triangle\ns1="; cin>>s1;
			cout<<"s2="; cin>>s2;
			cout<<"s3="; cin>>s3;
		}
		
		void area()
		{
			s=((s1+s2+s3)/2.0);
			a=sqrt(s*(s-s1)*(s-s2)*(s-s3));	
			cout<<"\nArea of the Triangle="<<a;	
		}	                               
		
		void perimeter()
		{
			pm=s1+s2+s3;
			cout<<"\nPerimeter of Triangle="<<pm<<"\n";
		}                                                                                                                                                        
};

class rectangle:public polygon
{
	float l,b,a,pm;
	
	public:
		void input()
		{
			cout<<"Enter the sides of the rectangle\nL="; cin>>l;
			cout<<"B="; cin>>b;
		}
		
		void area()
		{
			a=l*b;
			cout<<"\nArea of the Rectangle="<<a;	
		}
		
		void perimeter()
		{
			pm=(2*(l+b));
			cout<<"\nPerimeter of Rectangle="<<pm<<"\n";
		}	                  	
};

class square:public polygon
{
	float l,a,pm;

	public:
		
		void input()
		{
			cout<<"Enter the side of the square\nL="; cin>>l;
		}
			
		void area()
		{
			a=l*l;
			cout<<"\nArea of the Square="<<a;	
		}	
		
		void perimeter()
		{
			pm=4*l;
			cout<<"\nPerimeter of Square="<<pm<<"\n";
		}	             
};

main()
{
	triangle t,*p1;
	rectangle r,*p2;
	square sq,*p3;
	int opt;
	char loop='y';
	
	while(loop=='y'||loop=='Y')
	{
			
		cout<<"\nSelect an option\n1.Triangle\n2.Rectangle\n3.Square\nOption=";
		cin>>opt;
	
		switch(opt)
		{
			case 1:
				p1=&t;
				p1->input();
				p1->area();
				p1->perimeter();
				break;
			
			case 2:
				p2=&r;
				p2->input();
				p2->area();
				p2->perimeter();
				break;
			
			case 3:
				p3=&sq;
				p3->input();
				p3->area();
				p3->perimeter();
				break;
			
			default:
				cout<<"\nInvalid Selection\n";
			
		}
		
		cout<<"\nDo you want to continue(y/n):";
		cin>>loop;
	}
	
return 0;
}



#include<iostream>
using namespace std;

class Student
{
	protected:
	int usn,age;
	char name[20];

};

class Ug : public Student
{
	int sem,fee,sti;

	public:
	void getdata()
	{
		cout<<"\nEnetr Usn , Name , Age : ";
		cin>>usn>>name>>age;
		cout<<"\nEnter Sem,Fee,Stipend : ";
		cin>>sem>>fee>>sti;
	}

	void display()
	{
		cout<<name<<"\t"<<age<<"\t"<<sem<<"\n";
	}

	int getsem()
	{
		return(sem);
	}

	int getage()
	{
		return(age);
	}

};

class Pg : public Student
{
	int sem,fee,sti;

	public:
	void getdata()
	{
		cout<<"\nEnetr Usn , Name , Age : ";
		cin>>usn>>name>>age;

		cout<<"\nEnter Sem,Fee,Stipend : ";
		cin>>sem>>fee>>sti;
	}

	void display()
	{
		cout<<name<<"\t"<<age<<"\t"<<sem<<"\n";
	}

	int getsem()
	{
		return(sem);
	}

	int getage()
	{
		return(age);
	}

};

int main()
{

	Pg p[2];
	Ug u[2];

	int flag,age,sem,agesum=0,semcnt=0,j,i;

	cout<<"\n\nEnter Pg students details..\n";
	for(i=0; i<2; i++ )
		p[i].getdata();

	cout<<"\n\nEnter Ug students details..\n";
	for(i=0; i<2; i++ )
		u[i].getdata();

	cout<<"\nUG - students details..\n";
	cout<<"--------------------------\n";
	cout<<"Name\tAge\tSem\n";
	for(i=0; i<2; i++ )
		u[i].display();
	cout<<"--------------------------\n";
	for(i=1; i<9; i++ )
	{
		flag=0;
		for(j=0; j<2; j++ )
		{
			sem=u[j].getsem();
			age=u[j].getage();

			if( i==sem )
			{
				agesum+=age;
				semcnt++;
				flag=1;
			}
		}
	if(flag)
	   cout<<i<<"\t"<<agesum/semcnt<<endl;
}

	agesum=0,semcnt=0;

	cout<<"\n\nPG - students details..\n";
	cout<<"--------------------------\n";
	cout<<"Name\tAge\tSem\n";
	for(i=0; i<2; i++ )
		p[i].display();
	cout<<"--------------------------\n";
	for(i=1; i<9; i++ )
	{
		flag=0;
		for(j=0; j<2; j++ )
		{
			sem=p[j].getsem();
			age=p[j].getage();

			if( i==sem )
			{
				agesum+=age;
				semcnt++;
				flag=1;
			}
		}
			if(flag)
			cout<<i<<"\t"<<agesum/semcnt<<endl;
	}

	return 0;

}




#include<iostream>
using namespace std;

struct dob
{
	int d,m,y;
};

class person
{
	protected:
		char name[50];
		int age;
};

class account:virtual public person
{
	protected:
		float acno;	
};

class admin:virtual public person
{
	protected:
			dob dd;
};

class master:public account,admin
{
	public:
		void input();
		void display();
		int update(float,int);
}m[10];

void master::input()
{
	cout<<"Enter the name:"; 
	cin>>name;
	
	cout<<"Enter the age:"; 
	cin>>age;
	
	cout<<"Enter the account number:"; 
	cin>>acno;
	
	cout<<"Enter your date of birth\nd:"; 
	cin>>dd.d;
	
	cout<<"m:"; 
	cin>>dd.m;
	
	cout<<"y:";
 	cin>>dd.y;
}

void master::display()
{
	cout<<name;
	cout<<"\t"<<age;
	cout<<"\t"<<acno;
	cout<<"\t"<<dd.d<<"/"<<dd.m<<"/"<<dd.y<<"\n";
}

int master::update(float ac,int size)
{
	int pos=0;
	
	for(int i=0;i<size;i++)
	{
		if(m[i].acno==ac)
		{
			pos=i;
			break;
		}
		else 
			pos=-1;
	}
	return pos;		
}

void tabb()
{
	cout<<"\nName\tage\taccno\tDOB\n";
	cout<<"____\t___\t_____\t___\n";
}

main()
{
	int s=0,i,opt,p;
	char loop='y';
	float acc;
	master u;
	while(loop=='y'||loop=='Y')
	{
		cout<<"1.Input\n2.Display\n3.Update\nOption:";
		cin>>opt;
		
		switch(opt)
		{
			case 1:
				cout<<"Enter the total number of inputs:";
				cin>>s;
				cout<<"Enter the details...\n";
					for(i=0;i<s;i++)
						m[i].input();
				break;
					
			case 2:
				tabb();
				for(i=0;i<s;i++)
					m[i].display();	
				break;
				
			case 3:
				cout<<"Enter the accno:";
				cin>>acc;
				p=u.update(acc,s);
				if(p!=-1)
				{
					cout<<"\nEnter the new details\n";
					m[p].input();
				}
				else	
					cout<<"\n...Invalid...\n";
				break;
				
			default:
				cout<<"...Invalid Option...\n";
				break;			
		}		
		cout<<"\nDo you want to continue(y/n):";
		cin>>loop;
	}
return 0;
}



#include<iostream>
using namespace std;
struct dob
{
	int d,m,y;	
};

class student
{
	protected:
		char name[50];
		dob dd;
		int rno;
	
	public:
		virtual void getdata()=0;
		virtual void displayresult()=0;	
					
};

class pg:public student
{
	public:
		void getdata()
		{
			cout<<"Enter the data of PG student\n";
			cout<<"Enter the name:"; cin>>name;
			
			cout<<"Enter the date of birth:\nd="; cin>>dd.d;
			cout<<"m="; cin>>dd.m;
			cout<<"y="; cin>>dd.y;
			
			cout<<"Enter the roll number:"; cin>>rno;
		}	
		
		void displayresult()
		{
			cout<<"\nData of PG student\n";
			cout<<"..................\n";
			
			cout<<"Name:"<<name;
			cout<<"\nDate of birth:"<<dd.d<<"/"<<dd.m<<"/"<<dd.y;
			cout<<"\nRoll Number:"<<rno<<"\n";
		}	
};

class ug:public student
{
	public:
		void getdata()
		{
			cout<<"Enter the data of UG student\n";
			cout<<"Enter the name:"; cin>>name;
			
			cout<<"Enter the date of birth:\nd="; cin>>dd.d;
			cout<<"m="; cin>>dd.m;
			cout<<"y="; cin>>dd.y;
			
			cout<<"Enter the roll number:"; cin>>rno;
		}
		
		void displayresult()
		{
			cout<<"\nData of UG student\n";
			cout<<"..................\n";
			
			cout<<"Name:"<<name;
			cout<<"\nDate of birth:"<<dd.d<<"/"<<dd.m<<"/"<<dd.y;
			cout<<"\nRoll Number:"<<rno<<"\n";
		}			
};

main()
{
	pg p,*ptr1;
	ug u,*ptr2;
	
	ptr1=&p;
	ptr2=&u;
	
	ptr1->getdata();
	ptr2->getdata();
	ptr1->displayresult();
	ptr2->displayresult();
	
	return 0;
}



