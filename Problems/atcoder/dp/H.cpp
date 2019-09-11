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

int dp[1001][1001];
int main()
{
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		int n,m; cin>>n>>m;
		char grid[n][m];
		for (int i = 0.; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				cin>>grid[i][j];
			}
		}		
		if (grid[0][0] == '#')
		{
			cout<<0<<endl;
			return 0;
		}
		dp[0][0] = 1;
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				if (grid[i][j] != '#')
				{
					if (i>0 and grid[i-1][j] != '#')
					{
						dp[i][j]+= dp[i-1][j] % 1000000007;
					}
					if (j>0 and grid[i][j-1] != '#')
					{
						dp[i][j]+= dp[i][j-1] % 1000000007;
					}
				}				
			}
		}
		cout<<dp[n-1][m-1] % 1000000007;
		cout<<endl;	
	}
}