#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

#define MOD 1000000007

// ans 887284912
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
		int t,k; cin>>t>>k;
		
		int a[t][2];
		int big =0;
		for (int i = 0; i<t; i++)
		{
			cin>>a[i][0]>>a[i][1];
			big = max(big,a[i][1]);
		}

		ll pre[big+5]={};
		int dp[big+1] = {};

		dp[0] = 1;
		for (int i = 1; i<=big; i++)
		{
			dp[i] = dp[i-1];
			if (i >= k) dp[i]= (int) (((ll)dp[i] + (ll)dp[i-k]) % MOD);
			pre[i] = pre[i-1] + dp[i];
			//cout<<dp[i]<<" "<<pre[i]<<endl;
		}

		for (int i = 0; i<t; i++)
		{
			cout<<(pre[a[i][1]] - pre[a[i][0]-1]) % MOD<<endl;
		}
	}
}