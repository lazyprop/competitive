#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("in.txt");

	int n; cin>>n;
	pair<int,int> a[n];
	for (int i = 0; i<n; i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	sort(a,a+n);

	int dp[n+1] = {};
	for (int i = 1; i<n; i++)
	{
		int l = 0, r = i-1;
		int best = -1;
		while (l<=r)
		{
			int m = l + (r-l)/2;
			if (a[m].first < a[i].first - a[i].second)
			{
				best = m;
				l = m+1;
			}
			else
			{
				r = m-1;
			}
		}
		if (best >=0)
		{
			dp[i] = dp[best] + i-best-1;	
		}
		else
		{
			dp[i] = i;
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i<n; i++)
	{
		ans = min(ans, dp[i] + n-i-1);
	}
	cout<<ans<<endl;
}