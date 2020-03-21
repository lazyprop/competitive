#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m; cin>>n>>m;

	ll tot[n] = {}, l[n] = {}, r[n] = {}, best[n] = {};

	for (int i = 0; i<n; i++)
	{
		int len; cin>>len;

		ll besthere = 0;

		best[i] = LLONG_MIN;
		for (int j = 0; j<len; j++)
		{
			int x; cin>>x;

			tot[i]+= x;

			l[i] = max(l[i], tot[i]);
			r[i] = min(r[i], tot[i]);

			besthere+= x;
			best[i] = max(best[i], (ll) x);
			if (besthere < 0)
			{
				besthere = 0;
			}
			else best[i] = max(besthere, best[i]);
		}

		r[i] = tot[i] - r[i];
	}

	ll cur = 0, ans = LLONG_MIN;
	while (m--)
	{
		int x; cin>>x;
		x--;

		ans = max(ans, best[x]);

		if (cur)
		{
			ans = max(ans, cur + l[x]);
		}

		cur = max(r[x], cur + tot[x]);
		cur = max(cur, (ll) 0);

	}
	cout<<ans<<endl;
}