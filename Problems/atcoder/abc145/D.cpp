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

	int n,m; cin>>n>>m;

	int dp[n+1][m+1] = {};
	dp[0][0] = 1;
	for (int i = 1; i<n; i++)
	{
		for (int j = 1; j<m; j++)
		{
			if (i>1 and j>2)
			{
				dp[i][j] += dp[i-1][j-2];
			}
			if (i>2 and j>1)
			{
				dp[i][j]+= dp[i-2][j-1];
			}
		}	
	}
	cout<<dp[n-1][m-1]<<endl;
}