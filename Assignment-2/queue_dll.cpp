/*
	Authored by:-
	Anirudh Swaminathan 102115004 - Chemical 2nd year - 4th semester
	Abhinandan Nabera 102115038 - Chemical 2nd year - 4th semester

	This code is for implementing queue using doubly linked lists

	This is a part of the programming assignment 2 given to students who opted to do Minors in CS in NIT-Trichy
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Queue
{
	struct Node
	{
		int data;
		Node *next, *prev;
	};
	Node *head, *tail;
	
public:
	//Constructor
	Queue()
	{
		head = NULL;
		tail = NULL;
	}
	
	//Modifiers
	void enqueue(int val)
	{
		Node *new_node = new Node;
		if(!new_node)
		{
			cerr<<"\nMemory cannot be allocated\n";
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
		cout<<"\n"<<val<<" successfully added to the queue";
		return;
	}
	
	int dequeue()
	{
		Node *temp;
		int ret = 0;
		if(head == NULL && tail == NULL)
		{
			cerr<<"\nQueue underflow!!\n";
			return 0;
		}
		ret = tail->data;
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
			temp = tail;
			tail = tail->prev;
			temp->prev = NULL;
			tail->next = NULL;
			delete temp;
			temp = NULL;
		}
		return ret;
	}
	
	//Inspectors
	void display()
	{
		Node *temp = tail;
		if(temp == NULL)
		{
			cerr<<"\nQueue empty\n";
			return;
		}
		cout<<"\nPrinting queue contents\n";
		while(temp)
		{
			cout<<temp->data<<" ";
			temp = temp->prev;
		}
		cout<<endl;
		return;
	}
	
	//Destructor
	~Queue()
	{
		cerr<<"\nDestructor called";
		Node *temp = head;
		while(temp)
		{
			cout<<"\nDeleting "<<head->data<<" from the queue";
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
	Queue aqueue;
	int choice;
	int val;
	do
	{
		cout<<"\n1. Enqueue\n2. Dequeue\n3. Display contents of queue\n4. Quit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter integer to store in queue:\t";
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
