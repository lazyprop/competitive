#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

const int maxN = 1000000;

int seen[maxN];
vector<int> adj[maxN];

void dfs(int s)
{
	if (seen[s])
	{
		return;
	}
	seen[s] = 1;

	// process node s

	for (int i = 0, l = adj[s].size(); i<l; i++)
	{
		dfs(adj[s][i]);
	}
}

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

		for (int i = 0; i<m; i++)
		{
			int a,b; cin>>a>>b;
			adj[a].push_back(b);
		}

		dfs(1);
	}
}