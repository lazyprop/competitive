// bfs implementation for undirected acyclic graphs
#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<int> tree[], int u, int v)
{
	tree[u-1].push_back(v);
	tree[v-1].push_back(u);
}

int main()
{
	int V,E; cin>>V>>E;
	vector<int> adj[V];
	for (int i = 0;i<E;i++)
	{
		int u,v;
		cin>>u>>v;
		addedge(adj,u,v);
	}

	int s,t; cin>>s>>t;
	// search begins here
	
	int discovered[V], count=0;
	for (int i = 0;i<V;i++)
	{
		discovered[i] = 0;
	}
	discovered[s-1] = 1;
	int flag=0;
	vector<int> L = {s};
	while (L.size() > 0)
	{
		vector<int> temp;
		for (int i = 0; i<L.size();i++)
		{
			for (int j = 0,n=adj[L[i]-1].size(); j<n;j++)
			{
				int v = adj[L[i]-1][j];
				if (discovered[v-1] == 0)
				{

					discovered[v-1] = 1;
					temp.push_back(v);
				}
				if (v==t)
				{
					flag=1;
					break;
				}

			}
			if (flag==1)
			{
				break;
			}
		}
		L.clear();
		for (int i = 0,n=temp.size();i<n;i++)
		{
			L.push_back(temp[i]);
		}
		if (temp.size() > 0 )
		{
			count++;
		}
		if (flag==1)
		{
			break;
		}

	}
	cout<<count<<endl;

}
