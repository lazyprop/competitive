#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	int n;
	int den[5] = {1,5,10,25,50};
	while (cin>>n)
	{
		// code
		int dp[n+1][5];
		for (int i = 0; i<5; i++)
		{
			dp[0][i] = 1;
		}
		for (int i = 0; i<=n; i++)
		{
			dp[i][0] = 1;
		}
		for (int i = 1; i<5; i++)
		{
			for (int x = 1; x<=n; x++)
			{
				dp[x][i] = dp[x][i-1];
				if (x>=den[i])
				{
					dp[x][i]+= dp[x-den[i]][i];
				}
			}
		}
		if (dp[n][4] == 1)
		{
			cout<<"There is only 1 way to produce "<<
			n<<" cents change.\n";
		}
		else
		{
			cout<<"There are "<<dp[n][4]<<" ways to produce "<<
			n<<" cents change.\n";
		}
	}
}