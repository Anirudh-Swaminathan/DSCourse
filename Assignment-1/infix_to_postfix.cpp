/*
	Authored by:-
	Anirudh Swaminathan 102115004 - Chemical 2nd year - 4th semester
	Abhinandan Nabera 102115038 - Chemical 2nd year - 4th semester

	This code is for the problem of converting an infix expression into a postfix expression using stack.

	This is a part of the programming assignment 1 given to students who opted to do Minors in CS in NIT-Trichy
*/
#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

#define MAX_SIZE 101

int main()
{
	stack<char> sta;
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
							char ch = sta.top();
							while(1)
							{
								if(ch=='^')
								{
									output[ind++] = '^';
									sta.pop();
								}
								else if(sta.top() == '*' || sta.top() == '/')
								{
									output[ind++] = sta.top();
									sta.pop();
									sta.push(input[i]);
									break;
								}
								else if(sta.top() == '+' || sta.top()=='-')
								{
									sta.push(input[i]);
									break;
								}
								ch = sta.top();
							}
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
							char ch = sta.top();
							while(1)
							{
								if(ch=='^')
								{
									output[ind++] = '^';
									sta.pop();
								}
								else if(sta.top() == '*' || sta.top() == '/')
								{
									output[ind++] = sta.top();
									sta.pop();
									sta.push(input[i]);
									break;
								}
								else if(sta.top() == '+' || sta.top()=='-')
								{
									sta.push(input[i]);
									break;
								}
								ch = sta.top();
							}
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
	cout<<output<<endl;
	return 0;
}
