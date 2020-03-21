#include<bits/stdc++.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		int a[n][4] = {};
		for (int i = 0; i<n; i++)
		{
			cin>>a[i][0];
			string s; cin>>s;
			for (int j = 0; j<s.size(); j++)
			{
				if (s[j] == 'A') a[i][1] = 1;
				if (s[j] == 'B') a[i][2] = 1;
				if (s[j] == 'C') a[i][3] = 1;
			}
		}
		
		int dp[7];
		for (int i = 0; i<7; i++) dp[i] = 300000;

		for (int i = 0; i<n; i++)
		{
			if (a[i][1] == 1 and a[i][2] == 0 and a[i][3] == 0)
			{
				dp[0] = min(a[i][0], dp[0]);
			}
			if (a[i][1] == 0 and a[i][2] == 1 and a[i][3] == 0)
			{
				dp[1] = min(a[i][0], dp[1]);
			}
			if (a[i][1] == 0 and a[i][2] == 0 and a[i][3] == 1)
			{
				dp[2] = min(a[i][0], dp[2]);
			}
		}

		dp[3] = dp[0] + dp[1];
		dp[4] = dp[1] + dp[2];
		dp[5] = dp[0] + dp[2];
		for (int i = 0; i<n; i++)
		{
			if (a[i][1] == 1 and a[i][2] == 1 and a[i][3] == 0)
			{
				dp[3] = min(a[i][0], dp[3]);
			}
			if (a[i][1] == 0 and a[i][2] == 1 and a[i][3] == 1)
			{
				dp[4] = min(a[i][0], dp[4]);
			}
			if (a[i][1] == 1 and a[i][2] == 0 and a[i][3] == 1)
			{
				dp[5] = min(a[i][0], dp[5]);
			}
		}

		dp[6] = min(dp[0]+ dp[1]+ dp[2], 
			min(dp[3] + dp[2], min(dp[4] + dp[0], dp[5] + dp[1])));
		dp[6] =  min(dp[6], min(dp[4]+dp[5], min(dp[5]+dp[3], dp[3]+dp[4])));
		
		for (int i = 0; i<n; i++)
		{
			if (a[i][1] == 1 and a[i][2] == 1 and a[i][3] == 1)
			{
				dp[6] = min(a[i][0], dp[6]);
			}
		}
		if (dp[6] > 300000) cout<<-1<<endl;
		else cout<<dp[6]<<endl;
	}
}