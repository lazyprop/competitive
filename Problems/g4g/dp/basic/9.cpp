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

	int T; cin>>T;
	while (T--)
	{
		int n,m; cin>>m;
		int a[m];
		for (int i = 0; i<m; i++)
		{
			cin>>a[i];
		}
		cin>>n;
		sort(a,a+m);

		int dp[n+1][m+1]={};
		
		for (int i = 0; i<m; i++)
		{
			dp[0][i] = 1;
			for (int x = 1; x<=n; x++)
			{
				if (i>0)
				{
					dp[x][i] = dp[x][i-1];
				}
				if (x>=a[i])
				{
					dp[x][i]+=dp[x-a[i]][i];
				}
			}
		}
		cout<<dp[n][m-1]<<endl;
	}	
}