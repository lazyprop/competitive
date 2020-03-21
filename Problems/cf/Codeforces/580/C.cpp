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

	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n,m; cin>>n>>m;
		int cat[n+1] = {};
		for (int i = 1; i<=n; i++) cin>>cat[i];

		vector<int> adj[n+1];
		for (int i = 0; i<n-1; i++)
		{
			int u,v; cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		// dfs
		stack<pair<int,int> > Q;
		Q.push(make_pair(1,cat[1]));
		int ans = 0;
		int seen[n+1] = {};

		while (!Q.empty())
		{
			pair<int,int> s = Q.top();
			Q.pop();

			int flag = 0;

			if (!seen[s.first])
			{				
				seen[s.first] = 1;
				if (s.second > m)
				{
					flag = 1;
				}
			}

			if (!flag)
			{
				int size = 0;
				for (int i =0, l=adj[s.first].size(); i<l; i++)
				{
					int u = adj[s.first][i];
					if (!seen[u])
					{
						size++;
						if (cat[u])
						{
							Q.push(make_pair(u,s.second+cat[u]));
						}
						else
						{
							Q.push(make_pair(u,0));
						}
					}
				}
				if (size == 0)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}