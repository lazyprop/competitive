#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("in.txt")

	int n,k; cin>>n>>k;
	int a[n], dp[n] = {};

	cin>>a[0]>>a[1];
	dp[0] = a[0];
	dp[1] = dp[0] + a[1];

	for (int i = 2; i<n; i++)
	{
		cin>>a[i];
		dp[i] = a[i] + max(dp[i-1], dp[i-2]);
	}

	k--;
	int dp2[n] = {}, ans = dp[k] - a[k];
	// cout<<ans<<endl;
	if (k < n-1)
	{
		dp2[k+1] = a[k+1];

		ans = max(ans, dp[k+1] + dp2[k+1] - a[k+1]);
	}

	for (int i = k+2; i<n; i++)
	{
		dp2[i] = a[i] + max(dp2[i-1], dp2[i-2]);
		ans  = max(ans, dp2[i] + dp[i] - a[i]);
	}

	if (k == 0)
	{
		ans = max(ans,0);
	}
	cout<<ans<<endl;
}