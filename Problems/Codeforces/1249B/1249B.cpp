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
			a[i]--;
		}

		int dp[n] = {};

		for (int i = 0; i<n; i++)
		{
			if (dp[i] == 0)
			{
				int count = 1, cur = i;
				vector<int> path;
				for (int j = 0; j<n; j++)
				{
					path.push_back(cur);
					if (a[cur] == i) break;
					cur = a[cur];
					count++;
				}
				for (int j = 0, x = path.size(); j<x;j++)
				{
					dp[path[j]] = count;
				}
			}
			cout<<dp[i]<<" ";
			
		}
		cout<<endl;
	}
}