#include<iostream>
using namespace std;
struct link
{
	int data;
	link *next;
};
class linklist
{
	private:
	link *first;
	public:
	linklist()
	{
		first=NULL;
		void additem(int d);
		void deleteitem();
		void display();
	};
	void linklist::additem(int d)
	{
		link *nl=new link;
		nl->data=d;
		nl->next=first;
		first=nl;
	}
	void linklist::deleteitem()
	{
		link *temp=first;
		first=first->next;
		delete temp;
	}
	void linklist::display()
	{
		link *current=first;
		while(current!=NULL)
		{
			cout<<current->data<<"\t";current=current->next;
		}
	}
};
int main()
{
	linklist li;
	li.additem(25);
	li.additem(35);
	li.additem(45);
	li.additem(56);
	li.display();
	cout<<"\n After Deletion \n";
	li.deleteitem();
	li.display();
	return 0;
}




