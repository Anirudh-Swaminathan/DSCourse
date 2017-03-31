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
		cout<<"\n1. Enqueue\n2. Dequeue\n3. Display contents of queue\n4. Quit\n";
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
				q.display();
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
