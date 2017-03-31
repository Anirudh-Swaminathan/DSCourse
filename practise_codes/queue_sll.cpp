#include <iostream>
using namespace std;
class Queue
{
	struct Node
	{
		int data;
		Node* next;
	};
	Node* head, *tail;
public:
	// Constructor
	Queue()
	{
		head = NULL;
		tail = NULL;
	}
	
	// Modifiers
	void enqueue(int val)
	{
		Node* new_node = new Node;
		if(!new_node)
		{
			cerr<<"\nMemory allocation failure\n";
			return;
		}
		new_node->data = val;
		new_node->next = NULL;
		if(head == NULL && tail == NULL)
		{
			head = new_node;
			tail = new_node;
			return;
		}
		tail->next = new_node;
		tail = new_node;
		cout<<"\n"<<val<<" successfully added to the stack";
		return;
	}
	int dequeue()
	{
		Node* temp;
		int ret  = 0;
		if(head == NULL && tail == NULL)
		{
			cerr<<"\nQueue underflow!!\n";
			return 0;
		}
		temp = head;
		head = head->next;
		ret = temp->data;
		temp->next = NULL;
		delete temp;
		temp = NULL;
		if(head == NULL) tail = NULL;
		return ret;
	}
	
	void reverse()
	{
		if(!head)
		{
			cerr<<"\nQueue empty!!\n";
			return;
		}
		if(!(head->next))
		{
			cout<<"\n1 element only is present";
			return;
		}
		Node *p, *q, *r;
		p = q = r = head;
		p = p->next->next;
		q = q->next;
		r->next = NULL;
		q->next = r;
		tail = r;
		while(p)
		{
			r = q;
			q = p;
			p = p->next;
			q->next = r;
		}
		head = q;
		q = NULL;
		r = NULL;
		cout<<"\nThe contents of the queue has been reversed\n";
		return;
	}
	
	//Inspectors
	void display()
	{
		Node* temp;
		if(head == NULL && tail == NULL)
		{
			cerr<<"\nQueue empty!!\n";
			return;
		}
		temp = head;
		cout<<"\nPrinting queue contents\n";
		while(temp)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
		return;
	}
	
	// Destructor
	~Queue()
	{
		cerr<<"\nDestructor called";
		Node* temp = head;
		while(temp)
		{
			cout<<"\nDeleting "<<head->data<<" from the queue";
			head = head->next;
			delete temp;
			temp = head;
		}
		if(!head) tail = NULL;
		cout<<endl;
	}
};

int main()
{
	Queue q;
	int choice;
	int val;
	do
	{
		cout<<"\n1. Enqueue\n2. Dequeue\n3. Reverse Queue\n4. Display contents of queue\n5. Quit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter integer to enqueue:\t";
				cin>>val;
				q.enqueue(val);
				break;
			case 2:
				cout<<"\nThe element that was dequeued is "<<q.dequeue();
				break;
			case 3:
				q.reverse();
				break;
			case 4:
				q.display();
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
