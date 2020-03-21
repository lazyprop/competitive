/*
Calculate the number of ways to fill an 2*n grid,
 _ _ _
|_|_|_|...
|_|_|_|

with a 2*1 tile:
 _	__
| | or |__|
|_|

*/

#include<iostream>
using namespace std;

int main()
{
	int n; cin>>n;
	
	int dp[n+1];
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i<=n; i++)
	{
		dp[i] = 0;
	}
	int ans=0;
	for (int i = 3; i<=n; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout<<dp[n]<<endl;
}



