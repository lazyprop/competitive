#include<bits/stdc++.h>
using namespace std;

const int mod = pow(10,9) + 7;
int dp[2][5010];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	int n; cin>>n;

	dp[0][0] = 1;
	
	int tot = 1;
	
	char statement; cin>>statement;

	for (int x = 1; x<n; x++)
	{
		int totx = 0;

		int i = x%2;
		if (statement == 'f')
		{
			dp[i][0] = 0;
			for (int j = 1; j<n; j++)
			{
				dp[i][j] = dp[!i][j-1];
				
				totx+= dp[i][j];
				totx%=mod;
			}
		}
		else
		{
			int pre = 0;
			for (int j = 0; j<n; j++)
			{
				dp[i][j] = (tot - pre + mod) % mod;

				pre+= dp[!i][j];
				pre%= mod;

				totx+= dp[i][j];
				totx%= mod;
			}
		}

		if (x != n-1) cin>>statement;
		tot = totx;
	}

	cout<<tot<<endl;
}