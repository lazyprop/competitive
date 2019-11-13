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

	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		int a[n];
		vector<int> freq[n+1];

		for (int i= 0; i<n; i++)
		{
			cin>>a[i];
			freq[a[i]].push_back(i);
		}

		int ans = INT_MAX;
		for (int i = 1; i<=n; i++)
		{
			int x = freq[i].size();
			if (x< 2) continue;
			for (int j = 1; j<x; j++)
			{
				ans = min(ans,freq[i][j] - freq[i][j-1]+1);
			}
		}

		if (ans == INT_MAX) ans = -1;
		cout<<ans<<endl;
	}
}