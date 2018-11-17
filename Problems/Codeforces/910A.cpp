#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,d; cin>>n>>d;
	string s; cin>>s;
	
	int dp[101];
	for (int i = 0; i<101; i++)
	{
		dp[i] = 10000000;
	}
	dp[0] = 0;

	for (int i = 0; i<n; i++)
	{
		for (int j = 1; j<=d; j++)
		{
			if (i+j<n)
			{
				if (s[i+j]=='1')
				{
					dp[i+j] = min(dp[i+j],1+dp[i]);
				}
			}
		}
	}
	if (dp[n-1] != 10000000)		
		cout<<dp[n-1]<<endl;
	else
		cout<<-1<<endl;
}
