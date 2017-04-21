/*
	Authored by:-
	Anirudh Swaminathan 102115004 - Chemical 2nd year - 4th semester
	Abhinandan Nabera 102115038 - Chemical 2nd year - 4th semester

	This code is for implementing Dijkstra's algorithm for single source shortest path algorithm. 
	This is for an undirected graph.

	This is a part of the programming assignment 4 given to students who opted to do Minors in CS in NIT-Trichy
*/
#include <iostream>
using namespace std;
#define INF 1000000
int gr[10][10];
bool mark[10];
int n;
int m;
int dist[10];

void dijkstra(int s)
{
    dist[s-1]=0;
    for(int co=0; co<n-1; ++co)
    {
        int ind;
        int mi=INF;
        for(int k=0; k<n; ++k)
        {
            if(mark[k]==0 && mi>=dist[k])
            {
                mi=dist[k];
                ind=k;
            }
        }
        mark[ind]=1;
        for(int i=0; i<n; ++i)
        {
            if(mark[i]==0 && gr[ind][i]!=0 && dist[ind]+gr[ind][i]<dist[i]) dist[i]=dist[ind]+gr[ind][i];
        }
    }
}

int main()
{
    int t;
    cout<<"\nEnter the number of test cases: ";
    cin>>t;
    for(int w=0; w<t; ++w)
    {
        cout<<"\nEnter the number of nodes: ";
        cin>>n;
        cout<<"\nEnter the number of edges: ";
        cin>>m;
        for(int i=0; i<n; ++i) mark[i]=0;
        for(int i=0; i<n; ++i) dist[i]=INF;
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j) gr[i][j]=0;
        cout<<"\nEnter "<<m<<" edges 1 by 1\n";
        for(int i=0; i<m; ++i)
        {
            int a,b,r;
            cin>>a;
            cin>>b;
            cin>>r;
            if(gr[a-1][b-1]==0)
            {
                gr[a-1][b-1]=r;
                gr[b-1][a-1]=r;
            }
            else
            {
                if(gr[a-1][b-1]>r)
                {
                    gr[a-1][b-1]=r;
                    gr[b-1][a-1]=r;
                }
            }
        }
        int s;
        cout<<"\nEnter the source node: ";
        cin>>s;
        dijkstra(s);
        cout<<"\nOutputting shortest distances from the source...\n";
        for(int i=0; i<n; ++i)
        {
            if(i+1!=s){
                if(dist[i]!=INF)
                    cout<<dist[i]<<" ";
                else cout<<-1<<" ";
            }
            else
            {
				cout<<"s ";
			}
        }
        cout<<"\n";
    }
    return 0;
}
