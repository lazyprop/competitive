#include<bits/stdc++.h>
using namespace std;

int dp[510][510];
int a[510];

int f(int i, int j)
{
	if (dp[i][j]) return dp[i][j];
	if (i > j)
	{
		return 0;
	}
	if (i == j)
	{
		dp[i][j] = 1;
		return 1;
	}

	dp[i][j] = 1 + min(f(i+1, j), f(i, j-1));

	for (int k = i+2; k<=j; k++)
	{
		if (a[i] == a[k])
		{
			dp[i][j] = min(dp[i][j], f(i+1, k-1) + f(k+1, j));
			// cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[k]<<endl;
		}
	}
	if (a[i] == a[i+1])
	{
		dp[i][j] = min(dp[i][j], 1 + f(i+2, j));
	}

	return dp[i][j];
}

int main()
{
	int n; cin>>n;
	for (int i = 0; i<n; i++)
	{
		cin>>a[i];
	}

	cout<<f(0,n-1)<<endl;
	
}