#include<bits/stdc++.h>
using namespace std;

const int maxn = 12;

#define ll int

ll dp[maxn][maxn][maxn];

ll f(int i, int a, int b)
{
	// cout<<i<<" "<<a<<" "<<b<<endl;
	if (i == -1)
	{
		return a > b;
	}

	if (dp[i][a][b] != -1) return dp[i][a][b];

	dp[i][a][b] = f(i-1, a, b) + f(i-1, a+1, b) + f(i-1, a, b+1);
	return dp[i][a][b];
}

int main()
{
	// ifstream cin("in.txt");

	int n; cin>>n;
	int x;
	for (int i = 0; i<n; i++) cin>>x;

	memset(dp, -1, sizeof(dp));

	cout<<f(n-1, 0, 0)<<endl;
}