/*
	Authored by:-
	Anirudh Swaminathan 102115004 - Chemical 2nd year - 4th semester
	Abhinandan Nabera 102115038 - Chemical 2nd year - 4th semester

	This code is for implementing Topological sorting using Kahn's algorithm. 
	This is for a DAG(Directed Acylic Graph)

	This is a part of the programming assignment 4 given to students who opted to do Minors in CS in NIT-Trichy
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gr[10][10];
int mark[10];
int n;
int m;
int ind;
int arr[10];

void visit(int cu)
{
	if(!mark[cu])
	{
		mark[cu] = 1;
		for(int j=0; j<n; ++j)
		{
			if(gr[cu][j])
				visit(j);
		}
		arr[ind--] = cu;
	}
	return;
}

void topological_sort()
{
	visit(0);
	return;
}

int main()
{
	cout<<"\nEnter the number of nodes: ";
	cin>>n;
	cout<<"\nEnter the number of edges: ";
	cin>>m;
	ind = n-1;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j) gr[i][j] = 0;
	for(int i=0; i<n; ++i) mark[i]=0;
	cout<<"\nEnter "<<m<<" edges 1 by 1 (Format: From To)\n";
    for(int i=0; i<m; ++i)
    {
        int a,b;
        cin>>a;
        cin>>b;
        if(gr[a-1][b-1]==0)
        {
            gr[a-1][b-1]=1;
        }
    }
    topological_sort();
    cout<<"\nAfter performing topological sorting on the given DAG using Kahns algorithm, the output is\n";
    for(int i=0; i<n; ++i) cout<<arr[i]+1<<" ";
    cout<<endl;
	return 0;
}
