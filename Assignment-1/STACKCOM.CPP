#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

class stack
{
	public:

	int stck[10];
	int top;
	int max_size;

	stack()
	{
		top = -1;
	}

	void push()
	{
		int element;
		if(top == max_size - 1)
		{
			cout<<"Stack full.\n";
			return;
		}
		else
		{
			cout<<"Enter element to push: ";
			cin>>element;
			top = top + 1;
			stck[top] = element;
		}
	}

	void pop()
	{
		if(top == -1)
		{
			cout<<"Stack empty.\n";
			return;
		}
		else
		{
			cout<<"Deleted element: "<<stck[top]<<"\n";
			top = top - 1;
		}
	}
}

main()
{
	clrscr();
	int option,count = 0;
	stack st1, st2;
	cout<<"Enter stack 1 details: ";
	cout<<"\nEnter stack 1 size: ";
	cin>>st1.max_size;
	while(1)
	{
		cout<<"Enter option: 1. Push 2. Pop 3. Submit stack: ";
		cin>>option;
		if(option == 1)
		{
			st1.push();
		}
		else if(option == 2)
		{
			st1.pop();
		}
		else if(option == 3)
		{
			cout<<"Stack 1 registered sucessfully.";
			break;
		}
	}
	cout<<"\nEnter stack 2 details: ";
	cout<<"\nEnter stack 2 size: ";
	cin>>st2.max_size;
	while(1)
	{
		cout<<"Enter option. 1.Push 2.Pop 3. Submit stack: ";
		cin>>option;
		if(option == 1)
		{
			st2.push();
		}
		else if(option == 2)
		{
			st2.pop();
		}
		else if(option == 3)
		{
			cout<<"Stack 2 registered sucessfully.";
			break;
		}
	}
	cout<<"\nDo you want to start comparing? 1. Yes 2. No: ";
	cin>>option;
	if(option == 1)
	{
		if(st1.top != st2.top)
			cout<<"Size of the stacks are not equal.";
		else
		{
		    for(int i = 0; i <= st1.top; i++)
		    {
			if(st1.stck[i] == st2.stck[i])
				count = count + 1;
			else
				cout<<"Stacks are not equal.";
		    }
		    if(count == st1.top + 1)
			cout<<"Stacks are equal.";
		}
	}
	else if(option == 2)
	{
		exit(0);
	}
	getch();
}