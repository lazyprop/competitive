#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[501][501];
int dp[501][501];

int func(int i, int j)
{		
	if (i==-1)
	{
		return 1000000000;
	}
	if (j==-1)
	{
		return 1000000000;
	}
	if (dp[i][j])
	{
		return dp[i][j];
	}
	if (i==0 && j==0)
	{
		return arr[i][j];
	}

	int ans= arr[i][j] + min(func(i-1,j) ,func(i,j-1));
	dp[i][j] = ans;
	return ans;
}

int main()
{
	cin>>n>>m;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<func(n-1,m-1)<<endl;
}