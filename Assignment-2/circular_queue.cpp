/*
	Authored by:-
	Anirudh Swaminathan 102115004 - Chemical 2nd year - 4th semester
	Abhinandan Nabera 102115038 - Chemical 2nd year - 4th semester

	This code is for implementing circular queue using linked lists

	This is a part of the programming assignment 2 given to students who opted to do Minors in CS in NIT-Trichy
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class CQueue
{
	struct Node
	{
		int data;
		Node *next;
	};	
	Node *head, *tail;
	
public:
	
	// Constructor
	CQueue()
	{
		head = NULL;
		tail = NULL;
	}
	
	// Modifiers
	void enqueue(int val)
	{
		Node *new_node = new Node;
		if(!new_node)
		{
			cerr<<"\nMemory allocation failure!\n";
			return;
		}
		new_node->data = val;
		if(head == NULL && tail == NULL)
		{
			new_node->next = NULL;
			head = new_node;
			tail = new_node;
			tail->next = head;
		}
		else
		{
			tail->next = new_node;
			new_node->next = head;
			tail = new_node;
		}
		cout<<"\n"<<val<<" successfully added to the queue";
		return;
	}
	
	int dequeue()
	{
		int ret = -1;
		if(tail == NULL && head == NULL)
		{
			cerr<<"\nQueue underflow!!\n";
			return ret;
		}
		if(head == tail)
		{
			ret = head->data;
			tail = NULL;
			delete head;
			head = NULL;
			return ret;
		}
		ret = head->data;
		Node *temp = head;
		head = head->next;
		tail->next = head;
		temp->next = NULL;
		delete temp;
		temp = NULL;
		return ret; 
	}
	
	// Inspectors
	void display()
	{
		Node *temp = head;
		if(temp == NULL)
		{
			cerr<<"\nQueue empty\n";
			return;
		}
		cout<<"\nPrinting circular queue contents\n";
		while(temp != tail)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<tail->data<<"\n";
		return;
	}
	
	// Destructor
	~CQueue()
	{
		cerr<<"\nDestructor called";
		Node *temp = head;
		if(head == NULL && tail == NULL) return;
		tail->next = NULL;
		tail = NULL;
		while(temp)
		{
			cout<<"\nDeleting "<<head->data<<" from the circular queue";
			head = head->next;
			temp->next = NULL;
			delete temp;
			temp = head;
		}
		return;
	}
	
};

int main()
{
	CQueue aqueue;
	int choice;
	int val;
	do
	{
		cout<<"\n1. Enqueue\n2. Dequeue\n3. Display contents of queue\n4. Quit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter integer to store in circular queue:\t";
				cin>>val;
				aqueue.enqueue(val);
				break;
			case 2:
				cout<<"\nThe element that was dequeued was "<<aqueue.dequeue();
				break;
			case 3:
				aqueue.display();
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
