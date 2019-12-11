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
		int a[m+1]={},b[m+1]={},c[m+1],d[m+1];

		cin>>c[0]>>d[0];
		for (int i = 1; i<=m; i++)
		{
			cin>>a[i]>>b[i]>>c[i]>>d[i];
		}

		a[0] = INT_MAX;
		int dp[n+1][m+1] = {};

		for (int i = 1; i<=n; i++)
		{
			for (int j = 1; j<=m; j++)
			{
				int x = a[j]/b[j];
				for (int k = 0; k<=x; k++)
				{
					if (k*c[j] <= i)
					{
						dp[i][j] = max(dp[i][j], dp[i-k*c[j]][j-1] + d[j]*k);
					}
					else break;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i<=n; i++)
		{
			ans = max(ans,dp[i][m] + ((n-i)/c[0])*d[0]);
		}
		cout<<ans<<endl;
	}
}