#include<iostream>
#include<math.h>
using namespace std;
class A
{

public:float a, b, c;
	   virtual void getdata(int, int, int)
	   {
	   }
	   virtual  void display()

	   {
	   }
	   virtual float area() = 0;
};
class B :public A
{
public:
	void getdata(int p, int q, int r)
	{
		a = p; b = q;
	}
	float area()
	{
		return a*a;
	}
	void display()
	{
		cout << area() << "\n";
	}

};
class C :public A{
public:
	void getdata(int p, int q, int r)
	{
		a = p;
	}
	float area()
	{

		return (3.14*a*a);
	}
	void display()
	{
		cout << area();
	}

};
class D :public A
{
public:
	void getdata(int p, int q, int r)
	{
		a = p; b = q; c = r;
	}
	float area()
	{
		float s;
		s = (a + b + c) / 2;
		return(sqrt(s*(s - a)*(s - b)*(s - c)));

	}
	void display()
	{
		cout << area();
	}


};
int main()
{
	A*a; int n; B b; C c; D d;
	cout << "choice\n";
	cin >> n;
	switch (n){
	case 1:a = &b; a->getdata(1, 2, 3); a->display();
		cout << a->area(); break;
	case 2:a = &c; a->getdata(1, 2, 3); a->display();
		cout << a->area(); break;
	case 3:a = &d; a->getdata(1, 2, 3); a->display();
		cout << a->area(); break;
	}
	getchar(); getchar();
	return 0;

}
