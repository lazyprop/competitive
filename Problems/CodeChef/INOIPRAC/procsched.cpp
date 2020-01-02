#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll dp[5010][5010];

bool comp(pair<int,int> a, pair<int,int> b)
{
	return a.second < b.second;
}
int main()
{
	// ifstream cin("in.txt");

	int T; cin>>T;
	while (T--)
	{
		int n,m; cin>>n>>m;
		int a[n+1];

		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}

		pair<int,int> b[m+1];
		
		for (int i = 0; i<m; i++)
		{
			cin>>b[i].first;
		}
		for (int i = 0; i<m; i++)
		{
			cin>>b[i].second;
		}

		sort(b, b+m, comp);
	
		for (int i = 1; i<=n; i++)
		{
			dp[i][0] = dp[i-1][0] + a[i-1];
		}
		
		for (int j = 1; j<=m; j++)
		{
			if (dp[0][j-1] < b[j-1].second)
			{
				dp[0][j] = max((ll) b[j-1].second, b[j-1].first + dp[0][j-1]);
			}
			else
			{
				dp[0][j] = 1e14;
			}
		}

		// a = classified
		// b = public


		for (int c = 1; c <= n; c++)
		{
			for (int p = 1; p <= m; p++)
			{
				ll x1 = dp[c-1][p] + a[c-1];
				ll x2 = dp[c][p-1];

				if (x2 < b[p-1].second)
				{
					x2 = max((ll) b[p-1].second, x2 + b[p-1].first);
				}
				else
				{
					x2 = 1e14;
				}

				dp[c][p] = min(x1,x2);
			}
		}


		if (dp[n][m] >= 1e14)
		{
			cout<<-1<<endl;
			continue;
		}
		cout<<dp[n][m]<<endl;
	}
}