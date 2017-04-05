/*
	Authored by:-
	Anirudh Swaminathan 102115004 - Chemical 2nd year - 4th semester
	Abhinandan Nabera 102115038 - Chemical 2nd year - 4th semester

	This code is for reversing doubly linked lists

	This is a part of the programming assignment 2 given to students who opted to do Minors in CS in NIT-Trichy
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DLL
{
	struct Node
	{
		int data;
		Node *next, *prev;
	};
	Node *head, *tail;
	
	// Private Modifiers for the DLL
	void insertBeg(int val)
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
		cout<<"\n"<<val<<" successfully inserted at the beginning";
		return;
	}
	
	void insertEnd(int val)
	{
		Node *new_node = new Node;
		if(!new_node)
		{
			cerr<<"\nMemory cannot be allocated!!\n";
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
			new_node->prev = tail;
			new_node->next = NULL;
			tail->next = new_node;
			tail = new_node;
		}
		cout<<"\n"<<val<<" successfully inserted at the end";
		return;
	}
	
	void insertAfter(int val, int afterVal)
	{
		Node *new_node = new Node;
		if(!new_node)
		{
			cerr<<"\nMemory cannot be allocated!!\n";
			return;
		}
		if(head == NULL && tail == NULL)
		{
			new_node->data = val;
			new_node->next = NULL;
			new_node->prev = NULL;
			head = new_node;
			tail = new_node;
			cout<<"\n"<<val<<" inserted successfully";
			return;
		}
		new_node->data = val;
		Node *temp = head;
		bool found = false;
		while(temp)
		{
			if(temp->data == afterVal)
			{
				found = true;
				break;
			}
			temp = temp->next;
		}
		if(!found)
		{
			cerr<<"\n"<<afterVal<<" was not found in the doubly linked list!\n";
			return;
		}
		new_node->next = temp->next;
		new_node->prev = temp;
		if(temp->next) temp->next->prev = new_node;
		else tail = new_node;
		temp->next = new_node;
		cout<<"\n"<<val<<" inserted successfully after "<<afterVal;
		return;
	}
	
	void insertBefore(int val, int beforeVal)
	{
		Node *new_node = new Node;
		if(!new_node)
		{
			cerr<<"\nMemory cannot be allocated!!\n";
			return;
		}
		if(head == NULL && tail == NULL)
		{
			new_node->data = val;
			new_node->next = NULL;
			new_node->prev = NULL;
			head = new_node;
			tail = new_node;
			cout<<"\n"<<val<<" inserted successfully";
			return;
		}
		new_node->data = val;
		Node *temp = head;
		bool found = false;
		while(temp)
		{
			if(temp->data == beforeVal)
			{
				found = true;
				break;
			}
			temp = temp->next;
		}
		if(!found)
		{
			cerr<<"\n"<<beforeVal<<" was not found in the doubly linked list!\n";
			return;
		}
		new_node->next = temp;
		new_node->prev = temp->prev;
		if(temp->prev) temp->prev->next = new_node;
		else head = new_node;
		temp->prev = new_node;
		cout<<"\n"<<val<<" inserted successfully before "<<beforeVal;
		return;
	}
	
	int deleteBeg()
	{
		Node *temp;
		int ret = 0;
		if(head == NULL && tail == NULL)
		{
			cerr<<"\nDLL underflow!!\n";
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
	
	int deleteEnd()
	{
		Node *temp;
		int ret = 0;
		if(head == NULL && tail == NULL)
		{
			cerr<<"\nDLL underflow!!\n";
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
	
	int deleteAfter(int afterVal)
	{
		Node *temp = head;
		int ret = 0;
		if(head == NULL && tail == NULL)
		{
			cerr<<"\nDLL underflow!!\n";
			return 0;
		}
		if(head == tail)
		{
			cerr<<"\nOnly 1 element!!";
			return 0;
		}
		if(tail->data == afterVal)
		{
			cerr<<"\n"<<afterVal<<" is the last element";
			return 0;
		}
		bool found = false;
		while(temp)
		{
			if(temp->data == afterVal)
			{
				found = true;
				break;
			}
			temp = temp->next;
		}
		if(!found)
		{
			cerr<<"\n"<<afterVal<<" was not found in the doubly linked list!\n";
			return 0;
		}
		if(temp->next->next == NULL)
		{
			ret = deleteEnd();
			return ret;
		}
		Node *dele = temp->next;
		ret = dele->data;
		temp->next = dele->next;
		dele->next->prev = temp;
		dele->prev = NULL;
		dele->next = NULL;
		delete dele;
		dele = NULL;
		temp = NULL;
		return ret;
	}
	
	int deleteBefore(int beforeVal)
	{
		Node *temp = head;
		int ret = 0;
		if(head == NULL && tail == NULL)
		{
			cerr<<"\nDLL underflow!!\n";
			return 0;
		}
		if(head == tail)
		{
			cerr<<"\nOnly 1 element!!";
			return 0;
		}
		if(head->data == beforeVal)
		{
			cerr<<"\n"<<beforeVal<<" is the first element";
			return 0;
		}
		bool found = false;
		while(temp)
		{
			if(temp->data == beforeVal)
			{
				found = true;
				break;
			}
			temp = temp->next;
		}
		if(!found)
		{
			cerr<<"\n"<<beforeVal<<" was not found in the doubly linked list!\n";
			return 0;
		}
		if(temp->prev->prev == NULL)
		{
			ret = deleteBeg();
			return ret;
		}
		Node *dele = temp->prev;
		ret = dele->data;
		temp->prev = dele->prev;
		dele->prev->next = temp;
		dele->next = NULL;
		dele->prev = NULL;
		delete dele;
		dele = NULL;
		temp = NULL;
		return ret;
	}
	
public:
	//Constructor
	DLL()
	{
		head = NULL;
		tail = NULL;
	}
	
	// Modifiers
	void insert()
	{
		int ch;
		cout<<"\nChoose mode of insertion";
		cout<<"\n1. Insert at beginning\n2. Insert at end\n3. Insert after\n4. Insert before\n\n";
		cin>>ch;
		int val, nexval;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the value to insert at the beginning: ";
				cin>>val;
				insertBeg(val);
				break;
			case 2:
				cout<<"\nEnter the value to insert at the end: ";
				cin>>val;
				insertEnd(val);
				break;
			case 3:
				cout<<"\nEnter the value to insert: ";
				cin>>val;
				cout<<"\nEnter the value after which "<<val<<" has to be inserted: ";
				cin>>nexval;
				insertAfter(val, nexval);
				break;
			case 4:
				cout<<"\nEnter the value to insert: ";
				cin>>val;
				cout<<"\nEnter the value before which "<<val<<" has to be inserted: ";
				cin>>nexval;
				insertBefore(val, nexval);
				break;
			default:
				cerr<<"\n\nWrong Option!! Aborting Insertion!!\n";
				break;
		}
		return;
	}
	
	int delet()
	{
		int ret = -1;
		int ch, nexval;
		cout<<"\nChoose the mode of deletion";
		cout<<"\n1. Delete head\n2. Delete Tail\n3. Delete after\n4. Delete Before\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				ret = deleteBeg();
				break;
			case 2:
				ret = deleteEnd();
				break;
			case 3:
				cout<<"\nEnter the value after which element has to be deleted: ";
				cin>>nexval;
				ret = deleteAfter(nexval);
				break;
			case 4:
				cout<<"\nEnter the value before which element has to be deleted: ";
				cin>>nexval;
				ret = deleteBefore(nexval);
				break;
			default:
				cerr<<"\n\nWrong Option!! Aborting Deletion!!\n";
				break;
		}
		return ret;
	}
	
	// Reverse the DLL
	void reverse()
	{
		if(head!=NULL)
		{
			Node*t=head;
			tail = head;
			while(t->next!=NULL)
			{
				Node*s;
				s=t->next;
				t->next=t->prev;
				t->prev=s;
				t=t->prev;
			}
			head=t;
			t->next=t->prev;
			t->prev=NULL;
			t=t->prev;
		}
		return;
	}
	
	// Inspectors
	void display()
	{
		Node *temp = head;
		if(temp == NULL)
		{
			cerr<<"\nDLL empty\n";
			return;
		}
		cout<<"\nPrinting DLL contents\n";
		while(temp)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
		return;
	}
	
	// Destructor
	~DLL()
	{
		cerr<<"\nDestructor called";
		Node *temp = head;
		while(temp)
		{
			cout<<"\nDeleting "<<head->data<<" from the DLL";
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
	DLL dll;
	int choice;
	int val;
	do
	{
		cout<<"\n1. Insert element\n2. Delete element\n3. Display contents of DLL\n4. Reverse the DLL\n5. Quit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				dll.insert();
				break;
			case 2:
				cout<<"\nThe element deleted from the DLL is "<<dll.delet();
				break;
			case 3:
				dll.display();
				break;
			case 4:
				dll.reverse();
				cout<<"\nReversed the DLL";
				dll.display();
				break;
			case 5:
				cout<<"\nQuitting program\n";
				break;
			default:
				cout<<"\nWrong choice. Quitting program\n";
				choice = 5;
		}
		cout<<"\n========================================================================\n";
	} while(choice!=5);
	return 0;
}

