#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n,m; cin>>n>>m;
		int a[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);

		ll dp[n] = {};
		dp[0] = a[0];
		cout<<dp[0]<<" ";
		for (int i = 1; i<m; i++)
		{
			dp[i] = dp[i-1];
			dp[i]+= a[i];
			cout<<dp[i]<<" ";
		}
		ll sum[n] = {};
		for (int i = 0; i<n; i++)
		{
			sum[i] = a[i];
		}
		for (int i = m; i<n; i++)
		{
			sum[i]+= sum[i-m]; 
		}
		for (int i = m; i<n; i++)
		{
			dp[i] = dp[i-1] + a[i] + sum[i-m];
			/*
			for (int x = 1; x*m <= i; x++)
			{
				dp[i]+= a[i-x*m];
			}
			*/
			cout<<dp[i]<<" ";
		}
		cout<<endl;
	}
}