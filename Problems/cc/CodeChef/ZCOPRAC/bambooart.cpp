#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin>>n;
	int a[n];
	for (int i = 0; i<n; i++) cin>>a[i];

	sort(a,a+n);
	
	int dp[n][n] = {};
	dp[0][0] = 1;
    int ans = 0;
	for (int i = 0; i<n; i++)
	{
		dp[i][i] = 1;
		for (int j = i+1; j<n; j++)
		{
			int diff = a[j] - a[i];
			dp[i][j] = 2;

			for (int k = i-1; k>=0; k--)
			{
				if (a[i] - a[k] == diff)
				{
					dp[i][j] = max(dp[i][j], dp[k][i]+1);
					break;
				}
			}
			ans = max(ans,dp[i][j]);
		}
	}

	cout<<ans<<endl;
}