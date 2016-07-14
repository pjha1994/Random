#include<iostream>
using namespace std;
void main()
{
	char k,a[100],b[100]; int l,m,i,j;
	cout << "hello!I am back\n\n";
	cout << "I CAN CONCATENATE,REVERSE AND COPY\n\nCHECK ME\n\n";
	cout << "enter a string\n";
	cin >>a;
	for (l = 0; a[l]!='\0'; l++);
	cout << l<<"\n\n";
	cout << "enter another string\n\n";
	cin >> b;
	for (m = 0; b[m] != '\0'; m++);
	cout << m << "\n\n";
	for (i = l, j = 0; b[j] != '\0'; i++, j++)
	{
		a[i] = b[j];
	}
	 a[i] = '\0';
	cout << "concatenated string is  "<<a<<"\n\n";
	for (l = 0; a[l] != '\0'; l++);
	for (i = 0, j = l - 1; i < l / 2; i++, j--)
	{
		k = a[i];
		a[i] = a[j];
		a[j] = k;
	}
	cout << "reversed string is " << a<<"\n\n";
	for (i = 0; a[i] != '\0'; i++)
		a[i] = b[i];

	cout << "copied string is " << a<<"\n\n"<<"GOOD BYE\n\n";
	  
	system("pause");

}
