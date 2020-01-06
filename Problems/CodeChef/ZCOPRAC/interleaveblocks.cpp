#include<bits/stdc++.h>
using namespace std;

const int mod = pow(10,8) + 7;
const int maxn = 110;

int a[maxn][2];
int dp[maxn][maxn][maxn][2];

int f(int i, int j, int k, int prev)
{
	if (i == 0 and j == 0 and k == 0) return 1;
	if (k < 0) return 0;
	if (i == 0 and j == 0) return 0;

	if (dp[i][j][k][prev]) return dp[i][j][k][prev];

	if (i >= 0)
	{
		// take from first
		dp[i][j][k][prev] = 
	}
}

int main()
{
	ifstream cin("in.txt");

	int T; cin>>T;
	while (T--)
	{
		int n,m,block; cin>>n>>m>>block;
		for (int i = 1; i<=n; i++) cin>>a[i][0];
		for (int j = 1; j<=m; j++) cin>>a[j][1];

		a[n+1][0] = -1;
		a[m+1][1] = -1;

		int ans = f(n,m,block);
		ans%= mod;
		cout<<ans<<endl;
		memset(dp, 0, sizeof(dp));
	}
}