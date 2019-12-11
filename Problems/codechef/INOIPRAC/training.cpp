#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll digsum(ll x)
{
	ll res = 0;
	while (x)
	{
		res+= x%10;
		x/=10;
	}
	return pow(res,3);
}

ll dp[5005][5005];
int main()
{
	int n,sin; cin>>n>>sin;
	int a[n+1];
	for (int i = 1; i<=n; i++)
	{
		cin>>a[i];
	}

	ll prepow[5005] = {};
	prepow[0] = sin;
	for (int i = 1; i<=n+2; i++)
	{
		prepow[i] = prepow[i-1] +  digsum(prepow[i-1]);
	}

	ll ans = 0;
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=i; j++)
		{
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j] + a[i]*prepow[j-1]);
			ans = max(dp[i][j],ans);
		}
	}
	cout<<ans<<endl;

}