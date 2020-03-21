#include<bits/stdc++.h>
using namespace std;

const int maxn = 710;
int dp[maxn][maxn], seen[maxn][maxn];

int b[maxn], v[maxn];

int k; 

int f(int l, int r)
{
	if (seen[l][r]) return dp[l][r];
	if (l >= r) return 0;


	seen[l][r] = 1;

	dp[l][r] = 0;
	for (int i = l+1; i<=r; i++)
	{
		if (b[i] - b[l] == k)
		{
			dp[l][r] = max(dp[l][r], f(l+1, i-1) + f(i+1, r) + v[l] + v[i]);
		}	
	}
	dp[l][r] = max(dp[l][r], f(l+1,r));

	return dp[l][r];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	int n; cin>>n>>k;

	for (int i = 0; i<n; i++)
	{
		cin>>v[i];
	}
	for (int i = 0; i<n; i++)
	{
		cin>>b[i];
	}

	cout<<max(0,f(0,n-1))<<endl;
}