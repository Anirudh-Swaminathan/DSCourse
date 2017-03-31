#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack
{
	struct Node
	{
		int data;
		Node *next;
	};
	Node *top;
public:
	// Constructor
	Stack()
	{
		top = NULL;
	}
	
	// Modifiers
	void push(int val)
	{
		Node *new_node = new Node;
		if(!new_node)
		{
			cerr<<"\nMemory allocation failure\n";
			return;
		}
		new_node->data = val;
		new_node->next = top;
		top = new_node;
		cout<<"\n"<<val<<" successfully added to the stack";
		return;
	}
	
	int pop()
	{
		Node* temp;
		int ret = 0;
		if(top == NULL)
		{
			cerr<<"\nStack underflow!!\n";
			return 0;
		}
		temp = top;
		top = top->next;
		ret = temp->data;
		temp->next = NULL;
		delete temp;
		temp = NULL;
		return ret;
	}
	
	void reverse()
	{
		if(!top)
		{
			cerr<<"\nStack empty!!\n";
			return;
		}
		if(!(top->next))
		{
			cout<<"\n1 element only is present";
			return;
		}
		Node *p, *q, *r;
		p = q = r = top;
		p = p->next->next;
		q = q->next;
		r->next = NULL;
		q->next = r;
		while(p)
		{
			r = q;
			q = p;
			p = p->next;
			q->next = r;
		}
		top = q;
		cout<<"\nThe contents of the stack has been reversed\n";
		return;
	}
	
	// Inspectors
	void display()
	{
		Node* temp;
		if(top == NULL)
		{
			cerr<<"\nStack empty!!\n";
			return;
		}
		temp = top;
		cout<<"\nPrinting stack contents\n";
		while(temp)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
		return;
	}
	
	// Destructor
	~Stack()
	{
		cerr<<"\nDestructor called";
		Node* temp = top;
		while(temp)
		{
			cout<<"\nDeleting "<<top->data<<" from the stack";
			top = top->next;
			delete temp;
			temp = top;
		}
		cout<<endl;
	}
};

int main()
{
	Stack astack;
	int choice;
	int val;
	do
	{
		cout<<"\n1. Push to stack\n2. Pop from stack\n3. Reverse the stack\n4. Display contents of stack\n5. Quit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter integer to push to stack:\t";
				cin>>val;
				astack.push(val);
				break;
			case 2:
				cout<<"\nThe element that was popped from the stack is "<<astack.pop();
				break;
			case 3:
				astack.reverse();
				break;
			case 4:
				astack.display();
				break;
			case 5:
				cout<<"\nQuitting program\n";
				break;
			default:
				cout<<"\nWrong choice. Quitting program\n";
				choice = 5;
		}
	} while(choice!=5);
	return 0;
}
