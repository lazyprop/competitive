#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m; cin>>n>>m;
	vector<int> adj[n+2];
	for (int i = 0; i<m; i++)
	{
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int count = 0;
	int seen[n+1] = {};

	for (int x = 1; x<=n; x++)
	{
		if (!seen[x])
		{
			stack<int> Q;
			Q.push(x);

			while (!Q.empty())
			{
				int s = Q.top();
				Q.pop();

				if (!seen[s])
				{
					seen[s] = 1;
				}

				for (int i = 0, l = adj[s].size(); i<l; i++)
				{
					if (!seen[adj[s][i]])
					{
						Q.push(adj[s][i]);
					}
				}
			}
			count++;
		}
	}

	ll ans = pow(2,n-count);
	cout<<ans<<endl;
}