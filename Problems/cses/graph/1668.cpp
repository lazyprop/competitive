#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	vector<int> adj[n+1];

	for (int i = 0; i<m; i++)
	{
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int color[n+1] = {};

	int flag = 0;

	for (int x=1; x<=n; x++)
	{
		if (color[x]) continue;

		// bfs
		queue<int> Q;
		Q.push(x);	
		color[x] = 1;
		while (!Q.empty())
		{
			int s = Q.front();
			Q.pop();

			for (int i = 0, l = adj[s].size(); i<l; i++)
			{
				int t = adj[s][i];
				
				if (!color[t])
				{
					color[t] = 3-color[s];
					Q.push(t);
				}
				else
				{
					if (color[t] == color[s])
					{
						cout<<"IMPOSSIBLE\n";
						return 0;
					}
				}
			}
		}
	}
	for (int i = 1; i<=n; i++)
	{
		cout<<color[i]<<" \n" [i==n];
	}
}