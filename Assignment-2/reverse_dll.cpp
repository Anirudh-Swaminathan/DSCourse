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
	
public:
	//Constructor
	DLL()
	{
		head = NULL;
		tail = NULL;
	}
	
	// Modifiers
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
			cerr<<"\n"<<beforeVal<<" was not found in the doubly linked list!\n";
			return;
		}
		new_node->next = temp;
		new_node->prev = temp->prev;
		if(temp->prev) temp->prev->next = new_node;
		else head = new_node;
		temp->prev = new_node;
		return;
	}
	
	int deleteBeg()
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
	
	int deleteEnd()
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
	
	int deleteAfter(int afterVal)
	{
		
	}
};

int main()
{
	return 0;
}

