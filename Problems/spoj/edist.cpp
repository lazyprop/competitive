#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		string a; cin>>a;
		string b; cin>>b;
		int n = a.size();
		int m = b.size();

		int dp[n+1][m+1] = {};
		for (int i = 0; i<n+1; i++)
		{
			dp[i][0] = i;
		}
		for (int i = 0; i<m+1; i++)
		{
			dp[0][i] = i;
		}

		for (int i = 1; i<n+1; i++)
		{
			for (int j = 1; j<m+1; j++)
			{
				if (a[i-1] != b[j-1])
				{
					dp[i][j] = 1+min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));
				}
				else
				{
					dp[i][j] = dp[i-1][j-1];
				}
			}
		}
		cout<<dp[n][m]<<endl;
	}
}