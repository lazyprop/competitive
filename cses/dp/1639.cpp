#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;

	int n = a.size(), m = b.size();
	
	int dp[n+5][m+5] = {};
	for (int i = 0; i<n; i++)
	{
		for (int j= 0; j<m; j++)
		{
			dp[i][j] = INT_MAX;
		}
	}
	dp[0][0] = !(a[0]==b[0]);

	for (int i = 0; i<=n; i++)
	{
		for (int j = 0; j<=m; j++)
		{
			if (i==0)
			{
				dp[i][j] = j;
			}
			else if (j==0)
			{
				dp[i][j] = i;
			}
			else if (a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}

			else
			{
				dp[i][j] = 1+ min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
			}

		}
	}

	cout<<dp[n][m]<<endl;
}