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

int dp[1000001];
int main()
{
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		int n,x; cin>>n>>x;
		int c[n];
		for (int i = 0; i<n; i++)
		{
			cin>>c[i];
			dp[c[i]]++;
		}
		dp[0] = 0;

		for (int i = 1; i<=x; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (c[j] <= i) 
				{
					dp[i]+= dp[i-c[j]] % 1000000007;
					dp[i]%= 1000000007;
				}
			}
			//cout<<dp[i]<<endl;
		}
		cout<<dp[x]%1000000007;
		cout<<endl;	
	}
}