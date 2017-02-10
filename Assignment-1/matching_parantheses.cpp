/*
	Authored by:-
	Anirudh Swaminathan 102115004 - Chemical 2nd year - 4th semester
	Abhinandan Nabera 102115038 - Chemical 2nd year - 4th semester

	This code is for the problem of finding whether an input expression is valid by only checking if its
	parantheses are balanced.

	This is a part of the programming assignment 1 given to students who opted to do Minors in CS in NIT-Trichy
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101

// My Structure
struct Stack
{
	char sta[MAX_SIZE];
	int top;

	// Constructor
	Stack()
	{
		top = -1;
	}

	// Modifiers
	void push(char element)
	{
		if(top==MAX_SIZE-1) cout<<"Stack Overflow!!"<<endl;
		else
		{
			top++;
			sta[top] = element;
		}
	}

	char pop()
	{
		char ret = '\0';
		if(top == -1) cout<<"Stack is empty"<<endl;
		else
		{
			ret = sta[top];
			top--;
		}
		return ret;
	}

	// Inspectors
	void display()
	{
		if(top == -1) cout<<"Stack Underflow";
		else
		{
			cout<<"\nPrinting the stack"<<endl;
			for (int i=top; i>=0; --i)
			{
				cout<<sta[i]<<" ";
			}
			cout<<endl;
		}
	}

	int size()
	{
		return top+1;
	}
};

int main()
{
	Stack astack;
	char input[MAX_SIZE];
	cout<<"\nPlease enter only parantheses statement to check for matching parantheses\n";
	cin.getline(input, MAX_SIZE);
	cout<<"\nEntered expression is "<<input<<endl;
	bool matches = true;
	for(int i=0; i<strlen(input); ++i)
	{
		//cout<<"Curr char is "<<input[i]<<endl;
		if(input[i] == '(')
		{
			astack.push(input[i]);
			//cout<<sta.size()<<endl;
		}
		else if(input[i] == ')')
		{
			if(astack.size() == 0)
			{
				matches = false;
				break;
			}
			char ch = astack.pop();
		}
	}
	if(astack.size() == 0 && matches) cout<<"\nThe parantheses are balanced\n";
	else cout<<"\nThe parantheses are unbalanced\n";
	return 0;
}
