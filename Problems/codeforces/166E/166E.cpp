#include<iostream>
#include<vector>
#include<limits>
#include<math.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int dp[10000002][4];
int main()
{
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		int n; cin>>n;
		dp[1][0] = 0; dp[1][1] = 1; dp[1][2] = 1; dp[1][3] = 1;

		for (int i = 2; i<=n; i++)
		{
			for (int j = 0; j<4; j++)
			{
				for (int k = 0; k<4; k++)
				{
					if (k != j)
					{
						dp[i][j]+= dp[i-1][k];
						dp[i][j] = dp[i][j]%1000000007;
					}
				}
			}
		}
		cout<<dp[n][0]%1000000007 ;
		cout<<endl;	
	}
}