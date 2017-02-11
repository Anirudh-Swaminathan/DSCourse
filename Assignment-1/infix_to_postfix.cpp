/*
	Authored by:-
	Anirudh Swaminathan 102115004 - Chemical 2nd year - 4th semester
	Abhinandan Nabera 102115038 - Chemical 2nd year - 4th semester

	This code is for the problem of converting an infix expression into a postfix expression using stack.

	This is a part of the programming assignment 1 given to students who opted to do Minors in CS in NIT-Trichy
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101

// My Structure
class Stack
{
private:
	char sta[MAX_SIZE];
	int tp;
	
public:
	// Constructor
	Stack()
	{
		tp = -1;
	}

	// Modifiers
	void push(char element)
	{
		if(tp==MAX_SIZE-1) cout<<"Stack Overflow!!"<<endl;
		else
		{
			tp++;
			sta[tp] = element;
		}
	}

	void pop()
	{
		if(tp == -1) cout<<"Stack is empty"<<endl;
		else tp--;
	}

	// Inspectors
	int size()
	{
		return tp+1;
	}
	
	char top()
	{
		return sta[tp];
	}
};

int main()
{
	Stack sta;
	char input[MAX_SIZE], output[MAX_SIZE];
	int ind=0;
	cout<<"\nPlease enter the infix expression to be converted into postfix\n";
	cin.getline(input, MAX_SIZE);
	cout<<"\nEntered expression is "<<input<<endl;
	for(int i=0; i<strlen(input); ++i)
	{
		if(isalnum(input[i])) output[ind++] = input[i];
		else
		{
			if(sta.size()==0 || sta.top()=='(') sta.push(input[i]);
			else if(input[i] == '(') sta.push(input[i]);
			else if(input[i] == ')')
			{
				char ch = sta.top();
				while(ch!='(')
				{
					output[ind++] = ch;
					sta.pop();
					ch = sta.top(); 
				}
				sta.pop();
			}
			else
			{
				switch(input[i])
				{
					case '^':
						sta.push(input[i]);
						break;
					case '/':
						if(sta.top() == '+' || sta.top()=='-')
						{
							sta.push(input[i]);
						}
						else if(sta.top() == '*' || sta.top() == '/')
						{
							output[ind++] = sta.top();
							sta.pop();
							sta.push(input[i]);
						}
						else if(sta.top() == '^')
						{
							while(1 && sta.size()>0 && sta.top() != '(')
							{
								char ch = sta.top();
								if(ch=='^')
								{
									output[ind++] = '^';
									sta.pop();
								}
								else if(sta.top() == '*' || sta.top() == '/')
								{
									output[ind++] = sta.top();
									sta.pop();
									break;
								}
								else if(sta.top() == '+' || sta.top()=='-')
								{
									break;
								}
							}
							sta.push(input[i]);
						}
						break;
					case '*':
						if(sta.top() == '+' || sta.top()=='-')
						{
							sta.push(input[i]);
						}
						else if(sta.top() == '*' || sta.top() == '/')
						{
							output[ind++] = sta.top();
							sta.pop();
							sta.push(input[i]);
						}
						else if(sta.top() == '^')
						{
							while(1 && sta.size()>0 && sta.top() != '(')
							{
								char ch = sta.top();
								if(ch=='^')
								{
									output[ind++] = '^';
									sta.pop();
								}
								else if(sta.top() == '*' || sta.top() == '/')
								{
									output[ind++] = sta.top();
									sta.pop();
									break;
								}
								else if(sta.top() == '+' || sta.top()=='-')
								{
									break;
								}
							}
							sta.push(input[i]);
						}
						break;
					case '+':
						if(sta.top() == '+' || sta.top() == '-')
						{
							output[ind++] = sta.top();
							sta.pop();
							sta.push(input[i]);
						}
						else if(sta.top() == '^'||sta.top() == '*' || sta.top()=='/')
						{
							while(1 && sta.size()>0 && sta.top()!='(')
							{
								char ch = sta.top();
								if(ch=='^'||sta.top() == '*' || sta.top()=='/')
								{
									output[ind++] = sta.top();
									sta.pop();
								}
								else if(sta.top() == '+' || sta.top() == '-')
								{
									output[ind++] = sta.top();
									sta.pop();
									break;
								}
							}
							sta.push(input[i]);
						}
						break;
					case '-':
						if(sta.top() == '+' || sta.top() == '-')
						{
							output[ind++] = sta.top();
							sta.pop();
							sta.push(input[i]);
						}
						else if(sta.top() == '^'||sta.top() == '*' || sta.top()=='/')
						{
							while(1 && sta.size()>0 && sta.top()!='(')
							{
								char ch = sta.top();
								if(ch=='^'||sta.top() == '*' || sta.top()=='/')
								{
									output[ind++] = sta.top();
									sta.pop();
								}
								else if(sta.top() == '+' || sta.top() == '-')
								{
									output[ind++] = sta.top();
									sta.pop();
									break;
								}
							}
							sta.push(input[i]);
						}
						break;
				}
			}
		}
	}
	while(sta.size()>0)
	{
		output[ind++] = sta.top();
		sta.pop();
	}
	//cout<<output<<endl;
	for(int i=0; i<ind; ++i) cout<<output[i];
	cout<<endl;
	return 0;
}
