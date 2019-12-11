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
		int a[n]; 
		
		for (int i  = 0; i<n; i++)
		{
			cin>>a[i];
		}
		int dp[n] = {};

		// 0 gets food
		dp[0] = a[0];		
		dp[1] = a[0] + a[1];
		dp[2] = a[0] + a[2];
		for (int i = 3; i<n; i++)
		{
			dp[i] = a[i] + min(dp[i-1], dp[i-2]);
		}
		int x = min(dp[n-1], dp[n-2]);

		// 0 does not get food
		dp[0] = a[0];
		dp[1] = a[1];
		for (int i = 2; i<n; i++)
		{
			dp[i] = a[i] + min(dp[i-1], dp[i-2]);
		}
		cout<<min(dp[n-1],x)<<endl;
	}
}