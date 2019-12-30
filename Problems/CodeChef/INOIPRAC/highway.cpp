#include<bits/stdc++.h>
using namespace std;

const int mod = 20011;
int main()
{
	// ifstream cin("in.txt");

	int n,m,d; cin>>n>>m>>d;
	int dp[n][m] = {};
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			int x; cin>>x;
			if (!i and !j) dp[i][j] = x;
			if (x)
			{
				if (i) dp[i][j]+= dp[i-1][j];
				if (j) dp[i][j]+= dp[i][j-1];

				for (int k = 0; k < i-d; k++)
				{
					dp[i][j]-= dp[k][j];
				}
				for (int k = 0; k < j-d; k++)
				{
					dp[i][j]-= dp[i][k];
				}

				while (dp[i][j] < 0) dp[i][j]+= mod;
				dp[i][j]%= mod;
			}
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
	}
	// cout<<endl;

	cout<<(dp[n-1][m-1] + mod) % mod<<endl;
}