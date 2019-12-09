#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	vector<int> adj[n+2];

	for (int i = 0; i<m; i++)
	{
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> Q;
	int seen[n+1] = {},dist[n+1] = {}, prev[n+1] = {};

	seen[1] = 1;
	dist[1] = 1;
	Q.push(1);

	while (!Q.empty())
	{
		int s = Q.front();
		Q.pop();

		for (int i = 0, l = adj[s].size(); i<l; i++)
		{
			int u = adj[s][i];
			if (seen[u]) continue;
			seen[u]++;
			dist[u] = dist[s]+1;
			prev[u] = s;
			Q.push(u);
		}
	}

	if (!dist[n])
	{
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	cout<<dist[n]<<endl;
	stack<int> sol;
	int k = n;
	while (prev[k])
	{
		sol.push(k);
		k = prev[k];
	}
	sol.push(1);

	while (!sol.empty())
	{
		cout<<sol.top()<<" ";
		sol.pop();
	}
	cout<<endl;
}