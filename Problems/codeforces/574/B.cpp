#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;

	int adj[n+1][n+1] = {};
	int degree[n+1] = {};

	for (int i = 0; i<m; i++)
	{
		int u,v; cin>>u>>v;
		adj[u][v] = 1;
		adj[v][u] = 1;
		degree[u]++;
		degree[v]++;
	}

	int ans = INT_MAX;
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=n; j++)
		{
			if (adj[i][j])
			{
				for (int k = j+1; k<=n; k++)
				{
					if (adj[i][k] and adj[j][k])
					{
						ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
					}
				}
			}
		}
	}
	if (ans == INT_MAX) ans = -1;
	cout<<ans<<endl;
}