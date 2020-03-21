#include<bits/stdc++.h>
using namespace std;

#define ll long long


int dp1[1001][1001];
int dp2[1001][1001];
int dp3[1001][1001];
int dp4[1001][1001];
int a[1001][1001];
int main()
{

	int n,m; cin>>n>>m;
	for (int i = 1; i<n; i++)
	{
		for (int j = 1; j<m; j++)
		{
			cin>>a[i][j];
		}
	}

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (i==0 and j==0)
			{
				dp1[i][j] = a[i][j];
			}
			else if (i==0)
			{
				dp1[i][j] =dp1[i][j-1]+a[i][j];
			}
			else if (j==0)
			{
				dp1[i][j] = dp1[i-1][j]+a[i][j];
			}
			else
			{
				dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1]) + a[i][j];
			}
		}
	}

	dp2[n-1][m-1] = a[n-1][m-1];
	for (int i = n-1; i>=0; i--)
	{
		for (int j = m-1; j>=0; j--)
		{
			if (i==0 and j==m-1)
			{
				dp2[i][j] = a[i][j];
			}
			else if (i==1)
			{
				dp2[i][j] =dp2[i][j+1]+a[i][j];
			}
			else if (j==1)
			{
				dp2[i][j] = dp2[i-1][j]+a[i][j];
			}
			else
			{
				dp2[i][j] = max(a[i-1][j],a[i][j-1]) + a[i][j];
			}
		}
	}
	dp3[n-1][0] = a[n-1][0];
	for (int i = n-1; i>=0; i--)
	{
		for (int j = 0; j<n; j++)
		{
			if (i==0 and j==0)
			{
				dp1[i][j] = a[i][j];
			}
			else if (i==1)
			{
				dp1[i][j] =dp1[i][j-1]+a[i][j];
			}
			else if (j==1)
			{
				dp1[i][j] = dp1[i-1][j]+a[i][j];
			}
			else
			{
				dp1[i][j] = max(a[i-1][j],a[i][j-1]) + a[i][j];
			}
		}
	}

	dp4[0][n-1] = a[0][n-1];
	for (int i = 0; i<n; i++)
	{
		for (int j = m-1; j>=0; j--)
		{
			if (i==0 and j==0)
			{
				dp1[i][j] = a[i][j];
			}
			else if (i==1)
			{
				dp1[i][j] =dp1[i][j-1]+a[i][j];
			}
			else if (j==1)
			{
				dp1[i][j] = dp1[i-1][j]+a[i][j];
			}
			else
			{
				dp1[i][j] = max(a[i-1][j],a[i][j-1]) + a[i][j];
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i<n-1; i++)
	{
		for (int j = 1; j<m-1; j++)
		{
			ans = max(ans,(ll)dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j]);
			ans = max(ans,(ll)dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1]);

		}
	}
	cout<<ans<<endl;
}