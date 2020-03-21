#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<int> tree[], int u, int v)
{
	tree[u].push_back(v);
}

int main()
{
	int n; cin>>n;
	vector<int> adj[n+1];

	for (int i = 0; i<n;i++)
	{
		int p; cin>>p;
		if (p!=-1)
		{
			addedge(adj,p,i+1);
		}
		else
		{
			addedge(adj,0,i+1);
		}
	}

	// bfs
	int discovered[n+1], count=0;
	for (int i = 1; i<n+1; i++)
	{
		discovered[i] = 0;
	}
	discovered[0] = 1;
	vector<int> L = {0};

	while (L.size() > 0)
	{
		vector<int> temp;
		for (int i = 0; i<L.size(); i++)
		{
			for (int j = 0; j< adj[L[i]].size(); j++)
			{
				int u = adj[L[i]][j];
				if (discovered[u] == 0)
				{
					discovered[u] = 1;
					temp.push_back(u);
				}
			}
		}
		if (temp.size() > 0)
		{
			count++;
		}
		L.clear();
		for (int i = 0; i<temp.size(); i++)
		{
			L.push_back(temp[i]);
		}
	}
	cout<<count<<endl;
}




