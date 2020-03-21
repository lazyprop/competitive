#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = pow(10,5) + 5;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	int Q; cin>>Q;
	while (Q--)
	{
		int n; cin>>n;
		int a[n+1] = {};

		for (int i = 0; i < n; i++)
		{
			int x; cin>>x;
			a[x]++;
		}

		sort(a, a+n+1, greater<int>());

		ll ans = 0;
		int taken[n+1] = {};

		for (int i = 0; i < n; i++)
		{
			if (!a[i]) break;

			if (taken[a[i]])
			{
				int x = a[i];
				while (taken[x] and x)
				{
					x--;
				}
				taken[x] = 1;
				ans+= x;
			}
			else
			{
				ans+= a[i];
				taken[a[i]] = 1;
			}
		}

		cout<<ans<<endl;
	}
}