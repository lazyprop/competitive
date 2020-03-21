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
		int h[n+1];
		for (int i = 1; i<n+1; i++)
		{
			cin>>h[i];
		}

		int dp[n+1] = {};
		dp[2] = abs(h[2] - h[1]);
		dp[3] = min(
			abs(h[3] - h[2]) + dp[2],
			abs(h[3] - h[1])
			);
		for (int i = 4; i<=n; i++)
		{
			dp[i] = min(
				abs(h[i] - h[i-1]) + dp[i-1],
				abs(h[i] - h[i-2]) + dp[i-2]
				);
		}
		cout<<dp[n];
		cout<<endl;	
	}
}