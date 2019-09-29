#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin>>s;
	int n = s.size();
	int dp[n];
	
	memset(dp,0,sizeof(dp));
	for (int i = 0; i<n-1; i++)
	{
		if (s[i] == s[i+1])
		{
			dp[i] = 1;
		}
	}
	int sum[n];
	memset(sum,0,sizeof(sum));
	sum[0] = 0;
	for (int i = 1; i<n; i++)
	{
		sum[i] = sum[i-1] + dp[i-1];
	}
	int m; cin>>m;
	for (int i = 0; i<m; i++)
	{
		int a,b; cin>>a>>b;
		//cout<<sum[b-1]<<" "<<sum[a-1]<<endl;
		cout<<sum[b-1]-sum[a-1]<<endl;
	}

}
