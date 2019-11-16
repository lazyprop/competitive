#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

const int maxN = 1000000;

vector<int> adj[maxN];
int seen[maxN];

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

		stack<int> Q;
		Q.push(1);

		while (!Q.empty())
		{
			int s = Q.top();
			Q.pop();

			if (!seen[s])
			{
				seen[s] = 1;
			}

			for (int i = 0, l=adj[s].size(); i<l; i++)
			{
				if (!seen[adj[s][i]])
				{
					Q.push(adj[s][i]);
				}
			}
		}
	}
}