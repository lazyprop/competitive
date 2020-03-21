#include<bits/stdc++.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int main()
{
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		int n,m; cin>>n>>m;
		vector<int> G[n];
		int W[n][n];
		make_weighted_graph(m,G,W);
		
		int ans=0;			
		for (int src=0; src<n; src++)
		{
			int dist[n], processed[n];
			for (int i = 0; i<n; i++)
			{
				dist[i] = 123456789;
				processed[i] = 0;
			}
			dist[src] = 0;

			priority_queue<pair<int, int> > q;
			q.push(make_pair(0,src));

			while (!q.empty())
			{
				int u = q.top().second;
				q.pop();

				if (processed[u])
					continue;
				processed[u] = 1;

				for (int i = 0, s = G[u].size(); i<s; i++)
				{
					int v = G[u][i];
					int w = W[u][v];
					if (dist[u]+w < dist[v])
					{
						dist[v] = dist[u] + w;
						q.push(make_pair(-dist[v], v));
					}
				}
			}
			int m = 0;
			for (int i = 0; i<n; i++)
			{
				m=max(m,dist[i]);
			}
			ans=max(m,ans);

		}		
		cout<<ans;
		cout<<endl;	
	}
}