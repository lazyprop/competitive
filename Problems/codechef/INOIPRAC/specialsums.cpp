#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	int n; cin>>n;
	int a[n], b[n];
	for (int i = 0; i<n; i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i<n; i++)
	{
		cin>>b[i];
	}

	pair<int,ll> dp[n];
	dp[0] = make_pair(0,0);

	for (int i = 1; i<n; i++)
	{
		if (dp[i-1])
	}

	ll ans = 0;
	for (int i = 1; i<n-1; i++)
	{
		cout<<dp[i].first<<" "<<a[dp[i].second-1]<<endl;
		ans = max(ans,dp[i].first + (ll) a[i+1] + (ll) a[dp[i].second-1]);
	}
	cout<<ans<<endl;
}