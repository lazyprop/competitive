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
		int a[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}
		int dp[n][3];
		for (int i = 0; i<n; i++)
		{
			dp[i][0] = INT_MAX;
			dp[i][1] = INT_MAX;
			dp[i][2] = INT_MAX;
		}
		dp[0][0] = 1;
		if (a[0] == 1 or a[0] == 3)
		{
			dp[0][1] = 0;
		}
		if (a[0] >=2)
		{
			dp[0][2] = 0;
		}
		for (int i = 1; i<n; i++)
		{
			dp[i][0] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));
			if (a[i] == 1 or a[i] == 3)
			{
				dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
			}
			if (a[i] >= 2)
			{
				dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
			}
		}
		cout<<min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2])<<endl;
	}
}