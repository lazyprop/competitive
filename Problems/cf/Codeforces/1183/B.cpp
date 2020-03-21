#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	int Q; cin>>Q;
	while (Q--)
	{
		int n,k; cin>>n>>k;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
		}

		sort(a,a+n);

		if (a[0] + k < a[n-1] - k)
		{
			cout<<-1<<endl;
			continue;
		}

		int l = a[0], r = a[n-1] + k;
		int best = 1;

		while (l <= r)
		{
			int m = l + (r-l)/2;
			// cout<<m<<" "<<m - a[0]<<" "<<k<<endl;

			if (m - a[0] <= k and abs(a[n-1] - m) <= k)
			{
				l = m+1;
				best = m;
			}

			else if (m - a[0] <= k and abs(a[n-1] - m) > k)
			{
				l = m+1;
			}

			else
			{
				r = m-1;
			}
		}
		// cout<<endl;

		cout<<best<<endl;
	}
}