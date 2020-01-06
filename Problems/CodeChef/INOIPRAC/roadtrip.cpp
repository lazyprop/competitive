#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("in.txt");

	int T; cin>>T;
	while (T--)
	{
		int n,m,k; cin>>n>>m>>k;
		vector<int> adj[n+1];
		
		for (int i = 0; i < m; i++)
		{
			int u,v; cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int a[n+1];
		for (int i = 1; i <= n; i++)
		{
			cin>>a[i];
		}

		vector<int> comp;
		int count = 0;
		int seen[n+1] = {};
		for (int x = 1; x <= n; x++)
		{
			if (seen[x]) continue;

			int sum = 0;

			seen[x] = 1;
			stack<int> Q;
			Q.push(x);
			while (!Q.empty())
			{
				int s = Q.top();
				Q.pop();

				sum+= a[s];

				for (auto u : adj[s])
				{
					if (!seen[u])
					{
						Q.push(u);
						seen[u] = 1;
					}
				}
			}

			comp.push_back(sum);
			count++;
		}
		if (count < k)
		{
			cout<<-1<<endl;
			continue;
		}

		sort(comp.begin(), comp.end());

		// for (auto u : comp) cout<<u<<" ";
		// cout<<endl;

		int x = k/2;
		int ans = 0;
		for (int i = 0; i < x; i++) ans+= comp[i];
		for (int i = count - 1; i >= count - (k-x); i--) ans+= comp[i];

		cout<<ans<<endl;
	}
}