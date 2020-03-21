#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	vector<int> adj[210];
	int ans = 0;

	for (int i = 1; i<=n; i++)
	{
		int x; cin>>x;
		if (x==0) ans++;
		while (x--)
		{
			int y; cin>>y;
			adj[100+y].push_back(i);
			adj[i].push_back(100+y);
		}
	}

	int seen[210] = {};
	
	if (ans<n) for (int x = 1; x<=200; x++)
	{
		if (seen[x] or !adj[x].size()) continue;

		// dfs
		stack<int> Q;
		Q.push(x);
		while (!Q.empty())
		{
			int s = Q.top();
			Q.pop();
			seen[s]++;

			for (auto t: adj[s])
			{
				if (!seen[t])
				{
					Q.push(t);
				}
			}
		}
		ans++;
	}	
	else ans++;
	cout<<ans-1<<endl;
}