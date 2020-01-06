#include<bits/stdc++.h>
using namespace std;

const int maxn = 1505;
const long long inf = 1e15;

#define ll long long


ll pre[maxn][maxn];
ll dp[maxn][maxn];
int seen[maxn][maxn];
int n,m;

ll f(int i, int j)
{
	if (i > n) return 0;
	if (j <= 0 or j > m) return -inf;

	// cout<<i<<" "<<j<<endl;

	if (seen[i][j]) return dp[i][j];

	if (i%2)
	{
		dp[i][j] = max((ll) pre[i][j] + f(i+1, j-1), f(i, j+1));
	}
	else
	{
		dp[i][j] = max((ll) pre[i][j] + f(i+1, j+1), f(i, j-1));
	}

	seen[i][j] = 1;

	return dp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	cin>>n>>m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin>>pre[i][j];
			pre[i][j]+= pre[i][j-1];
		}
	}

	cout<<f(1,1)<<endl;
}