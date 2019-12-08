#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int main()
{
	int n,m; cin>>n>>m;
	int a[n+2];
	for (int i = 1; i<=n; i++)
	{
		cin>>a[i];
	}

	int dp[n+3][m+2] = {};
	if (a[1])
	{
		dp[1][a[1]] = 1;
	}
	else
	{
		for (int i = 1; i<=m; i++)
		{
			dp[1][i] = 1;
		}
	}

	for (int i = 2; i<=n; i++)
	{
		if (a[i])
		{
			dp[i][a[i]] = (dp[i-1][a[i]-1] + dp[i-1][a[i]]) % mod + dp[i-1][a[i]+1];
			dp[i][a[i]]%= mod;
			continue;
		}
		for (int j = 1; j<=m; j++)
		{
			dp[i][j]+= (dp[i-1][j-1] + dp[i-1][j]) % mod;
			dp[i][j]+= dp[i-1][j+1];
			dp[i][j]%= mod;
		}
	}
	
	int ans = 0;
	for (int i = 1; i<=m; i++)
	{
		ans+= dp[n][i];
		ans%= mod;
	}
	cout<<ans<<endl;
}
