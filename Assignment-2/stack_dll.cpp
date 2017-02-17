#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack
{
	struct Node
	{
		int data;
		Node *prev, *next;
	};
	Node *head, *tail;
public:
	// Constructor
	Stack()
	{
		head = NULL;
		tail = NULL;
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
		if(head == NULL && tail == NULL)
		{
			new_node->data = val;
			new_node->next = NULL;
			new_node->prev = NULL;
			head = new_node;
			tail = new_node;
		}
		else
		{
			new_node->data = val;
			new_node->next = head;
			new_node->prev = NULL;
			head->prev = new_node;
			head = new_node;
		}
		cout<<"\n"<<val<<" successfully added to the stack";
		return;
	}
	
	int pop()
	{
		Node *temp;
		int ret = 0;
		if(head == NULL && tail == NULL)
		{
			cerr<<"\nStack underflow!!\n";
			return 0;
		}
		ret = head->data;
		if(head == tail)
		{
			tail = NULL;
			temp = head;
			head = NULL;
			delete temp;
			temp = NULL;
		}
		else
		{
			temp = head;
			head = head->next;
			temp->next = NULL;
			head->prev = NULL;
			delete temp;
			temp = NULL;
		}
		return ret;
	}
	
	// Inspectors
	void display()
	{
		Node *temp = head;
		if(temp == NULL)
		{
			cerr<<"\nStack empty\n";
			return;
		}
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
		Node *temp = head;
		while(temp)
		{
			cout<<"\nDeleting "<<head->data<<" from the stack";
			if(head == tail)
			{
				tail = NULL;
				head = NULL;
				delete temp;
				temp = NULL;
			}
			else
			{
				head = head->next;
				temp->next = NULL;
				head->prev = NULL;
				delete temp;
				temp = head;
			}
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
