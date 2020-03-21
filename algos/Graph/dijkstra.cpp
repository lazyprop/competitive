#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	// ifstream cin("in.txt");

	int n,m; cin>>n>>m;

	vector<pair<int,int> > adj[n+1];

	for (int i = 0; i < m; i++)
	{
		int u,v,w; cin>>u>>v>>w;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}

	int x = 1; // source is 1
	ll dist[n+1];
	int done[n+1] = {}, prev[n+1] = {};
	for (int i = 1; i <= n; i++) dist[i] = LLONG_MAX;

	
	priority_queue<pair<int,int>> Q;
	Q.push(make_pair(0, x));
	dist[x] = 0;

	while (!Q.empty())
	{
		int s = Q.top().second;
		Q.pop();
		
		if (done[s]) continue;
		done[s] = 1;

		for (auto u : adj[s])
		{

			int t = u.first, w = u.second;
			if (dist[s] + w < dist[t])
			{
				dist[t] = dist[s] + w;
				prev[t] = s;
				Q.push(make_pair(-dist[t], t));
			}
		}
	}

	if (dist[n] == LLONG_MAX)
	{
		cout<<-1<<endl;
		return 0;
	}

	int end = n;
	stack<int> path;
	while (end)
	{
		path.push(end);
		end = prev[end];
	}
	while (!path.empty())
	{
		cout<<path.top()<<" ";
		path.pop();
	}
	cout<<endl;
}