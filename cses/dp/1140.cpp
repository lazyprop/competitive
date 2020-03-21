#include<bits/stdc++.h>
using namespace std;

#define ll long long

int cmp(vector<int> a, vector<int> b)
{
	if (a[1] == b[1])
	{
		if (a[2] == b[2])
		{
			return a[0] < b[0];
		}
		return a[2] < b[2];
	}
	return a[1] < b[1];
}

int main()
{
	int n; cin>>n;	
	vector<int> a[n];
	for (int i = 0; i<n; i++)
	{
		int x,y,z; cin>>x>>y>>z;
		a[i] = {x,y,z};
	}
	sort(a,a+n,cmp);

	ll dp[n] = {};
	dp[0] = a[0][2];
	for (int i = 1; i<n; i++)
	{
		dp[i] = dp[i-1];

		int l = 0, r= n-1, best=-1;
		while (l<=r)
		{
			int m = l+(r-l)/2;
			if (a[m][1] < a[i][0])
			{
				best = m;
				l = m+1;
			}
			else
			{
				r = m-1;
			}
		}

		if (best >= 0)
		{
			dp[i] = max(dp[i], dp[best] + a[i][2]);
		}
	}
	cout<<dp[n-1]<<endl;
}