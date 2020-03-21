#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
	adj[u-1].push_back(v);
	adj[v-1].push_back(u);
}

int main()
{
	int v; cin>>v;
	int e; cin>>e;

	vector<int> adj[v];

	while (e--)
	{
		int u,v; cin>>u>>v;
		addedge(adj,u,v);

	}
	
	// print graph
	for(int i = 0;i<v;i++)
	{
		cout<<i+1<<"-> ";
		for (int j = 0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}

}
