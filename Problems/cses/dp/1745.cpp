#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;
	int a[n],sum=0;
	for (int i = 0; i<n; i++)
	{
		cin>>a[i];
		sum+= a[i];
	}
	sort(a,a+n);

	int dp[n+5][sum+5] = {};
	dp[0][a[0]] = 1;
	set<int> sol;
	sol.insert(a[0]);
	for (int i = 1; i<n; i++)
	{
		dp[i][a[i]] = 1;
		sol.insert(a[i]);
		for (int j = 1; j<=sum; j++)
		{
			if (dp[i-1][j]) dp[i][j]++;

			else if (j>a[i])
			{
				if (dp[i-1][j-a[i]])
				{
					dp[i][j]++;
					sol.insert(j);
				}
			}
		}
	}
	cout<<sol.size()<<endl;
	for (auto i: sol)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}