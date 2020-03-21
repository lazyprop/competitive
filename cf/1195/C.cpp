#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	int n; cin>>n;

	ll a[n][2];
	for (int i = 0; i<n; i++)
	{
		cin>>a[i][0];
	}
	for (int i = 0; i<n; i++)
	{
		cin>>a[i][1];
	}

	ll dp[n][2];
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];

	for (int i = 1; i<n; i++)
	{
		dp[i][0] = dp[i-1][1] + a[i][0];
		if (i-1)
		{
			dp[i][0] = max(dp[i][0],max(dp[i-2][0],dp[i-2][1]) + a[i][0]);
		}

		dp[i][1] = dp[i-1][0] + a[i][1];
		if (i-1)
		{
			dp[i][1] = max(dp[i][1],max(dp[i-2][1],dp[i-2][0]) + a[i][1]);
		}
	}
	cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
}