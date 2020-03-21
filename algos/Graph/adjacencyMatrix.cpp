#include<iostream>
using namespace std;

int main()
{
	int v; cin>>v;
	int adj[v][v];
	for (int i = 0;i<v;i++)
	{
		for(int j = 0;j<v;j++)
		{
			adj[i][j] = 0;
		}
	}

	int n; cin>>n;
	while (n--)
	{
		int a,b;
		cin>>a>>b;
		adj[a-1][b-1] = 1;
		adj[b-1][a-1] = 1;
	}

	for (int i = 0;i<v;i++)
	{
		for (int j = 0;j<v;j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}


