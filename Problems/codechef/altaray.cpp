#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		int a[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}

		int dp[n] = {};
		for (int x = 0; x<n; x++)
		{
			dp[x] = 1;
			
			int prev;
			if (a[x]<0) prev=-1;
			else prev=1;
			for (int i = x+1; i<n; i++)
			{
				int cur;
				if (a[i] < 0) cur=-1;
				else cur=1;
				if (cur == -prev) dp[x]++;
				else break;
				prev = cur;
			}
			for (int i = 1; i<dp[x]; i++)
			{
				dp[x+i] = dp[x] - i;
			}
			x+= dp[x]-1;
		}

		for (int i = 0; i<n; i++)
		{
			cout<<dp[i]<<" ";
		}
		cout<<endl;
	}
}