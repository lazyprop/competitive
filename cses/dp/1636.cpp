#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n,x; cin>>n>>x;
		int a[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		int dp[n][x+1] = {};
		for (int i = 0; i<n; i++)
		{
			dp[i][0] = 1;
			for (int j = 1; j<=x; j++)
			{
				if (a[i] <= j)
				{
					dp[i][j]+= dp[i][j-a[i]];
				}
				if (j>0 and i>0)
				{
					dp[i][j]+= dp[i-1][j];
				}
				dp[i][j]%= 1000000007;
			}
		}
		cout<<dp[n-1][x]<<endl;
	}
}