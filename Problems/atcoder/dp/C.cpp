#include<iostream>
#include<vector>
#include<limits>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int main()
{
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		int n; cin>>n;
		int a[n], b[n], c[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		int dp[n][3] = {};
		dp[0][0] = a[0];
		dp[0][1] = b[0];
		dp[0][2] = c[0];

		for (int i = 1; i<n; i++)
		{
			dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
			dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + b[i];
			dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
		}

		cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
		cout<<endl;	
	}
}