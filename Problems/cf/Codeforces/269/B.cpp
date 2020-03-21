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
		int a[n+1];
		
		for (int i = 1; i<=n; i++)
		{
			cin>>a[i];
			float x; cin>>x;
		}

		int dp[n+10] = {};
		for (int i = 1; i<=n; i++)
		{
			int type = a[i];
			for (int j = type; j>=1; j--)
			{
				dp[type] = max(dp[type],1+dp[j]);
			}
		}
			
		int ans = 0;
		for (int i  =1; i<=n; i++)
		{
			ans = max(ans,dp[i]);
		}
		cout<<n-ans<<endl;
	}
}