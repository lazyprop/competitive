#include<bits/stdc++.h>
using namespace std;

const int maxn = 3 * pow(10,5) + 10;
const int mod = 998244353;

int modpow(int a, int b)
{
	int res = 1;
	while (b--)
	{
		res*= a;
		res%=mod;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// ifstream cin("in.txt");

	int T; cin>>T;
	while (T--)
	{
		int n,m; cin>>n>>m;
		vector<int> adj[n+1];

		for (int i = 0; i < m; i++)
		{
			int u,v; cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		// bipartite check
		int col[n+1] = {}, seen[n+1] = {};
		long long ans = 1;
		int bip = 1;
		for (int x = 1; x <= n; x++)
		{
			if (seen[x]) continue;

			stack<int> Q;
			Q.push(x);
			seen[x] = 1;

			int a = 0, b = 0;

			while (!Q.empty())
			{
				int s = Q.top();
				Q.pop();

				if (col[s]) a++;
				else b++;

				for (auto u : adj[s])
				{
					if (seen[u])
					{
						if (col[u] == col[s])
						{
							bip = 0;
							break;
						}
					}
					else
					{
						Q.push(u);
						seen[u] = 1;
						col[u] = col[s]^1;
					}
				}
				if (!bip) break;
			}
			if (!bip) break;
			ans*= (modpow(2,a) + modpow(2,b)) % mod;
			ans%= mod;
		}
		ans*= bip;

		cout<<ans<<'\n';
	}
}