#include<bits/stdc++.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int W[10000][10000];

// I couldn't understand Dijkstra's. So improvised on BFS.
int main()
{
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		int n,m; cin>>n>>m;
		vector<int> G[n];		
		make_weighted_dir_graph(m,G,W);
	
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				cout<<W[i][j]<<" ";

			}
			cout<<endl;
		}
		for (int i = 0; i<n; i++)	
		{
			cout<<i+1<<": ";
			for (int j = 0; j < G[i].size(); j++)
			{
				cout<<G[i][j]+1<<"("<<W[i][G[i][j]]<<") ";
			}
			cout<<endl;
		}

		int src; cin>>src; src--;
		int dist[n]; // distance of all nodes from source
		for (int i = 0; i<n; i++)
		{
			dist[i] = 1000000000;
		}
		dist[src] = 0;

		int pre[n]; // predecessor of i-th node in final shortest path
		int discovered[n];
		memset(discovered,sizeof(discovered),0);

		int flag=0;
		vector<int> L;
		L.push_back(src);
		while (L.size() > 0)
		{
			vector<int> temp;
			for (int i = 0; i<L.size(); i++)
			{
				int u = L[i];
				for (int j = 0; j<G[u].size(); j++)
				{
					int v = G[u][j];
					if (dist[v] > dist[u] + W[u][v])
					{
						dist[v] = dist[u] + W[u][v];
						pre[v] = u;
					}
					temp.push_back(v);
				}
				discovered[u] = 1;				
			}
			L=temp;
		}

		for (int i = 0; i<n; i++)
		{
			cout<<pre[i]<<" ";
		}
		cout<<endl;
	}
}