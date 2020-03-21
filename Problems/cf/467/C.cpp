#include<bits/stdc++.h>

using namespace std;

#define ll long long
int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		ll n,m,k; cin>>n>>m>>k;

		ll pre[n+1] = {};
		for (int i = 0; i<n; i++)
		{
			int x; cin>>x;
			pre[i+1] = pre[i] + x;
		}

		ll ans=INT_MIN, dp[n+5][n+5]={};
		for (int x = 1; x<=k; x++) // opt when choosing x pairs
		{
			for (int i = m; i<=n; i++)
			{
				dp[x][i] = dp[x-1][i-m] + pre[i] - pre[i-m];
				dp[x][i] = max(dp[x][i], dp[x][i-1]);
				ans = max (dp[x][i], ans);
			}
		}
		cout<<ans<<endl;
	}
}