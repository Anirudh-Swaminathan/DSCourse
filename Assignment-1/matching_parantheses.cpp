#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <cstring>
using namespace std;
int main()
{
	stack<char> sta;
	string input;
	cout<<"\nPlease enter only parantheses statement to check for mathcing parantheses\n";
	cin>>input;
	cout<<"\nEntered expression is "<<input<<endl;
	for(int i=0; i<input.length(); ++i)
	{
		if(input[i] == '(')
		{
			sta.push(input[i]);
		}
		else
		{
			if(sta.size() == 0)
			{
				cout<<"\nThe parantheses are unbalanced\n";
				break;
			}
			char ch = sta.top();
			sta.pop();
		}
	}
	if(sta.size() == 0) cout<<"\nThe parantheses are balanced\n";
	else cout<<"\nThe parantheses are unbalanced\n";
	return 0;
}
