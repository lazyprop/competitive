#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// ifstream cin("in.txt");

	int n; cin>>n;
	int a[n+2], pre[n+2] = {};
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
		pre[i] = pre[i-1] + a[i];
	}

	int suff[n+2] = {};
	for (int i = n; i >= 1; i--)
	{
		suff[i] = suff[i+1] + a[i];
	}

	int dp[n+2] = {};
	for (int i = n; i >= 1; i--)
	{
		dp[i] = max(dp[i+1] + a[i], -suff[i]);
	}

	int ans = INT_MIN;
	for (int i = 1; i <= n+1; i++)
	{
		ans = max(ans, dp[i] - pre[i-1]);
	}
	cout<<ans<<endl;
}