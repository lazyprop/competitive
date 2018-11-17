// number of ways to transverse a DAG

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	vector<int> adj[n];
	for (int i = 0; i<m; i++)
	{
		int a,b; cin>>a>>b;
		adj[a-1].push_back(b-1);
	}

	vector<int> L={0}; // initialize current working layer
	int discovered[n];
	for (int i = 0; i<n; i++)
	{
		discovered[i] = 0;
	}
	discovered[0] = 1;
	int ans = 1;

	while (L.size() > 0)
	{
		vector<int> temp;
		for (int i = 0; i<L.size();i++)
		{
			int u = L[i];
			for (int j = 0; j<adj[u].size(); j++)
			{
				int v = adj[u][j];
				if (discovered[v] == 0)
				{
					discovered[v] = 1;
					temp.push_back(v);
				}
			}
			ans*=factorial(adj[u].size());

		}
		L=temp;
	}
	cout<<ans<<endl;
}



