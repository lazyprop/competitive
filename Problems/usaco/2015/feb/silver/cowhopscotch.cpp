#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

const int MOD = 1000000007;
int main()
{
	ifstream cin("hopscotch.in");
	ofstream cout("hopscotch.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int r,c,k; cin>>r>>c>>k;
		
		int a[r][c];
		for (int i = 0; i<r; i++)
		{
			for (int j = 0; j<c; j++)
			{
				cin>>a[i][j];
			}
		}

		ll dp[r][c];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i<r; i++)
		{
			for (int j = 0; j<c; j++)
			{
				for (int k = i+1; k<r; k++)
				{
					for (int l=j+1; l<c; l++)
					{
						if (a[k][l] != a[i][j])
						{
							dp[k][l]+= dp[i][j];
							dp[k][l]%=MOD;
						}
					}
				}
			}
		}
		cout<<dp[r-1][c-1]<<endl;
	}
}