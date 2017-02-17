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
		cout<<"\n1. Push to stack\n2. Pop from stack\n3. Display contents of stack\n4. Quit\n";
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
				astack.display();
				break;
			case 4:
				cout<<"\nQuitting program\n";
				break;
			default:
				cout<<"\nWrong choice. Quitting program\n";
				choice = 4;
		}
	} while(choice!=4);
	return 0;
}
