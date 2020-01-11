#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	int n,m; cin>>n>>m;
	
	int a[n+1];
	for (int i = 1; i <= n; i++) cin>>a[i];
	
	vector<int> adj[n+1];

	while (m--)
	{
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ll sum = 0;
	int seen[n+1] = {};
	for (int x = 1; x <= n; x++)
	{
		if (seen[x]) continue;

		seen[x] = 1;
		int small = INT_MAX;
		
		stack<int> Q;
		Q.push(x);
		
		while (!Q.empty())
		{
			int s = Q.top();
			Q.pop();

			small = min(a[s], small);

			for (auto u : adj[s])
			{
				if (!seen[u])
				{
					seen[u] = 1;
					Q.push(u);
				}
			}
		}
		sum+= (ll) small;
	}
	cout<<sum<<endl;
}