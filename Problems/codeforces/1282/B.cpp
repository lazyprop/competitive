#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	ifstream cin("in.txt");

	int T=1; cin>>T;
	// T=1;
	while (T--)
	{
		int n,p,k; cin>>n>>p>>k;
		ll a[n+2];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);

		pair<int, int> dp[n+1][3];
		dp[0][0] = make_pair(0,p);
		dp[0][1] = make_pair(0,p);
		dp[0][2] = make_pair(0,p);

		for (int i = 1; i<n; i++)
		{
			dp[i][0] = make_pair(0,INT_MAX);
			for (int j = 0; j<3; j++)
			{
				if (dp[i-1][j].first > dp[i][0].first)
				{
					dp[i][0] = dp[i][j];
				}
				if (dp[i-1][j].first == dp[i][0].first)
				{
					if (dp[i-1][j].second >  dp[i][0].second)
					{
						dp[i][0] = dp[i][j];
					}
				}
			}

			// case: take one
			dp[i][1].first = 0;
			if (dp[i-1][0].second >= a[i])
			{
				if (dp[i-1][0].first + 1 > dp[i][1].first)
				{
					dp[i][1] = make_pair(dp[i-1][0].first + 1, dp[i-1][0].second - a[i]);
				}
			}

			if (dp[i-1][1].second >= a[i])
			{
				if (dp[i-1][1].first + 1 > dp[i][1].first)
				{
					dp[i][1] = make_pair(dp[i-1][1].first + 1, dp[i-1][1].second - a[i]);
				}
			}

			if (dp[i-1][2].second >= a[i])
			{
				if (dp[i-1][2].first + 1 > dp[i][1].first)
				{
					dp[i][1] = make_pair(dp[i-1][2].first + 1, dp[i-1][2].second - a[i]);
				}
			}

			// case: take k
			if (i>=k)
			{
				dp[i][2].first = 0;
				if (dp[i-k][0].second >= a[i])
				{
					if (dp[i-k][0].first + k > dp[i][2].first)
					{
						dp[i][2] = make_pair(dp[i-k][0].first + k, dp[i-k][0].second - a[i]);
					}
				}

				if (dp[i-k][1].second >= a[i])
				{
					if (dp[i-k][1].first + k > dp[i][2].first)
					{
						dp[i][2] = make_pair(dp[i-k][1].first + k, dp[i-k][1].second - a[i]);
					}
				}

				if (dp[i-k][2].second >= a[i])
				{
					if (dp[i-k][2].first + k > dp[i][2].first)
					{
						dp[i][2] = make_pair(dp[i-k][2].first + k, dp[i-k][2].second - a[i]);
					}
				}
			}

			cout<<dp[i][0].first<<" "<<dp[i][1].first<<" "<<dp[i][2].first<<endl;
		}

		cout<<max(dp[n-1][0].first, max(dp[n-1][1].first, dp[n-1][2].first))<<endl;
	}
}