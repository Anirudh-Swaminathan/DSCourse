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
#include <queue>
using namespace std;

int gr[10][10];
int in_degree[10];
int n;
int m;
int ind;
int arr[10];
queue<int> q;

void topological_sort()
{
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			if(gr[i][j])
				in_degree[j]++;
	for(int i=0; i<n; ++i)
		if(!in_degree[i]) q.push(i);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		arr[ind++] = cur;
		for(int j=0; j<n; ++j)
		{
			if(gr[cur][j])
			{
				in_degree[j]--;
				if(!in_degree[j]) q.push(j);
			}
		}
	}
	return;
}

int main()
{
	cout<<"\nEnter the number of nodes: ";
	cin>>n;
	cout<<"\nEnter the number of edges: ";
	cin>>m;
    for(int i=0; i<n; ++i) in_degree[i]=0;
	ind = 0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j) gr[i][j] = 0;
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
