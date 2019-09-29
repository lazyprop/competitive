#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		unsigned long long a[n], b[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}
		for (int i = 0; i<n; i++)
		{
			cin>>b[i];
		}
		
		unsigned long long dp[n][3];
		dp[0][0] = a[0];
		dp[0][1] = b[0];
		dp[0][2] = 0;
		for (int i = 1; i<n; i++)
		{
			dp[i][0] = max(dp[i-1][1] + a[i],
			 max(dp[i-1][2] + a[i],a[i]));
			
			dp[i][1] = max(dp[i-1][0] + b[i],
			 max(dp[i-1][2] + b[i],	b[i]));

			dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
		}
		cout<<max(dp[n-1][0], max(dp[n-1][1],
			dp[n-1][2]))<<endl;
	}
}