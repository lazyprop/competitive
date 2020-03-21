#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	vector<int> adj[n+2];
	for (int i =0; i<m; i++)
	{
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int seen[n+1] = {};
	vector<int> comps;

	for (int i=1; i<=n; i++)
	{
		if (seen[i]) continue;

		// dfs
		stack<int> Q;
		Q.push(i);
		comps.push_back(i);
		while (!Q.empty())
		{
			int s= Q.top();
			Q.pop();

			if (!seen[s])
			{
				seen[s]++;
			}

			for (int i = 0, x = adj[s].size(); i<x; i++)
			{
				if (!seen[adj[s][i]])
				{
					Q.push(adj[s][i]);
				}
			}
		}
	}

	int ans = comps.size()-1;
	cout<<ans<<endl;
	for (int i = 1; i<=ans; i++)
	{
		cout<<comps[0]<<" "<<comps[i]<<endl;
	}
}